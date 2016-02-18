/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 18:25:20 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 19:27:43 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include <errno.h>
#include <stdlib.h>

void				ftv_init_instance(t_ftvector *v, size_t chunk_size)
{
	v->data = NULL;
	v->size = 0;
	v->chunk_size = chunk_size;
	v->capacity = 0;
	return ;
}

t_ftvector			*ftv_init_alloc(size_t chunk_size)
{
	t_ftvector	*ret;

	ret = malloc(sizeof(t_ftvector));
	if (ret == NULL)
		return (NULL);
	ftv_init_instance(ret, chunk_size);
	return (ret);
}

int					ftv_copy(t_ftvector *dst, t_ftvector const *src)
{
	*dst = *src;
	dst->data = ft_memdup(src->data, src->capacity * src->chunk_size);
	if (dst->data == NULL)
		return (ENOMEM);
	return (0);
}
