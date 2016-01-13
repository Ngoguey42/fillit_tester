// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 15:19:03 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
#include <chrono>

// #include <>

#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>

#include "ThreadPool.h"
#define NUM_WORKERS 5
#define WORK_TIMEOUT 10s
using namespace std::literals;
extern char **environ;

class UnitTest
{
public:

	/* CONSTRUCTION ***************** */
	UnitTest()
		: binary_path("/bin/ls")
		, argv1("-l")
		{


		}
	~UnitTest(){}

	// UnitTest() = delete;
	UnitTest(UnitTest const &src) = delete;
	UnitTest(UnitTest &&src) = delete;
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

		WorkerData::map.emplace(id, w);
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
	if (pid == 0)
	{
		err = ::close(w.pipe[0]);
		assert(err == 0); /*close failed*/
		err = ::dup2(w.pipe[1], 1);
		assert(err == 1); /*dup2 failed*/
		::execve(av0, (char *[]){av0, av1, NULL}, environ);
		assert(false); /*execve failed*/
	}
	assert(pid > 0); /*fork failed*/
	while (1)
	{
		std::this_thread::yield();
		err = ::waitpid(pid, t.status, WNOHANG);
		if (err == 0)
		{
			t.time = std::chrono::high_resolution_clock::now() - start;
			if (t.time > WORK_TIMEOUT)
			{
				t.err = true;
				t.timeout = true;
				break ;
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
	do
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

int							main(int ac, char *av[])
{
	std::vector<UnitTest> tasks(1000);

	assert(ac == 3);
	run(tasks, av);
	std::cout << tasks[0].output << std::endl;
	std::cout << tasks[0].err << std::endl;
	std::cout << tasks[0].timeout << std::endl;
	std::cout << "waited for "
			  << std::chrono::duration_cast<std::chrono::microseconds>(tasks[0].time).count()
			  << " microseconds\n";(void)ac;
	return (0);
}
