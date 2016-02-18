/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve64.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:13:56 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 11:33:12 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Main algorithm (bitwise) when w <= sizeof(uintmax_t)
** Writes result to pool[]->finalpos
** *
** Without -O2 'static' does nothing
** With -O2 'static' speeds things up by 14%
*/

static bool		loop(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid)
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
				if (pid == pool->lastpid || loop(m | pmask, pool, w, pid + 1))
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

bool		flt_solve64(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid)
{
	return (loop(m, pool, w, pid));
}
