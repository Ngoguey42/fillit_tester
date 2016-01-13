// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 17:00:13 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
** clang++ -O2 -std=c++14 main.cpp && time ./a.out 1 100 /bin/ls ls
** *
** av[1] pieces per test (0+)
** av[2] num tests (0+)
** av[3] binary 1
** av[4] binary 2
*/

#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <chrono>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <algorithm>
// #include <>

#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include "ThreadPool.h"
#define NUM_WORKERS 5
#define WORK_TIMEOUT 1s
using namespace std::literals;
extern char **environ;

class UnitTest
{
public:

	/* CONSTRUCTION ***************** */
	UnitTest(char const *bp, std::string const &av1)
		: binary_path(bp)
		, argv1(av1)
		, timeout{}, status{}, err{}, time{}, output{}
		{}


	UnitTest(UnitTest &&src)
		: binary_path(src.binary_path)
		, argv1(std::move(src.argv1))
		, timeout{}, status{}, err{}, time{}, output{}
		{}
	~UnitTest(){}

	UnitTest() = delete;
	UnitTest(UnitTest const &src) = delete;
	UnitTest					&operator=(UnitTest const &rhs) = delete;
	UnitTest					&operator=(UnitTest &&rhs) = delete;

	char const *binary_path;
	std::string argv1;

	bool timeout;
	int status[1];
	bool err;
	std::chrono::duration<double, std::milli> time;
	std::string output;

protected:
private:
};

class WorkerData
{
	/* CONSTRUCTION ***************** */
private:
	WorkerData(){}
public:
	~WorkerData(){}

	WorkerData(WorkerData const &src) = delete;
	WorkerData(WorkerData &&src) = delete;
	WorkerData					&operator=(WorkerData const &rhs) = delete;
	WorkerData					&operator=(WorkerData &&rhs) = delete;

	/* PUBLIC ATTRIBUTES ************ */
	int							pipe[2];

	/* STATIC FUNCTIONS ************* */
	static WorkerData &getWorkerData(std::thread::id id) {
		return *WorkerData::map[id];
	}
	static void initWorkerData(std::thread::id id) {
		WorkerData *const w = new WorkerData;
		int err;
		int flags;

		{
			std::unique_lock<std::mutex> lock(WorkerData::map_mutex);

			WorkerData::map.emplace(id, w);
		}
		err = ::pipe(w->pipe);
		assert(err == 0); /*pipe failed*/
		flags = ::fcntl(w->pipe[0], F_GETFL, 0);
		err = ::fcntl(w->pipe[0], F_SETFL, flags | O_NONBLOCK);;
		assert(err == 0); /*fcntl failed*/
		return ;
	}

protected:
private:
	/* STATIC ATTRIBUTES ************ */
	static std::unordered_map<std::thread::id, WorkerData*>	map;
	static std::mutex map_mutex;
};
std::unordered_map<std::thread::id, WorkerData*>		WorkerData::map; /*static*/
std::mutex WorkerData::map_mutex; /*static*/


static int work(UnitTest &t)
{
	WorkerData &w = WorkerData::getWorkerData(std::this_thread::get_id());
	pid_t pid;
	int err;
	int ret;
	char av0[::strlen(t.binary_path) + 1];
	char av1[t.argv1.size() + 1];
	auto start = std::chrono::high_resolution_clock::now();
	char buf[128];

	::strcpy(av0, t.binary_path);
	::strcpy(av1, t.argv1.c_str());
	start = std::chrono::high_resolution_clock::now();
	pid = ::fork();
	if (pid == 0) // Child process
	{
		err = ::close(w.pipe[0]);
		assert(err == 0); /*close failed*/
		err = ::dup2(w.pipe[1], 1);
		assert(err == 1); /*dup2 failed*/
		::execve(av0, (char *[]){av0, av1, NULL}, environ);
		assert(false); /*execve failed*/
	}
	assert(pid > 0); /*fork failed*/
	while (1) // Waiting child process with timeout
	{
		std::this_thread::yield();
		err = ::waitpid(pid, t.status, WNOHANG);
		if (err == 0)
		{
			t.time = std::chrono::high_resolution_clock::now() - start;
			if (t.time > WORK_TIMEOUT)
			{
				::kill(pid, SIGKILL);
				t.timeout = true;
			}
			continue ;
		}
		else if (err == pid)
			break ;
		else
			assert(false); /*waitpid failed*/
	}
	if (*t.status != 0)
		t.err = true;
	do // Retrieving child process output with nonblocking read
	{
		ret = ::read(w.pipe[0], buf, sizeof(buf));
		err = errno;
		t.output.append(buf, ret);
	} while (ret > 0);
	assert(ret == -1 && err == EAGAIN); /*read failed*/
	return 0;
}

void		run(std::vector<UnitTest> &tasks, char const *const av[])
{
	ThreadPool p(NUM_WORKERS);

	for (auto const &w : p.getWorkers())
		WorkerData::initWorkerData(w.get_id());
	for (UnitTest &t : tasks)
		p.enqueue(&work, std::ref(t));
	return ;
}


