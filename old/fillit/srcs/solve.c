/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:03:33 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 14:56:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Math function
*/
static int			ft_sqrtfloor(int v)
{
	int		i;

	i = v;
	while (i * i > v)
		i--;
	return i;
}

static int			ft_sqrtceil(int v)
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

static void			write_map_bitwise_solve(t_map m, t_ppool *const pool)
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

/*
** Tries succesive map size picking the right algorithm
*/
static int			loop_sizes(t_map m, t_ppool *const pool)
{
	unsigned int			w;

	w = ft_sqrtceil(pool->lastpid * 4 + 4);
	while (1)
	{
		if (w * 4 <= sizeof(uintmax_t))
		{
			if (flt_solve64(0, pool, w, 0))
			{
				write_map_bitwise_solve(m, pool);
				break ;
			}
		}
		else if (w * 4 <= sizeof(__uint128_t))
		{
			if (flt_solve128(0, pool, w, 0))
			{
				write_map_bitwise_solve(m, pool);
				break ;
			}
		}
		else
		{
			if (flt_solveptr(m, pool, w, 0))
				break ;
		}
		w++;
	}
	return (w);
}

/*
** Builds t_map and prints result
*/
void				flt_solve(t_ppool *pool)
{
	char		m[MAP_W][MAP_W];
	int			w;
	int			x;
	int			y;

	memset(m, '.', sizeof(m));
	w = loop_sizes(m, pool);
	for (y = 0; y < w; y++)
	{
		for (x = 0; x < w; x++)
		{
			ft_putchar(m[y][x]);
		}
		ft_putchar('\n');
	}
	return ;
	(void)ft_sqrtfloor;
}
