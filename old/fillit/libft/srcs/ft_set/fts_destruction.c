/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_destruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 10:34:43 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 12:54:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"
#include <stdlib.h>

void				fts_release(t_ftset *s, void (*dea)())
{
	t_ftset_node			*node;
	t_ftset_node			*next;

	node = fts_begin(s);
	while (node != NULL)
	{
		if (node->l != NULL)
			node = node->l;
		else if (node->r != NULL)
			node = node->r;
		else
		{
			next = node->parent;
			if (next != NULL && next->l == node)
				next->l = NULL;
			else if (next != NULL)
				next->r = NULL;
			if (dea != NULL)
				dea(node);
			free(node);
			node = next;
		}
	}
	*s = fts_uninitialized();
	return ;
}
