// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   report.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/01/14 11:38:58 by ngoguey           #+#    #+#             //
//   Updated: 2016/01/14 11:53:59 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "tester.hpp"

using namespace std::chrono;

#define STRINGIFY(...) static_cast<std::ostringstream&>(std::ostringstream{}.flush() << __VA_ARGS__).str()

template<class T>
static std::string durToStr(T dur)
{
	double d;

	if (dur >= 1s)
	{
		d = duration_cast<milliseconds>(dur).count();
		return STRINGIFY(d / 1000.) + "s";
	}
	else if (dur >= 1ms)
	{
		d = duration_cast<microseconds>(dur).count();
		return STRINGIFY(d / 1000.) + "ms";
	}
	else
	{
		d = duration_cast<nanoseconds>(dur).count();
		return STRINGIFY(d / 1000.) + "us";
	}
}

static std::string escape(std::string s)
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

static void report_crash(UnitTest const &t)
{
	std::ofstream f;
	char const *crashname = strsignal(WTERMSIG(*t.status));
	std::string const fname = std::string("./log/CRASH_")
		+ escape(crashname) + "_"
		+ escape(t.binary_path) + ".txt";

	f.open(fname, std::ios_base::out | std::ios_base::trunc);
	f << t.binary_path << '\n';
	f << crashname << '\n';
	f << "over: \"" << t.argv1 << "\"\n";
	f << "ran for: " << durToStr(t.duration) << "\n";
	f.close();
	return ;
}

static void report_diff(UnitTest const &ta, UnitTest const &tb)
{
	std::ofstream f;
	std::string const fname = std::string("./log/DIFF_")
		+ escape(ta.argv1) + ".txt";

	f.open(fname, std::ios_base::out | std::ios_base::trunc);
	f << "over: \"" << ta.argv1 << "\"\n";
	f << "===================================================\n";
	f << ta.binary_path << " output:\n";
	f << "ran for: " << durToStr(ta.duration) << "\n";
	f << "===================================================\n";
	f << ta.output;
	f << "===================================================\n";
	f << tb.binary_path << " output:\n";
	f << "ran for: " << durToStr(tb.duration) << "\n";
	f << "===================================================\n";
	f << tb.output;
	f << "===================================================\n";
	// TODO: output diff at the end of the file
	f.close();
	return ;
}

void report(std::vector<UnitTest> const &tasks, char const *const av[])
{
	duration<double, std::milli> durs[2] = {0ms, 0ms};
	int fterrs[2] = {0, 0};
	int errs[2] = {0, 0};
	int to[2] = {0, 0};
	int diffs = 0;

	for(int i = 0; i < tasks.size(); i += 2)
	{
		durs[0] += tasks[i].duration;
		durs[1] += tasks[i + 1].duration;
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
				report_diff(tasks[i], tasks[i + 1]);
		}
	}
	std::cout
		<< std::atoi(av[2]) << " map(s) of size "
		<< std::atoi(av[1]) << " generated in ./map" << std::endl;
	std::cout
		<< "WORK_TIMEOUT set to " << durToStr(WORK_TIMEOUT) << " ; "
		<< NUM_WORKERS << " programs running in parallel" << std::endl;
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
			<< durToStr(durs[i]) << " total time" << std::endl;
	}
	std::cout << std::endl;
	std::cout << diffs << " diffs" << std::endl;
	std::cout << std::endl;
	std::cout << "See ./log directory for fatal errors or diffs details" << std::endl;
	std::cout << "(a maximum of 5 files each are created in ./log)" << std::endl;
	return ;
}
