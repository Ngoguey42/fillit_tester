// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 19:27:35 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

/*
** clang++ -O2 -std=c++14 main.cpp && time ./a.out 3 1000 ./fillita ./fillitb
** *
**   The preceding command:
** 1. compiles the tester
** 2. removes ./map and ./log directories
** 3. generates 1000 random .fillit files containing 3 pieces in ./map
** 4. runs in parallel the two given binaries over those maps
** 5. computes a report, and logs errors in ./log
** *
** *
** av[1] pieces per test (0+)
** av[2] num tests (1+)
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
#define NUM_WORKERS 4
#define WORK_TIMEOUT 100ms
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
		assert(false); /*execve failed, av[3] or av[4] must be wrong*/
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
	if (WIFSIGNALED(*t.status) && !t.timeout)
	{
		std::cerr << *t.status << std::endl;
		t.err = true;
	}
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
	unsigned int uid(void) const { /* used to disambiguate the 2^(4*4) different grids */
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
	if (ret.size() > 200)
	{
		ret.erase(200);
		ret.append("...");
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
	assert(ntests > 0); /* wrong av[2] */
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
			if (&p != &*pvec.begin()) /* lol line !! */
				f << '\n';
			p.dump(f);
		}
		assert(f.good()); /* file write failed */
		f.close();
		assert(f.good()); /* file close failed */
		tasks.push_back(std::move(UnitTest(av[3], fname)));
		tasks.push_back(std::move(UnitTest(av[4], fname)));
	}
	return tasks;
}

std::string escape(std::string s)
{
	std::string::iterator it;

	while (1)
	{
		auto it = s.find('/');

		if (it == std::string::npos)
			break ;
		s[it] = '_';
	}
	while (1)
	{
		auto it = s.find(' ');

		if (it == std::string::npos)
			break ;
		s[it] = '_';
	}

	return s;
}

void report_crash(UnitTest const &t)
{
	std::ofstream f;
	char const *crashname = strsignal(WTERMSIG(*t.status));
	std::string const fname = std::string("./log/CRASH_")
		+ escape(crashname) + "_"
		+ escape(t.binary_path) + ".txt";

	f.open(fname, std::ios_base::out | std::ios_base::trunc);
	f << t.binary_path;
	f << '\n';
	f << crashname;
	f << '\n';
	f << "over: \"" << t.argv1 << "\"";
	f << '\n';
	f << "ran for: " << std::chrono::duration_cast<std::chrono::milliseconds>(t.time).count() << "ms";
	f << '\n';
	f.close();
	// TODO: output diff at the end of the file
	return ;
}

void report_diff(UnitTest const &ta, UnitTest const &tb)
{
	std::ofstream f;
	// char const *crashname = strsignal(WTERMSIG(*t.status));
	std::string const fname = std::string("./log/DIFF_")
		+ escape(ta.argv1) + ".txt";

	f.open(fname, std::ios_base::out | std::ios_base::trunc);
	// f << t.binary_path;
	// f << '\n';
	// f << crashname;
	// f << '\n';
	f << "over: \"" << ta.argv1 << "\"";
	f << '\n';
	f << "===================================================\n";
	f << ta.binary_path << " output:\n";
	f << "ran for: " << std::chrono::duration_cast<std::chrono::milliseconds>(ta.time).count() << "ms\n";
	f << "===================================================\n";
	f << ta.output;
	f << "===================================================\n";
	f << tb.binary_path << " output:\n";
	f << "ran for: " << std::chrono::duration_cast<std::chrono::milliseconds>(tb.time).count() << "ms\n";
	f << "===================================================\n";
	f << tb.output;
	f << "===================================================\n";
	// f << '\n';
	f.close();
	return ;
}

void report(std::vector<UnitTest> const &tasks, char const *const av[])
{
	std::chrono::duration<double, std::milli> durs[2] = {0ms, 0ms};
	int fterrs[2] = {0, 0};
	int errs[2] = {0, 0};
	int to[2] = {0, 0};
	int diffs = 0;

	for(int i = 0; i < tasks.size(); i += 2)
	{
		durs[0] += tasks[i].time;
		durs[1] += tasks[i + 1].time;
		fterrs[0] += (int)tasks[i].err;
		fterrs[1] += (int)tasks[i + 1].err;
		to[0] += (int)tasks[i].timeout;
		to[1] += (int)tasks[i + 1].timeout;
		if (tasks[i].output == "error\n")
			errs[0]++;
		if (tasks[i + 1].output == "error\n")
			errs[1]++;
		if (tasks[i].err && errs[0] <= 5)
			report_crash(tasks[i]);
		if (tasks[i + 1].err && errs[1] <= 5)
			report_crash(tasks[i + 1]);
		if (tasks[i].output != tasks[i + 1].output)
		{
			diffs++;
			if (diffs <= 5 && tasks[i].err == false && tasks[i + 1].err == false)
			{
				report_diff(tasks[i], tasks[i + 1]);
			}
		}
	}
	std::cout
		<< std::atoi(av[2]) << " map(s) of size "
		<< std::atoi(av[1]) << " generated in ./map"
		<< std::endl;
	std::cout
		<< "WORK_TIMEOUT set to " << std::chrono::duration_cast<std::chrono::milliseconds>(WORK_TIMEOUT).count()
		<< "ms ; "
		<< NUM_WORKERS << " programs running in parallel"
		<< std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout
			<< "Player #" << i << "(" << tasks[i].binary_path << ")"
			<< std::endl;
		std::cout
			<< fterrs[i] << " crash(s); " << std::endl
			<< errs[i] << " \"error\\n\" output(s); " << std::endl
			<< to[i] << " time out(s); "
			<< std::chrono::duration_cast<std::chrono::milliseconds>(durs[i]).count() << "ms total time"
			<< std::endl;
	}
	std::cout << std::endl;
	std::cout << diffs << " diffs" << std::endl;
	std::cout << std::endl;
	std::cout << "See ./log directory for fatal errors or diffs details" << std::endl;
	std::cout << "(a maximum of 5 files each are created in ./log)" << std::endl;
	return ;
}


int							main(int ac, char *av[])
{
	std::cout << "Hello World";
	std::cout.flush();
	assert(ac == 5); /* wrong number of arguments to program */
	std::srand(time(0));

	std::vector<UnitTest> tasks = build_tasks(av);

	run(tasks, av);
	std::cout << "\r";
	report(tasks, av);
	return (0); // tmp
	for (auto const &t : tasks)
	{
		std::cout << t.binary_path << " " << t.argv1
				  << " err:" << t.err
				  << " timeout:" << t.timeout
				  << " duration:" << std::chrono::duration_cast<std::chrono::milliseconds>(t.time).count()
				  << "ms "
				  << std::endl;
		// ::system((std::string("cat ") + t.argv1).c_str());
		std::cout << "RESULT:" << std::endl;
		std::cout << t.output << std::endl;
		std::cout << "==========================================" << std::endl;
	}
	return (0);
}
