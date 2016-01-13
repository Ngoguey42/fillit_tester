
#include "tester.hpp"

using namespace std::chrono;

#define MSTOI(T) duration_cast<milliseconds>((T)).count()

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
	f << "ran for: " << MSTOI(t.time) << "ms\n";
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
	f << "ran for: " << MSTOI(ta.time) << "ms\n";
	f << "===================================================\n";
	f << ta.output;
	f << "===================================================\n";
	f << tb.binary_path << " output:\n";
	f << "ran for: " << MSTOI(tb.time) << "ms\n";
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
				report_diff(tasks[i], tasks[i + 1]);
		}
	}
	std::cout
		<< std::atoi(av[2]) << " map(s) of size "
		<< std::atoi(av[1]) << " generated in ./map" << std::endl;
	std::cout
		<< "WORK_TIMEOUT set to " << MSTOI(WORK_TIMEOUT) << "ms ; "
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
			<< MSTOI(durs[i]) << "ms total time" << std::endl;
	}
	std::cout << std::endl;
	std::cout << diffs << " diffs" << std::endl;
	std::cout << std::endl;
	std::cout << "See ./log directory for fatal errors or diffs details" << std::endl;
	std::cout << "(a maximum of 5 files each are created in ./log)" << std::endl;
	return ;
}
