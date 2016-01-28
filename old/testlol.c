/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 19:03:57 by ngoguey           #+#    #+#             */
/*   Updated: 2016/01/28 19:50:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h> //TO REMOVE LATER

#define qprintf(...) printf(__VA_ARGS__); fflush(stdout)


typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct
{
	int			sid;	/* Shape ID */
	uintmax_t	mask;
	__uint128_t	mask128;
	int			w;
	int			h;
	t_vec2i		dt[4];
	t_vec2i		finalpos;
	char		character;
}				t_piece;

#define MAP_W 13

typedef char		t_map[MAP_W][MAP_W];

typedef struct
{
	t_piece		pcs[27];
	int			lastpid;
}				t_ppool;








/*
** Slave functions for fallback algorithm
*/
static void		load_marks(t_map m, char *marks[const 4]
						   , t_vec2i const c, t_vec2i const dt[const 4])
{
	marks[0] = &m[c.y + dt[0].y][c.x + dt[0].x];
	marks[1] = &m[c.y + dt[1].y][c.x + dt[1].x];
	marks[2] = &m[c.y + dt[2].y][c.x + dt[2].x];
	marks[3] = &m[c.y + dt[3].y][c.x + dt[3].x];
	return ;
}

static void		apply_marks(char *const marks[const 4], char const c)
{
	*marks[0] = c;
	*marks[1] = c;
	*marks[2] = c;
	*marks[3] = c;
	return ;
}

static void		increment_marks(char *marks[const 4])
{
	marks[0]++;
	marks[1]++;
	marks[2]++;
	marks[3]++;
	return ;
}

static bool		check_marks(char *const marks[const 4])
{
	return (*marks[0] == '.' && *marks[1] == '.'
			&& *marks[2] == '.' && *marks[3] == '.');
}

static void		unapply_marks(char *const marks[const 4])
{
	*marks[0] = '.';
	*marks[1] = '.';
	*marks[2] = '.';
	*marks[3] = '.';
	return ;
}







/*
** Fallback algorithm (char*) when w > sizeof(uintmax_t)
** Writes result to t_map
*/

static bool		loop_coords(t_map m, t_ppool const *const restrict pool
							, int const w
							, int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	char					*marks[4];

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		load_marks(m, marks, c, p->dt);
		while (c.x <= w - p->w)
		{
			if (check_marks(marks))
			{
				apply_marks(marks, p->character);
				if (pid == pool->lastpid || loop_coords(m, pool, w, pid + 1))
					return true;
				unapply_marks(marks);
			}
			increment_marks(marks);
			c.x++;
		}
		c.y++;
	}
	return false;
}

/*
** Main algorithm (bitwise) when w <= sizeof(uintmax_t)
** Writes result to pool[]->finalpos
** *
** Without -O2 'static' does nothing
** With -O2 'static' speeds things up by 14%
*/

