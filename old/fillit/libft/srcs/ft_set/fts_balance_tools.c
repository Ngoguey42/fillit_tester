/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_balance_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 13:42:28 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:28:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"
#include <errno.h>

#define SETNODE struct s_ftset_node

void			fts_repair_sons_link(SETNODE *son, SETNODE *parent)
{
	if (son != NULL)
		son->parent = parent;
	return ;
}

void			fts_repair_node_height(SETNODE *node)
{
	SETNODE const *const	l = node->l;
	SETNODE	const *const	r = node->r;
	int const				rh = r == NULL ? 0 : r->height;
	int const				lh = l == NULL ? 0 : l->height;

	node->height = MAX(rh, lh) + 1;
	return ;
}

void			fts_repair_parents_link(SETNODE *son, SETNODE *parent
										, SETNODE const *oldson)
{
	if (parent != NULL)
	{
		if (parent->l == oldson)
			parent->l = son;
		else
			parent->r = son;
	}
	return ;
}

void			fts_repair_parents_heights(t_ftset_node *node)
{
	while (node != NULL)
	{
		fts_repair_node_height(node);
		node = node->parent;
	}
	return ;
}
