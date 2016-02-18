/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 17:08:20 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/08 17:33:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_list.h"

void			ftl_init_instance(t_ftlist *l, size_t chunk_size)
{
	*l = (t_ftlist){(t_ftlist_node*)l, (t_ftlist_node*)l, chunk_size, 0};
	return ;
}

t_ftlist		ftl_uninitialized(void)
{
	return ((t_ftlist){NULL, NULL, 0, 0});
}
