/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:33:31 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 12:06:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Slave functions for fallback algorithm
*/

static void		load_marks(
	t_map m, char *marks[const 4], t_vec2i const c, t_vec2i const dt[const 4])
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

#define CHEAT_INCREMENT_MARKS(k) k[0]++, k[1]++, k[2]++, k[3]++

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

static bool		loop(
	t_map m, t_ppool const *const pool, int const w, int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	char					*k[4];

	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		load_marks(m, k, c, p->dt);
		while (c.x <= w - p->w)
		{
			if (*k[0] == '.' && *k[1] == '.' && *k[2] == '.' && *k[3] == '.')
			{
				apply_marks(k, p->character);
				if (pid == pool->lastpid || loop(m, pool, w, pid + 1))
					return (true);
				unapply_marks(k);
			}
			CHEAT_INCREMENT_MARKS(k);
			c.x++;
		}
		c.y++;
	}
	return (false);
}

bool			flt_solveptr(
	t_map m, t_ppool *const pool, int const w, int const pid)
{
	return (loop(m, pool, w, pid));
}
