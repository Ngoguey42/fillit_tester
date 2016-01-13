// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/13 11:32:11 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/13 12:18:04 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#include <vector>
// #include <>
#include <utility>
#include <unordered_map>
#include <iostream>
#include "ThreadPool.h"

#define NUM_WORKERS 4

class Task
{
public:

	/* CONSTRUCTION ***************** */
	Task(){}
	~Task(){}

	// Task() = delete;
	Task(Task const &src) = delete;
	Task(Task &&src) = delete;
	Task					&operator=(Task const &rhs) = delete;
	Task					&operator=(Task &&rhs) = delete;

protected:
private:
};

class Worker
{

	/* CONSTRUCTION ***************** */
private:
	Worker(){}
public:
	~Worker(){}

	// Worker() = delete;
	Worker(Worker const &src) = delete;
	Worker(Worker &&src) = delete;
	Worker					&operator=(Worker const &rhs) = delete;
	Worker					&operator=(Worker &&rhs) = delete;

	static Worker			&getWorker(std::thread::id id) {
		auto	it = Worker::map.find(id);

		if (it == Worker::map.end())
		{
			Worker::map.emplace(std::make_pair(id, Worker()));
			return Worker::map.find(id)->second;
		}
		// else
			return it->second;
		}
protected:
private:
	static std::unordered_map<std::thread::id, Worker>	map;
};


int		work(Task &t)
{
	std::cout << "hello\n";
	return 0;
}


void		run()
{
	ThreadPool				p(NUM_WORKERS);
	std::vector<Task>		tasks(15);

	for (Task &t : tasks)
	{
		p.enqueue(&work, std::ref(t));


	}
	return ;
}


int			main(void)
{
	run();
	return (0);
}
