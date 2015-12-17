/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	*/
/*	testlol.c											:+:		:+:	:+:	*/
/*													+:+ +:+		+:+	*/
/*	By: ngoguey <ngoguey@student.42.fr>			+#+	+:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2015/12/10 17:22:22 by ngoguey			#+#	#+#			*/
/*   Updated: 2015/12/17 13:03:07 by ngoguey          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
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
	int			w;
	int			h;
	t_vec2i		dt[4];
	char		character;
}				t_piece;

#define MAP_W 128

typedef char		t_map[MAP_W][MAP_W];

typedef struct
{
	t_piece		pcs[27];
	int			lastpid;
}				t_ppool;









void		load_marks(t_map m, char *marks[const 4]
					   , t_vec2i const c, t_vec2i const dt[const 4])
{
	marks[0] = &m[c.y + dt[0].y][c.x + dt[0].x];
	marks[1] = &m[c.y + dt[1].y][c.x + dt[1].x];
	marks[2] = &m[c.y + dt[2].y][c.x + dt[2].x];
	marks[3] = &m[c.y + dt[3].y][c.x + dt[3].x];
	return ;
}

void		apply_marks(char *const marks[const 4], char const c)
{
	*marks[0] = c;
	*marks[1] = c;
	*marks[2] = c;
	*marks[3] = c;
	return ;
}

void		increment_marks(char *marks[const 4])
{
	marks[0]++;
	marks[1]++;
	marks[2]++;
	marks[3]++;
	return ;
}

bool		check_marks(char *const marks[const 4])
{
	return (*marks[0] == '.' && *marks[1] == '.'
			&& *marks[2] == '.' && *marks[3] == '.');
}

void		unapply_marks(char *const marks[const 4])
{
	*marks[0] = '.';
	*marks[1] = '.';
	*marks[2] = '.';
	*marks[3] = '.';
	return ;
}






bool		loop_coords(t_map m, t_ppool const *const pool
						, int const w
						, int const pid)
{
	t_vec2i					c;
	char					*marks[4];
	t_piece const *const	p = pool->pcs + pid;

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

void		loop_sizes(t_map m, t_ppool *const pool)
{
	int		w;

	w = 2;
	while (1)
	{
		qprintf("%s with w=%d\n", __FUNCTION__, w);
		if (loop_coords(m, pool, w, 0))
			break;
		w++;
	}
	return ;
}

void		solver(t_ppool pool)
{
	char		m[MAP_W][MAP_W];
	int const	max = 7;

	memset(m, '.', sizeof(m));

	loop_sizes(m, &pool);

	int x, y;
	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 15; x++)
		{
			qprintf("%c ", m[y][x]);
		}
		qprintf("\n");
	}
	return ;
}


t_piece const pcs[] = {
	(t_piece){2, 3, {{1, 0},{0, 1},{1, 1},{0, 2},}, '0'},
	(t_piece){3, 2, {{1, 0},{0, 1},{1, 1},{2, 1},}, '0'},
	(t_piece){2, 3, {{1, 0},{1, 1},{0, 2},{1, 2},}, '0'},
	(t_piece){2, 3, {{1, 0},{0, 1},{1, 1},{1, 2},}, '0'},
	(t_piece){3, 2, {{1, 0},{2, 0},{0, 1},{1, 1},}, '0'},
	(t_piece){2, 3, {{0, 0},{0, 1},{1, 1},{0, 2},}, '0'},
	(t_piece){3, 2, {{0, 0},{1, 0},{2, 0},{1, 1},}, '0'},
	(t_piece){3, 2, {{0, 0},{0, 1},{1, 1},{2, 1},}, '0'},
	(t_piece){3, 2, {{0, 0},{1, 0},{1, 1},{2, 1},}, '0'},
	(t_piece){1, 4, {{0, 0},{0, 1},{0, 2},{0, 3},}, '0'},
	(t_piece){2, 3, {{0, 0},{1, 0},{0, 1},{0, 2},}, '0'},
	(t_piece){3, 2, {{0, 0},{1, 0},{2, 0},{2, 1},}, '0'},
	(t_piece){2, 3, {{0, 0},{0, 1},{0, 2},{1, 2},}, '0'},
	(t_piece){2, 2, {{0, 0},{1, 0},{0, 1},{1, 1},}, '0'},
	(t_piece){2, 3, {{0, 0},{1, 0},{1, 1},{1, 2},}, '0'},
	(t_piece){3, 2, {{0, 0},{1, 0},{2, 0},{0, 1},}, '0'},
	(t_piece){3, 2, {{2, 0},{0, 1},{1, 1},{2, 1},}, '0'},
	(t_piece){2, 3, {{0, 0},{0, 1},{1, 1},{1, 2},}, '0'},
	(t_piece){4, 1, {{0, 0},{1, 0},{2, 0},{3, 0},}, '0'},
};

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int							main(void)
{
	t_ppool		pool;
	int			i;
	int const	max = 13;

	srand(0);
	/* srand(clock()); */

	bzero(&pool, sizeof(pool)); //debug

	for (i = 0; i < max; i++)
	{
		pool.pcs[i] = pcs[rand() % sizeof(pcs) / sizeof(*pcs)];
	}
	pool.lastpid = max - 1;

	for (i = 'A'; i <= 'Z'; i++) pool.pcs[i - 'A'].character = i;

	solver(pool);
	return (0);
}
