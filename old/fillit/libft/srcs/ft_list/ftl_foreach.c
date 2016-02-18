/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_foreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 19:02:31 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/17 13:40:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_list.h"

#define LISTNODE struct s_ftlist_node

void		ftl_foreach(t_ftlist const *l, void (*fun)(), void *ext)
{
	LISTNODE	*node;

	node = l->next;
	while (node != ftl_cend(l))
	{
		fun(ext, node);
		node = node->next;
	}
	return ;
}

void		ftl_foreach2(t_ftlist const *l, void (*fun)(), void *e1, void *e2)
{
	LISTNODE	*node;

	node = l->next;
	while (node != ftl_cend(l))
	{
		fun(e1, e2, node);
		node = node->next;
	}
	return ;
}

void		ftl_foreachi(t_ftlist const *l, void (*fun)(), void *ext)
{
	LISTNODE	*node;
	int			i;

	i = 0;
	node = l->next;
	while (node != ftl_cend(l))
	{
		fun(ext, node, i);
		node = node->next;
		i++;
	}
	return ;
}

void		ftl_foreach_if(t_ftlist const *l, void (*fun)(), void *ext
							, bool (*pred)())
{
	LISTNODE	*node;

	node = l->next;
	while (node != ftl_cend(l))
	{
		if (pred(ext, node))
			fun(ext, node);
		node = node->next;
	}
	return ;
}

void		ftl_foreachi_if(t_ftlist const *l, void (*fun)(), void *ext
							, bool (*pred)())
{
	LISTNODE	*node;
	int			i;

	i = 0;
	node = l->next;
	while (node != ftl_cend(l))
	{
		if (pred(ext, node, i))
			fun(ext, node, i);
		node = node->next;
		i++;
	}
	return ;
}
