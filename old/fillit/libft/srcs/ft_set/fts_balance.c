/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_balance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 13:42:07 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:36:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"
#include <errno.h>

#define SETNODE struct s_ftset_node

static SETNODE		*bal_ll(SETNODE *cur, SETNODE *l1, SETNODE *r2)
{
	*l1 = (SETNODE){cur->parent, l1->l, cur, 0};
	*cur = (SETNODE){l1, r2, cur->r, 0};
	fts_repair_sons_link(r2, cur);
	fts_repair_parents_link(l1, l1->parent, cur);
	fts_repair_node_height(cur);
	fts_repair_node_height(l1);
	fts_repair_parents_heights(l1->parent);
	return (l1);
}

static SETNODE		*bal_lr(SETNODE *cur, SETNODE *l1, SETNODE *r2)
{
	SETNODE	*l3;
	SETNODE	*r3;

	l3 = r2->l;
	r3 = r2->r;
	*r2 = (SETNODE){cur->parent, l1, cur, 0};
	*l1 = (SETNODE){r2, l1->l, l3, 0};
	*cur = (SETNODE){r2, r3, cur->r, 0};
	fts_repair_sons_link(l3, l1);
	fts_repair_sons_link(r3, cur);
	fts_repair_parents_link(r2, r2->parent, cur);
	fts_repair_node_height(l1);
	fts_repair_node_height(cur);
	fts_repair_node_height(r2);
	fts_repair_parents_heights(r2->parent);
	return (r2);
}

static SETNODE		*bal_rr(SETNODE *cur, SETNODE *r1, SETNODE *l2)
{
	*r1 = (SETNODE){cur->parent, cur, r1->r, 0};
	*cur = (SETNODE){r1, cur->l, l2, 0};
	fts_repair_sons_link(l2, cur);
	fts_repair_parents_link(r1, r1->parent, cur);
	fts_repair_node_height(cur);
	fts_repair_node_height(r1);
	fts_repair_parents_heights(r1->parent);
	return (r1);
}

static SETNODE		*bal_rl(SETNODE *cur, SETNODE *r1, SETNODE *l2)
{
	SETNODE	*l3;
	SETNODE	*r3;

	l3 = l2->l;
	r3 = l2->r;
	*l2 = (SETNODE){cur->parent, cur, r1, 0};
	*cur = (SETNODE){l2, cur->l, l3, 0};
	*r1 = (SETNODE){l2, r3, r1->r, 0};
	fts_repair_sons_link(l3, cur);
	fts_repair_sons_link(r3, r1);
	fts_repair_parents_link(l2, l2->parent, cur);
	fts_repair_node_height(r1);
	fts_repair_node_height(cur);
	fts_repair_node_height(l2);
	fts_repair_parents_heights(l2->parent);
	return (l2);
}

SETNODE				*fts_rebalance_node(SETNODE *cur)
{
	SETNODE	*l1;
	SETNODE	*r1;
	SETNODE	*l2;
	SETNODE	*r2;
	int		diff;

	l1 = cur->l;
	r1 = cur->r;
	diff = (l1 == NULL ? 0 : l1->height) - (r1 == NULL ? 0 : r1->height);
	if (diff > 1)
	{
		l2 = l1->l;
		r2 = l1->r;
		diff = (l2 == NULL ? 0 : l2->height) - (r2 == NULL ? 0 : r2->height);
		return (diff >= 0 ? bal_ll(cur, l1, r2) : bal_lr(cur, l1, r2));
	}
	else if (diff < -1)
	{
		l2 = r1->l;
		r2 = r1->r;
		diff = (l2 == NULL ? 0 : l2->height) - (r2 == NULL ? 0 : r2->height);
		return (diff <= 0 ? bal_rr(cur, r1, l2) : bal_rl(cur, r1, l2));
	}
	return (cur);
}
