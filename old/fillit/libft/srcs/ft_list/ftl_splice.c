/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_splice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 12:34:24 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 14:06:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "fterror.h"
#include <stdlib.h>

#define LISTNODE struct s_ftlist_node

static void	del(LISTNODE *prev, LISTNODE *next)
{
	next->prev = prev;
	prev->next = next;
	return ;
}

static void	add(LISTNODE *new, LISTNODE *prev, LISTNODE *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
	return ;
}

void		ftl_splice_one_back(t_ftlist *dst, t_ftlist *src, LISTNODE *node)
{
	t_ftlist_node	*next;

	FT_ASSERT(dst->chunk_size == src->chunk_size);
	src->size--;
	dst->size++;
	del(node->prev, node->next);
	next = dst->prev;
	add(node, next->prev, next);
	return ;
}
