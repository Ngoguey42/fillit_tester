/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_destruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 11:31:10 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 19:33:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <errno.h>
#include <stdlib.h>

void			ftv_clear(t_ftvector *v, void (*del)(void*))
{
	size_t		i;

	if (del != NULL)
	{
		i = 0;
		while (i < v->size)
			del((char*)v->data + i++ * v->chunk_size);
	}
	v->size = 0;
	return ;
}

void			ftv_release(t_ftvector *v, void (*del)(void*))
{
	ftv_clear(v, del);
	if (v->data != NULL)
		free(v->data);
	return ;
}

void			ftv_pop_back(t_ftvector *v, void (*del)(void*))
{
	if (del != NULL)
		del((char*)v->data + (v->size - 1) * v->chunk_size);
	v->size--;
	return ;
}
