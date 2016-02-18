/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_foreach.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 10:06:00 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:24:14 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "ft_vector.h"

void		ftv_foreachi(t_ftvector const *v, void (*fun)(), void *ext)
{
	size_t		i;

	i = 0;
	while (i < v->size)
	{
		fun(ext, v->data + v->chunk_size * i, i);
		i++;
	}
	return ;
}

void		ftv_foreach(t_ftvector const *v, void (*fun)(), void *ext)
{
	void		*ptr;
	void const	*ptrend;

	ptr = v->data;
	ptrend = v->data + v->chunk_size * v->size;
	while (ptr < ptrend)
	{
		fun(ext, ptr);
		ptr += v->chunk_size;
	}
	return ;
}

void		ftv_foreach2(t_ftvector const *v, void (*fun)(), void *e1, void *e2)
{
	void		*ptr;
	void const	*ptrend;

	ptr = v->data;
	ptrend = v->data + v->chunk_size * v->size;
	while (ptr < ptrend)
	{
		fun(e1, e2, ptr);
		ptr += v->chunk_size;
	}
	return ;
}

void		ftv_foreach0(t_ftvector const *v, void (*fun)())
{
	void		*ptr;
	void const	*ptrend;

	ptr = v->data;
	ptrend = v->data + v->chunk_size * v->size;
	while (ptr < ptrend)
	{
		fun(ptr);
		ptr += v->chunk_size;
	}
	return ;
}

void		ftv_foreach_if(t_ftvector const *v, void (*fun)(), void *ext,
							bool (*cond)())
{
	void		*ptr;
	void const	*ptrend;

	ptr = v->data;
	ptrend = v->data + v->chunk_size * v->size;
	while (ptr < ptrend)
	{
		if (cond(ext, ptr))
			fun(ext, ptr);
		ptr += v->chunk_size;
	}
	return ;
}
