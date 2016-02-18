/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_insertions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:58:36 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/17 16:56:08 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_list.h"

#define LISTNODE struct s_ftlist_node

static void	add(LISTNODE *new, LISTNODE *prev, LISTNODE *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
	return ;
}

int			ftl_push_back(t_ftlist *l, LISTNODE const *node)
{
	LISTNODE	*anode;

	anode = ft_memdup(node, l->chunk_size);
	if (anode == NULL)
		return (ENOMEM);
	add(anode, l->prev, (LISTNODE*)l);
	l->size++;
	return (0);
}

int			ftl_push_front(t_ftlist *l, LISTNODE const *node)
{
	LISTNODE	*anode;

	anode = ft_memdup(node, l->chunk_size);
	if (anode == NULL)
		return (ENOMEM);
	add(anode, (LISTNODE*)l, l->next);
	l->size++;
	return (0);
}

int			ftl_insert_pos(t_ftlist *l, LISTNODE *pos, LISTNODE const *node)
{
	LISTNODE	*anode;

	anode = ft_memdup(node, l->chunk_size);
	if (anode == NULL)
		return (ENOMEM);
	add(anode, pos, pos->next);
	l->size++;
	return (0);
}

int			ftl_insert_sort(t_ftlist *l, LISTNODE const *node, int64_t (*cmp)())
{
	LISTNODE		*anode;
	LISTNODE		*nx_node;

	anode = ft_memdup(node, l->chunk_size);
	if (anode == NULL)
		return (ENOMEM);
	nx_node = l->next;
	while (nx_node != ftl_cend(l))
	{
		if (cmp(nx_node, anode) > 0)
			break ;
		nx_node = nx_node->next;
	}
	add(anode, nx_node->prev, nx_node);
	l->size++;
	return (0);
}