struct Piece
{
	char    val[4][5];
	unsigned int adjDiff(void) { /* used to disambiguate valid and invalid pieces */
		unsigned int    acc = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 3; x++)
				if (val[y][x] == '#' && val[y][x + 1] == '#')
					acc++;
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#' && val[y + 1][x] == '#')
					acc++;
		return acc;
	}
	unsigned int type(void) { /* used to disambiguate the 19 different shapes */
		int             pos = 0;
		unsigned int    h = 0;
		int             fx = -1;
		int             fy = -1;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				if (val[y][x] == '#')
				{
					if (fx < 0)
						fx = x, fy = y;
					else
					{
						h += (x - fx + 2) << 4 * pos++;
						h += (y - fy + 2) << 4 * pos++;
					}
				}
		return h;
	}
	unsigned int uid(void) const { /* used to disambiguate the 2^16 different grids */
		unsigned int h = 0;

		for (int y = 0; y < 4; y++)
			for (int x = 0; x < 4; x++)
				h = (h << 1) + (this->val[y][x] == '#' ? 1 : 0);
		return h;
	}
	void dump(void) {
		std::for_each(std::begin(val), std::end(val)
					  , [](char l[5]){std::cout << l << '\n';});
	}
	void dump(std::ofstream &os) const {
		for (auto const &l : val)
			os << l << '\n';
	}
};

typedef std::unordered_multimap<unsigned int, Piece> pmap_t;
typedef std::unordered_set<unsigned int> pset_t;

void        gen(Piece &p, pmap_t &pmap, pset_t &pset, int count, int istart)
{
	int     y;
	int     x;

	if (count < 4)
	{
		for (int i = istart; i < 16; i++)
		{
			y = i / 4;
			x = i % 4;
			p.val[y][x] = '#';
			gen(p, pmap, pset, count + 1, i + 1);
			p.val[y][x] = '.';
		}
	}
	else if (p.adjDiff() >= 3)
	{
		pmap.insert({p.type(), p});
		pset.insert(p.type());
	}
}


unsigned int    randType(pset_t &pset)
{
	int const   n = std::rand() % pset.size();
	int         i = 0;

	for (auto t : pset)
		if (i++ == n)
			return t;
	assert(false); /* should not be reached */
}

Piece         &randPiece(pmap_t &pmap, pset_t &pset)
{
	unsigned int const  t = randType(pset);
	unsigned int const  n = std::rand() % pmap.count(t);
	auto const          range = pmap.equal_range(t);
	unsigned int        i = 0;

	for (auto it = range.first; it != range.second; ++it)
		if (i++ == n)
			return it->second;
	assert(false); /* should not be reached */
}


std::string filename_of_pvec(std::vector<Piece> const &pvec)
{
	std::string ret("./map/");

	for (auto const &p : pvec)
	{
		ret.append(std::to_string(p.uid()));
		ret.append("_");
	}
	ret.append(".fillit");
	return ret;
}


std::vector<UnitTest> build_tasks(char const *const av[])
{
	std::vector<UnitTest> tasks;
	std::unordered_multimap<unsigned int, Piece> pmap;
	std::unordered_set<unsigned int> pset;
	std::vector<Piece> pvec;
	Piece p = {"....", "....", "....", "...."};
	int const pptest = std::atoi(av[1]);
	int const ntests = std::atoi(av[2]);
	std::string fname;
	std::ofstream f;

	assert(pptest >= 0); /* wrong av[1] */
	assert(ntests >= 0); /* wrong av[2] */
	gen(p, pmap, pset, 0, 0);
	::system("rm -rf map log; mkdir -p log map");
	for (int i = 0; i < ntests; i++)
	{
		pvec.clear();
		for (int j = 0; j < pptest; j++)
			pvec.push_back(randPiece(pmap, pset));
		fname = filename_of_pvec(pvec);
		f.open(fname, std::ios_base::out | std::ios_base::trunc);
		assert(f.good()); /* file creation failed */
		for (auto const &p : pvec)
		{
			p.dump(f);
			f << '\n';
		}
		assert(f.good()); /* file write failed */
		f.close();
		assert(f.good()); /* file close failed */
		tasks.push_back(std::move(UnitTest("/bin/ls", fname)));
	}
	return tasks;
}

int							main(int ac, char *av[])
{
	assert(ac == 5);

	std::vector<UnitTest> tasks = build_tasks(av);

	run(tasks, av);
	std::cout << tasks[0].output << std::endl;
	std::cout << tasks[0].err << std::endl;
	std::cout << tasks[0].timeout << std::endl;
	std::cout << "waited for "
			  << std::chrono::duration_cast<std::chrono::microseconds>(tasks[0].time).count()
			  << " microseconds\n";(void)ac;
	return (0);
}
