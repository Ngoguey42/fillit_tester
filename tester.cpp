// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tester.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/10 12:27:41 by ngoguey           #+#    #+#             //
//   Updated: 2015/12/10 15:21:48 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// // // Uncomment one of those 3
// #define OUTPUT_MAP_TO_SDTOUT		// ./a.out SIZE
#define TEST1_BINARY				// ./a.out SIZE BINARY
// #define TEST2_BINARY				// ./a.out SIZE BINARY1 BINARY2
// // // Uncomment one of those 3

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <assert.h>
#include <unistd.h>

struct piece_t
{
	char	val[4][5];
	unsigned int	adjDiff(void) {
		unsigned int	acc = 0;

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
	void			dump(void) {
		// std::cout << (void*)(size_t)this->type() << std::endl;
		std::for_each(std::begin(val), std::end(val)
					  , [](char l[5]){std::cout << l << '\n';});
	}
	unsigned int				type(void)
		{
			int				pos = 0;
			unsigned int	h = 0;
			int				fx = -1;
			int				fy = -1;

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
};

std::unordered_multimap<unsigned int, piece_t>	map;
std::unordered_set<unsigned int>				set;

void		gen(piece_t &p, int count, int istart)
{
	int		y;
	int		x;

	if (count < 4)
	{
		for (int i = istart; i < 16; i++)
		{
			y = i / 4;
			x = i % 4;
			p.val[y][x] = '#';
			gen(p, count + 1, i + 1);
			p.val[y][x] = '.';
		}
	}
	else if (p.adjDiff() >= 3)
	{
		map.insert({p.type(), p});
		set.insert(p.type());
	}
}

unsigned int	randType()
{
	int const	n = std::rand() % set.size();
	int			i = 0;

	for (auto t : set)
		if (i++ == n)
			return t;
	assert(false);
}

piece_t			&randPiece()
{
	unsigned int const	t = randType();
	unsigned int const	n = std::rand() % map.count(t);
	auto const			range = map.equal_range(t);
	unsigned int		i = 0;

	for (auto it = range.first; it != range.second; ++it)
	{
		if (i++ == n)
			return it->second;
	}
	assert(false);
}

std::vector<piece_t>	genPieces(int count)
{
	std::vector<piece_t>	v;

	while (count-- > 0)
		v.push_back(randPiece());
	return v;
}

void	test(int count)
{
	for (auto &elt : genPieces(count))
	{
		elt.dump();
		std::cout << std::endl;
	}
}

void	test(int count, std::string const bin)
{
	int			pipe[2];
	int			pid;
	int			err;
	int			saveout;
	auto		vec = genPieces(count);

	err = ::pipe(pipe);
	assert(err == 0);
	std::cout << "\033[31m**********************" << std::endl;
	test(count);
	std::cout << "**********************\033[0m" << std::endl;
	pid = ::fork();
	if (pid == 0)
	{
		saveout = ::dup(1);
		::dup2(pipe[1], 1);
		test(count);
		::close(1);
		::dup2(saveout, 1);

		::dup2(pipe[0], 0);
		::execve(bin.c_str(), (char *[]){ NULL }, (char *[]){ NULL });
		std::cerr << "Could not run " << bin << std::endl;
		return ;
	}
	assert(pid > 0);
}

void	test(int count, std::string const bin1, std::string const bin2)
{

}

int							main(int ac, char *av[])
{
	piece_t					p = {"....", "....", "....", "...."};

	std::srand(std::clock());
	gen(p, 0, 0);
#if defined(OUTPUT_MAP_TO_SDTOUT)
	assert(ac == 2);
	test(std::atoi(av[1]));
#elif defined(TEST1_BINARY)
	assert(ac == 3);
	test(std::atoi(av[1]), av[2]);
#elif defined(TEST2_BINARY)
	assert(ac == 4);
	test(std::atoi(av[1]), av[2], av[3]);
#endif
	return (0);
}
