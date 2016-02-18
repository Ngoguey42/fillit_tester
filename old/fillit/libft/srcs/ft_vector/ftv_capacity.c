/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 18:37:27 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 19:28:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#include <stdlib.h>
#include <errno.h>

int					ftv_reserve(t_ftvector *v, size_t newcapacity)
{
	if (v->data != NULL)
		v->data = LIBFT_REALLOC(v->data, v->capacity * v->chunk_size,
								newcapacity * v->chunk_size);
	else
		v->data = malloc(newcapacity * v->chunk_size);
	if (v->data == NULL)
		return (ENOMEM);
	v->capacity = newcapacity;
	return (0);
}

int					ftv_double_capacity(t_ftvector *v)
{
	if (v->capacity == 0)
		return (ftv_reserve(v, 1));
	return (ftv_reserve(v, v->capacity * 2));
}

int					ftv_shrink_to_fit(t_ftvector *v)
{
	if (v->data == NULL)
		return (0);
	v->data = LIBFT_REALLOC(v->data, v->capacity * v->chunk_size,
							v->size * v->chunk_size);
	if (v->data == NULL)
		return (ENOMEM);
	v->capacity = v->size;
	return (0);
}
