/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 10:34:30 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:24:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"
#include <errno.h>

#define SETNODE struct s_ftset_node
#define NORM_AT_42_IS_WTF s->cmp

static SETNODE	*build_left(t_ftset *const s
							, t_ftset_node const *const new
							, t_ftset_insertion *const status
							, t_ftset_node *const cur)
{
	t_ftset_node	*newson;

	if (cur->l == NULL)
	{
		newson = fts_gen_node(s, cur, new, status);
		cur->l = newson;
		fts_increment_parents_heights(newson, cur);
	}
	else
	{
		newson = fts_build_cur(s, new, status, cur->l);
	}
	if (newson == NULL)
		return (NULL);
	return (fts_rebalance_node(cur));
}

static SETNODE	*build_right(t_ftset *const s
							, t_ftset_node const *const new
							, t_ftset_insertion *const status
							, t_ftset_node *const cur)
{
	t_ftset_node	*newson;

	if (cur->r == NULL)
	{
		newson = fts_gen_node(s, cur, new, status);
		cur->r = newson;
		fts_increment_parents_heights(newson, cur);
	}
	else
	{
		newson = fts_build_cur(s, new, status, cur->r);
	}
	if (newson == NULL)
		return (NULL);
	return (fts_rebalance_node(cur));
}

SETNODE			*fts_build_cur(t_ftset *const s
								, t_ftset_node const *const new
								, t_ftset_insertion *const status
								, t_ftset_node *const cur)
{
	int const		cmp = NORM_AT_42_IS_WTF(cur, new, s);

	if (cmp < 0)
		return (build_left(s, new, status, cur));
	else if (cmp > 0)
		return (build_right(s, new, status, cur));
	if (status != NULL)
		*status = (t_ftset_insertion){cur, false};
	return (cur);
}

int				fts_insert(t_ftset *s, t_ftset_node const *node
								, t_ftset_insertion *status)
{
	SETNODE		*head;

	if (s->size == 0)
		head = fts_gen_node(s, NULL, node, status);
	else
		head = fts_build_cur(s, node, status, s->head);
	if (head == NULL)
		return (ENOMEM);
	s->head = head;
	s->height = head->height;
	return (0);
}
