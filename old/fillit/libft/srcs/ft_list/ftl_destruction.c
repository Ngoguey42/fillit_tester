/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_destruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 17:37:55 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:10:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_list.h"

#define LISTNODE struct s_ftlist_node

static void	del(LISTNODE *prev, LISTNODE *next)
{
	next->prev = prev;
	prev->next = next;
	return ;
}

void		ftl_release(t_ftlist *l, void (*deallocator)())
{
	LISTNODE	*node;
	LISTNODE	*next;

	node = l->next;
	while (node != FTL_CEND(l))
	{
		next = node->next;
		del(node->prev, next);
		if (deallocator != NULL)
			deallocator(node);
		free(node);
		node = next;
	}
	*l = ftl_uninitialized();
	return ;
}

void		ftl_pop_back(t_ftlist *l, void (*deallocator)())
{
	LISTNODE	*node;

	node = l->prev;
	del(node->prev, FTL_END(l));
	if (deallocator != NULL)
		deallocator(node);
	free(node);
	l->size--;
	return ;
}

void		ftl_pop_front(t_ftlist *l, void (*deallocator)())
{
	LISTNODE	*node;

	node = l->next;
	del(FTL_END(l), node->next);
	if (deallocator != NULL)
		deallocator(node);
	free(node);
	l->size--;
	return ;
}

void		ftl_erase_pos(t_ftlist *l, LISTNODE *pos, void (*deallocator)())
{
	del(pos->prev, pos->next);
	if (deallocator != NULL)
		deallocator(pos);
	free(pos);
	l->size--;
	return ;
}
