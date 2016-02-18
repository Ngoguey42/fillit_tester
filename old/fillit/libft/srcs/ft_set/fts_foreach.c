/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_foreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 15:03:38 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:29:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

void				fts_foreach(t_ftset *s, void (*fun)(), void *ext)
{
	t_ftset_node		*node;

	node = fts_begin(s);
	while (node != NULL)
	{
		fun(ext, node);
		node = fts_next(node);
	}
	return ;
}

void				fts_foreachi(t_ftset *s, void (*fun)(), void *ext)
{
	t_ftset_node		*node;
	int					i;

	i = 0;
	node = fts_begin(s);
	while (node != NULL)
	{
		fun(ext, node, i++);
		node = fts_next(node);
	}
	return ;
}