static bool		loop_coords2(uintmax_t const m, t_ppool *const pool
							 , int const w
							 , int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	uintmax_t				pmask;

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask << (8 * c.y);
		while (c.x <= w - p->w)
		{
			if ((pmask & m) == 0)
			{
				if (pid == pool->lastpid || loop_coords2(m | pmask, pool, w, pid + 1))
				{
					pool->pcs[pid].finalpos = c;
					return true;
				}
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return false;
}

static bool		loop_coords3(__uint128_t const m, t_ppool *const pool
							 , int const w
							 , int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	__uint128_t				pmask;

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask128 << (11 * c.y);
		while (c.x <= w - p->w)
		{
			if ((pmask & m) == 0)
			{
				if (pid == pool->lastpid || loop_coords3(m | pmask, pool, w, pid + 1))
				{
					pool->pcs[pid].finalpos = c;
					return true;
				}
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return false;
}



/*
** Math function
*/
int			ft_sqrtfloor(int v)
{
	int		i;

	i = v;
	while (i * i > v)
		i--;
	return i;
}

int			ft_sqrtceil(int v)
{
	int		i;

	i = 0;
	while (i * i < v)
		i++;
	return i;
}

/*
** Loads loop_coords2's result to t_map
*/
void		write_map_solve2(t_map m, t_ppool *const pool)
{
	int				i;
	t_piece const	*p;
	int const		max = pool->lastpid + 1;

	for (i = 0 ; i < max; i++)
	{
		p = pool->pcs + i;
		m[p->dt[0].y + p->finalpos.y][p->dt[0].x + p->finalpos.x] = p->character;
		m[p->dt[1].y + p->finalpos.y][p->dt[1].x + p->finalpos.x] = p->character;
		m[p->dt[2].y + p->finalpos.y][p->dt[2].x + p->finalpos.x] = p->character;
		m[p->dt[3].y + p->finalpos.y][p->dt[3].x + p->finalpos.x] = p->character;
	}
	return ;
}

bool g_use_bitwise = true;

/*
** Tries succesive map size picking the right algorithm
*/
void		loop_sizes(t_map m, t_ppool *const pool)
{
	int			w;

	w = ft_sqrtceil(pool->lastpid * 4 + 4);
	while (1)
	{
		/* if (w <= 8 && g_use_bitwise) */
		/* { */
		/* 	qprintf("%s with w=%d loop_coords2\n", __FUNCTION__, w); */
		/* 	if (loop_coords2(0, pool, w, 0)) */
		/* 	{ */
		/* 		g_use_bitwise = false; */
		/* 		write_map_solve2(m, pool); */
		/* 		break; */
		/* 	} */
		/* } */

		if (w <= 11 && g_use_bitwise)
		{
			qprintf("%s with w=%d loop_coords3\n", __FUNCTION__, w);
			if (loop_coords3(0, pool, w, 0))
			{
				g_use_bitwise = false;
				write_map_solve2(m, pool);
				break;
			}
		}
		else
		{
			qprintf("%s with w=%d loop_coords\n", __FUNCTION__, w);
			if (loop_coords(m, pool, w, 0))
				break;
		}
		w++;
	}
	return ;
}

/*
** Builds t_map and prints result
*/
void		solver(t_ppool *pool)
{
	char		m[MAP_W][MAP_W];

	memset(m, '.', sizeof(m));

	loop_sizes(m, pool);


	int x, y;
	for (y = 0; y < MAP_W; y++)
	{
		for (x = 0; x < MAP_W; x++)
		{
			qprintf("%c ", m[y][x]);
		}
		qprintf("\n");
	}
	return ;
}

t_piece const pcs[] = {
    {0, 0x10302, 0x401802, 2, 3, {{1, 0},{0, 1},{1, 1},{0, 2}}},
	{1, 0x702, 0x3802, 3, 2, {{1, 0},{0, 1},{1, 1},{2, 1}}},
	{2, 0x30202, 0xc01002, 2, 3, {{1, 0},{1, 1},{0, 2},{1, 2}}},
	{3, 0x20302, 0x801802, 2, 3, {{1, 0},{0, 1},{1, 1},{1, 2}}},
	{4, 0x306, 0x1806, 3, 2, {{1, 0},{2, 0},{0, 1},{1, 1}}},
	{5, 0x10301, 0x401801, 2, 3, {{0, 0},{0, 1},{1, 1},{0, 2}}},
	{6, 0x207, 0x1007, 3, 2, {{0, 0},{1, 0},{2, 0},{1, 1}}},
	{7, 0x701, 0x3801, 3, 2, {{0, 0},{0, 1},{1, 1},{2, 1}}},
	{8, 0x603, 0x3003, 3, 2, {{0, 0},{1, 0},{1, 1},{2, 1}}},
	{9, 0x1010101, 0x200400801, 1, 4, {{0, 0},{0, 1},{0, 2},{0, 3}}},
	{10, 0x10103, 0x400803, 2, 3, {{0, 0},{1, 0},{0, 1},{0, 2}}},
	{11, 0x407, 0x2007, 3, 2, {{0, 0},{1, 0},{2, 0},{2, 1}}},
	{12, 0x30101, 0xc00801, 2, 3, {{0, 0},{0, 1},{0, 2},{1, 2}}},
	{13, 0x303, 0x1803, 2, 2, {{0, 0},{1, 0},{0, 1},{1, 1}}},
	{14, 0x20203, 0x801003, 2, 3, {{0, 0},{1, 0},{1, 1},{1, 2}}},
	{15, 0x107, 0x807, 3, 2, {{0, 0},{1, 0},{2, 0},{0, 1}}},
	{16, 0x704, 0x3804, 3, 2, {{2, 0},{0, 1},{1, 1},{2, 1}}},
	{17, 0x20301, 0x801801, 2, 3, {{0, 0},{0, 1},{1, 1},{1, 2}}},
	{18, 0xf, 0xf, 4, 1, {{0, 0},{1, 0},{2, 0},{3, 0}}},
};

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/*
  3 4.000000
  4 4.000000
  5 5.000000
  6 5.000000
  7 6.000000
  8 6.000000
  9 6.000000
  10 7.000000		EASY
  11 7.000000
  12 7.000000		HARD
  13 8.000000		EASY
  14 8.000000
  15 8.000000
  16 8.000000		HARD
  17 9.000000		EASY
  18 9.000000
  19 9.000000
  20 9.000000		HARD
  21 10.000000	EASY
  22 10.000000
  23 10.000000
  24 10.000000
  25 10.000000	HARD
  26 11.000000	EASY
*/

int							main(void)
{
	t_ppool		pool;
	int			i;
	int const	max = 23;

	/* srand(time(0)); */
	srand(1);
	bzero(&pool, sizeof(pool)); //debug

	for (i = 0; i < max; i++)
	{
		pool.pcs[i] = pcs[rand() % sizeof(pcs) / sizeof(*pcs)];
	}
	pool.lastpid = max - 1;

	for (i = 'A'; i <= 'Z'; i++)
		pool.pcs[i - 'A'].character = i;

	clock_t p1;

	p1 = clock();
	solver(&pool);
	printf("%.6f\n", ((double)(clock() - p1)) / (double)CLOCKS_PER_SEC);

	p1 = clock();
	solver(&pool);
	printf("%.6f\n", ((double)(clock() - p1)) / (double)CLOCKS_PER_SEC);
	return (0);
}
