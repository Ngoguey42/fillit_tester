// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 14:44:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <vector>
#include <string.h>
// #include <>
#include <utility>
#include <assert.h>
#include <unordered_map>
#include <iostream>
#include "ThreadPool.h"

#include <unistd.h>

#define NUM_WORKERS 5
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

		WorkerData::map.emplace(id, w);
		err = ::pipe(w->pipe);
		assert(err == 0); /*pipe failed*/
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
	char av0[::strlen(t.binary_path) + 1];
	char av1[t.argv1.size() + 1];

	::strcpy(av0, t.binary_path);
	::strcpy(av1, t.argv1.c_str());
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
	err = ::waitpid(pid, t.status, 0);
	assert(err == pid); /*waitpid failed*/
	if (*t.status != 0)
		t.err = true;
	return 0;
}

void		run(char const *const av[])
{
	ThreadPool p(NUM_WORKERS);
	std::vector<UnitTest> tasks(150);

	for (auto const &w : p.getWorkers())
		WorkerData::initWorkerData(w.get_id());
	for (UnitTest &t : tasks)
	{
		p.enqueue(&work, std::ref(t));


	}
	return ;
}


int							main(int ac, char *av[])
{
	assert(ac == 3);
	run(av);
	(void)ac;
	return (0);
}
