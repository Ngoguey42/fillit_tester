/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve128_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:52:52 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 11:57:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** __uint128_t *const m		same virtual map as in space_left
** __uint128_t cmask		current coord mask while recursing
*/

#define _CHEAT2(...) space += follow(m, w, cmask, __VA_ARGS__)
#define _CHEAT1(...) if ((*m & *cmask) == 0) _CHEAT2(__VA_ARGS__)
#define CHEAT(OP1, OP2, ...) *cmask OP1; _CHEAT1(__VA_ARGS__); *cmask OP2

#define CHEAT_TOP CHEAT(>>= 11, <<= 11, (t_vec2i){c.x, c.y - 1})
#define CHEAT_BOTTOM CHEAT(<<= 11, >>= 11, (t_vec2i){c.x, c.y + 1})
#define CHEAT_LEFT CHEAT(>>= 1, <<= 1, (t_vec2i){c.x - 1, c.y})
#define CHEAT_RIGHT CHEAT(<<= 1, >>= 1, (t_vec2i){c.x + 1, c.y})

static unsigned int	follow(
	__uint128_t *const m, int const w, __uint128_t *cmask, t_vec2i c)
{
	unsigned int	space;

	*m |= *cmask;
	space = 1;
	if (c.y > 0)
	{
		CHEAT_TOP;
	}
	if (c.y < w - 1)
	{
		CHEAT_BOTTOM;
	}
	if (c.x > 0)
	{
		CHEAT_LEFT;
	}
	if (c.x < w - 1)
	{
		CHEAT_RIGHT;
	}
	return (space);
}

/*
** __uint128_t m			virtual map found counting
** __uint128_t cmask		current coords mask while iterating
*/

static unsigned int	space_left(__uint128_t m, int const w)
{
	t_vec2i			c;
	__uint128_t		cmask[1];
	unsigned int	space;
	unsigned int	tmp;

	space = 0;
	c.y = 0;
	while (c.y < w)
	{
		*cmask = ((__uint128_t)1) << (11 * c.y);
		c.x = 0;
		while (c.x < w)
		{
			if ((m & *cmask) == 0)
			{
				tmp = follow(&m, w, cmask, c);
				if (tmp >= 4)
					space += tmp;
			}
			*cmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return (space);
}

static bool			loop(
	__uint128_t const m, t_ppool *const pool, int const w, int const pid)
{
	t_piece const *const	p = pool->pcs + pid;
	t_vec2i					c;
	__uint128_t				pmask;

	if (space_left(m, w) < (unsigned int)(pool->lastpid - pid + 1) * 4)
		return (false);
	c.y = 0;
	while (c.y <= w - p->h)
	{
		c.x = 0;
		pmask = p->mask128 << (11 * c.y);
		while (c.x <= w - p->w)
		{
			if ((pmask & m) == 0 &&
				(pid == pool->lastpid || loop(m | pmask, pool, w, pid + 1)))
			{
				pool->pcs[pid].finalpos = c;
				return (true);
			}
			pmask <<= 1;
			c.x++;
		}
		c.y++;
	}
	return (false);
}

bool				flt_solve128_plus(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid)
{
	return (loop(m, pool, w, pid));
}
