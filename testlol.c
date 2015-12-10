/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	*/
/*	testlol.c											:+:		:+:	:+:	*/
/*													+:+ +:+		+:+	*/
/*	By: ngoguey <ngoguey@student.42.fr>			+#+	+:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2015/12/10 17:22:22 by ngoguey			#+#	#+#			*/
/*   Updated: 2015/12/10 20:36:17 by ngoguey          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> //TO REMOVE LATER

#define qprintf printf


typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

typedef struct
{
	bool		claimed;
	bool		vacant;
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
	int			nfree;
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















bool		loop_pieces(t_map m, t_ppool *const pool, int const w);

bool		loop_coords(t_map m, t_ppool *const pool
						, int const w
						, t_piece *const p)
{
	t_vec2i		c;
	char		*marks[4];

	c.y = 0;
	while (c.y < w - p->h)
	{
		c.x = 0;
		while (c.x < w - p->w)
		{
			load_marks(m, marks, c, p->dt);
			if (check_marks(marks))
			{
				apply_marks(marks, p->character);
				p->claimed = true;
				if (pool->nfree == 0 || loop_pieces(m, pool, w))
					return true;
				p->claimed = false;
				unapply_marks(marks);
			}
			c.x++;
		}
		c.y++;
	}
	return false;
}

bool		loop_pieces(t_map m, t_ppool *const pool
						, int const w)
{
	t_piece		*p;

	pool->nfree--;
	p = pool->pcs;
	while (!p->vacant)
	{
		if (!p->claimed)
		{
			if (loop_coords(m, pool, w, p))
				return true;
		}
		p++;
	}
	pool->nfree++;
	return false;
}

void		loop_sizes(t_map m, t_ppool *const pool)
{
	int		w;

	w = 2;
	while (1)
	{
		qprintf("%s with w=%d\n", __FUNCTION__, w);
		if (loop_pieces(m, pool, w))
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
















t_piece	const	bar = (t_piece){false, false, 4, 1,
								{
									(t_vec2i){0, 0},
									(t_vec2i){1, 0},
									(t_vec2i){2, 0},
									(t_vec2i){3, 0},
								}, '0' };
t_piece	const	square = (t_piece){false, false, 2, 2,
								{
									(t_vec2i){0, 0},
									(t_vec2i){1, 0},
									(t_vec2i){1, 1},
									(t_vec2i){0, 1},
								}, '0' };
t_piece	const	z = (t_piece){false, false, 3, 2,
							  {
								  (t_vec2i){0, 0},
								  (t_vec2i){1, 0},
								  (t_vec2i){1, 1},
								  (t_vec2i){2, 1},
							  }, '0' };
t_piece	const	tr = (t_piece){false, false, 2, 3,
							  {
								  (t_vec2i){0, 0},
								  (t_vec2i){0, 1},
								  (t_vec2i){0, 2},
								  (t_vec2i){1, 1},
							  }, '0' };
t_piece	const	l = (t_piece){false, false, 2, 3,
							  {
								  (t_vec2i){0, 0},
								  (t_vec2i){0, 1},
								  (t_vec2i){0, 2},
								  (t_vec2i){1, 2},
							  }, '0' };

int const		listsz = 5;
t_piece const	*list[] = {
	&bar,
	&square,
	&z,
	&tr,
	&l,
};


#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int							main(void)
{
	t_ppool		pool;
	int			i;
	int const	max = 7;

	srand(clock());

	bzero(&pool, sizeof(pool)); //debug

	pool.pcs[0] = bar;
	for (i = 0; i < max; i++)
	{
		pool.pcs[i] = *list[rand() % listsz];
	}
	pool.nfree = max;

	for (i = 'A'; i <= 'Z'; i++) pool.pcs[i - 'A'].character = i;
	pool.pcs[pool.nfree].vacant = true;

	solver(pool);
	return (0);
}
