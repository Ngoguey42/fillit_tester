/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printt_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 15:55:51 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 19:23:42 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"

void			dbg_recap(void)
{
	size_t		i;
	size_t		len;

	i = 0;
	len = dbg_instance()->lines.size;
	while (i < len)
	{
		dbg_printline(i);
		i++;
	}
	return ;
}

void			dbg_resetlog(void)
{
	t_ftvector	*v;
	size_t		i;

	i = 0;
	v = &dbg_instance()->lines;
	while (i < v->size)
	{
		((t_debugline*)v->data)[i].logcount = 0;
		i++;
	}
	return ;
}

void			dbg_noprint(void)
{
	dbg_instance()->print = false;
	return ;
}

void			dbg_doprint(void)
{
	dbg_instance()->print = true;
	return ;
}
