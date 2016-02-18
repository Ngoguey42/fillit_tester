/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 09:59:21 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:24:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_vector.h"

#ifdef LIBFT_INTERNAL_USE_STD
# include <string.h>
#endif

size_t		ftv_find_index(t_ftvector const *v, void const *ref)
{
	size_t		i;

	i = 0;
	while (i < v->size)
	{
		if (LIBFT_MEMCMP(v->data + v->chunk_size * i, ref, v->chunk_size) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void		*ftv_find_ptr(t_ftvector const *v, void const *ref)
{
	void		*ptr;
	void const	*ptrend;

	ptr = v->data;
	ptrend = v->data + v->chunk_size * v->size;
	while (ptr < ptrend)
	{
		if (LIBFT_MEMCMP(ptr, ref, v->chunk_size) == 0)
			return (ptr);
		ptr += v->chunk_size;
	}
	return (NULL);
}

bool		ftv_find(t_ftvector const *v, void const *ref)
{
	return (ftv_find_ptr(v, ref) ? true : false);
}
