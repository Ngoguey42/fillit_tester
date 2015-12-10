/* ************************************************************************** */
/*																			*/
/*														:::		::::::::	*/
/*	testlol.c											:+:		:+:	:+:	*/
/*													+:+ +:+		+:+	*/
/*	By: ngoguey <ngoguey@student.42.fr>			+#+	+:+		+#+		*/
/*												+#+#+#+#+#+	+#+			*/
/*	Created: 2015/12/10 17:22:22 by ngoguey			#+#	#+#			*/
/*   Updated: 2015/12/10 18:59:27 by ngoguey          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <assert.h> //TO REMOVE LATER

#define qprintf printf

typedef struct	s_dyna
{
	void*		data;
	size_t		chunck_count;
	size_t		chunck_max;
	size_t		chunck_size;
}				t_dyna;

typedef struct	s_vec2i
{
	int			x;
	int			y;
}				t_vec2i;

/* pool.pcs[0] = (t_piece){false, false, 4, 1, (t_vec2i[]){ */

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


void		load_indices(t_map m, char *indices[4], t_vec2i c, t_piece const *p)
{
	indices[0] = &m[c.y + p->dt[0].y][c.x + p->dt[0].x];
	indices[1] = &m[c.y + p->dt[1].y][c.x + p->dt[1].x];
	indices[2] = &m[c.y + p->dt[2].y][c.x + p->dt[2].x];
	indices[3] = &m[c.y + p->dt[3].y][c.x + p->dt[3].x];
	return ;
}

void		apply_indices(t_map m, char *indices[4], t_piece const *p)
{
	*indices[0] = p->character;
	*indices[1] = p->character;
	*indices[2] = p->character;
	*indices[3] = p->character;
	return ;
}

bool		check_indices(char *indices[4])
{
	return (*indices[0] == '.' && *indices[1] == '.'
			&& *indices[2] == '.' && *indices[3] == '.');
}

void		unapply_indices(t_map m, char *indices[4])
{
	*indices[0] = '.';
	*indices[1] = '.';
	*indices[2] = '.';
	*indices[3] = '.';
	return ;
}

bool		loop_sizes(t_map m, t_ppool *pool);


bool		rec(t_map m, t_ppool *pool)
{
	if (pool->nfree == 0)
		return true;
	return loop_sizes(m, pool);
}

bool		loop_coords(t_map m, t_ppool *pool
						, int w
						, t_piece *p)
{
	t_vec2i		c;
	char		*indices[4];

	qprintf("%s w=%d p=%p\n", __FUNCTION__, w, p);
	pool->nfree--;
	c.y = 0;
	while (c.y < w - p->h)
	{
		c.x = 0;
		while (c.x < w - p->w)
		{
			load_indices(m, indices, c, p);
			if (check_indices(indices))
			{
				apply_indices(m, indices, p);
				p->claimed = true;
				if (rec(m, pool))
					return true;
				p->claimed = false;
				unapply_indices(m, indices);
			}
			c.x++;
		}
		c.y++;
	}
	pool->nfree++;
	return false;
}

bool		loop_pieces(t_map m, t_ppool *pool
						, int w)
{
	t_piece		*p;

	qprintf("%s w=%d\n", __FUNCTION__, w);
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
	return false;
}

bool		loop_sizes(t_map m, t_ppool *pool)
{
	int		w;

	w = 2;
	qprintf("%s\n", __FUNCTION__);
	while (1)
	{
		assert(w <= (MAP_W / 15));
		if (loop_pieces(m, pool, w))
			break;
		w++;
	}
	return w;
}

void		entry()
{
	char		m[MAP_W][MAP_W];
	t_ppool		pool;

	bzero(&pool, sizeof(pool)); //debug

	pool.pcs[2].vacant = true;
	pool.nfree = 2;
	pool.pcs[0]= (t_piece){false, false, 4, 1,
					   {
		(t_vec2i){0, 0},
		(t_vec2i){1, 0},
		(t_vec2i){2, 0},
		(t_vec2i){3, 0},
	}, 'A' };
	pool.pcs[1]= (t_piece){false, false, 4, 1,
					   {
		(t_vec2i){0, 0},
		(t_vec2i){1, 0},
		(t_vec2i){2, 0},
		(t_vec2i){3, 0},
	}, 'B' };


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

int							main(void)
{
	entry();
	return (0);
}
