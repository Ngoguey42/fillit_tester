/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve128.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:14:45 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 11:15:30 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static bool		loop(
	__uint128_t const m, t_ppool *const pool, int const w, int const pid)
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

bool		flt_solve128(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid)
{
	return (loop_coords64(m, pool, w, pid));
}
