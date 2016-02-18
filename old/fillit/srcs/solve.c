/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:03:33 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 12:06:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
int 		loop_sizes(t_map m, t_ppool *const pool)
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

		/* if (w <= 8 && g_use_bitwise) */
		/* { */
		/* 	/\* qprintf("%s with w=%d loop_coords2\n", __FUNCTION__, w); *\/ */
		/* 	if (loop_coords2(0, pool, w, 0)) */
		/* 	{ */
		/* 		g_use_bitwise = false; */
		/* 		write_map_solve2(m, pool); */
		/* 		break; */
		/* 	} */
		/* } */
		/* else if (w <= 11 && g_use_bitwise) */
		/* { */
		/* 	/\* qprintf("%s with w=%d loop_coords3\n", __FUNCTION__, w); *\/ */
		/* 	if (loop_coords3(0, pool, w, 0)) */
		/* 	{ */
		/* 		g_use_bitwise = false; */
		/* 		write_map_solve2(m, pool); */
		/* 		break; */
		/* 	} */
		/* } */
		/* else */
		/* { */
			/* qprintf("%s with w=%d loop_coords\n", __FUNCTION__, w); */
			if (flt_solveptr(m, pool, w, 0))
				break;
		/* } */
		/* w++; */
	}
	return w;
}

/*
** Builds t_map and prints result
*/
void		flt_solve(t_ppool *pool)
{
	char		m[MAP_W][MAP_W];
	int			w;

	memset(m, '.', sizeof(m));

	w = loop_sizes(m, pool);

	int x, y;
	for (y = 0; y < w; y++)
	{
		for (x = 0; x < w; x++)
		{
			printf("%c", m[y][x]);
		}
		printf("\n");
	}
	return ;
}
