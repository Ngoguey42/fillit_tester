/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 10:34:36 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 12:53:44 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_set.h"

void				fts_init_instance(t_ftset *s, size_t chunk_size
										, int (*cmp)())
{
	*s = (t_ftset){NULL, 0, 0, chunk_size, cmp};
	return ;
}

t_ftset				fts_uninitialized(void)
{
	return ((t_ftset){NULL, 0, 0, 0, NULL});
}
