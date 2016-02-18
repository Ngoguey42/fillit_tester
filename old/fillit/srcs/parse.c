/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:04:11 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 12:05:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

extern t_piece const pcs[19];

static bool			charsValid(char const buf[(4 + 1) * 4])
{
	int				sharp_count;
	int				x;
	int				y;

	sharp_count = 0;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (buf[y * 5 + x] == '#')
				sharp_count++;
			else if (buf[y * 5 + x] != '.')
				return (qprintf("FAILED LINE %d", __LINE__), false);
		}
		if (buf[y * 5 + 4] != '\n')
			return (qprintf("FAILED LINE %d", __LINE__), false);
	}
	if (sharp_count != 4)
		return (qprintf("FAILED LINE %d", __LINE__), false);
	return true;
}

static unsigned int	adjDiff(char const val[(4 + 1) * 4])
{
	unsigned int    acc;
	int				x;
	int				y;

	acc = 0;
	for (y = 0; y < 4; y++)
		for (x = 0; x < 3; x++)
			if (val[y * 5 + x] == '#' && val[y * 5 + x + 1] == '#')
				acc++;
	for (y = 0; y < 3; y++)
		for (x = 0; x < 4; x++)
			if (val[y * 5 + x] == '#' && val[(y + 1) * 5 + x] == '#')
				acc++;
	return acc;
}

static bool			match_piece(
	char const val[(4 + 1) * 4], t_piece const *pc, t_vec2i tl)
{
	int		x;
	int		y;
	int		dt;

	for (dt = 0; dt < 4; dt++)
	{
		y = tl.y + pc->dt[dt].y;
		x = tl.x + pc->dt[dt].x;
		if (x >= 4 || y >= 4 || val[y * 5 + x] != '#')
			return false;
	}
	return true;
}

static t_vec2i		calc_top_left(char const val[(4 + 1) * 4])
{
	int				x;
	int				y;
	int				minx;
	int				miny;

	minx = 4;
	miny = 4;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (val[y * 5 + x] == '#')
			{
				minx = MIN(x, minx);
				miny = MIN(y, miny);
			}
		}
	}
	return (t_vec2i){minx, miny};
}

static void			save_piece(char const val[(4 + 1) * 4], t_ppool p[1])
{
	t_piece const	*pc = pcs;
	t_vec2i const	topleft = calc_top_left(val);

	while ((void*)pc < END_ARRAY(pcs))
	{
		if (match_piece(val, pc, topleft))
		{
			p->pcs[p->lastpid] = *pc;
			return ;
		}
		pc++;
	}
	qprintf("FAILED LINE %d", __LINE__);
	return ;
}

int					flt_parse(char const *fname, t_ppool p[1])
{
	int const	fd = open(fname, O_RDONLY);
	char		buf1[(4 + 1) * 4];
	char		buf2[1];
	int			ret;
	int			i;

	i = 0;
	while ((ret = read(fd, buf1 + i, sizeof(buf1) - i)) > 0)
	{
		i += ret;
		if (i == sizeof(buf1))
		{
			if (!charsValid(buf1) || adjDiff(buf1) < 3)
				return (qprintf("FAILED LINE %d", __LINE__), 1);
			save_piece(buf1, p);
			p->lastpid++;
			ret = read(fd, buf2, 1);
			if (ret == 0)
				break ;
			else if (ret < 0 || *buf2 != '\n')
				return (qprintf("FAILED LINE %d", __LINE__), 1);
			i = 0;
		}
	}
	p->lastpid--;
	close(fd);
	return (0);
}
