/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_varg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:23:00 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/28 11:21:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

/*
** 'get_signed_varg' returns an int64_t.
** 'get_unsigned_varg' returns a uint64_t.
*/

/*
** Observing schools' 25/80 lines/cols limit using my libft/.../ft_typedefs.h.
** Schools' norm also forbids stdint.h library and switch/case use.
** Last line isn't reached, compilation flag requires a return.
** lengths:
** none	j	z	t	L	h	l	hh	ll
** 0	1	2	3	4	5	6	7	8
*/

t_i64	get_signed_varg(unsigned char length, va_list *args)
{
	if (length == 0)
		return ((t_i64)(int)va_arg(*args, long int));
	else if (length == 1)
		return ((t_i64)(intmax_t)va_arg(*args, t_i64));
	else if (length == 2)
		return ((t_i64)va_arg(*args, size_t));
	else if (length == 3)
		return ((t_i64)(ptrdiff_t)va_arg(*args, long int));
	else if (length == 4)
		return ((t_i64)(int)va_arg(*args, long int));
	else if (length == 5)
		return ((t_i64)(short int)va_arg(*args, long int));
	else if (length == 6)
		return ((t_i64)(long int)va_arg(*args, long int));
	else if (length == 7)
		return ((t_i64)(char)va_arg(*args, long int));
	else if (length == 8)
		return ((t_i64)va_arg(*args, t_i64));
	return ((t_i64)(int)va_arg(*args, long int));
}

t_ui64	get_unsigned_varg(unsigned char length, va_list *args)
{
	if (!length)
		return ((t_ui64)(unsigned int)va_arg(*args, t_ui32));
	else if (length == 1)
		return ((t_ui64)(uintmax_t)va_arg(*args, t_ui64));
	else if (length == 2)
		return ((t_ui64)va_arg(*args, size_t));
	else if (length == 3)
		return ((t_ui64)va_arg(*args, ptrdiff_t));
	else if (length == 4)
		return ((t_ui64)(unsigned int)va_arg(*args, t_ui32));
	else if (length == 5)
		return ((t_ui64)(unsigned short int)va_arg(*args, t_ui32));
	else if (length == 6)
		return ((t_ui64)(t_ui32)va_arg(*args, t_ui32));
	else if (length == 7)
		return ((t_ui64)(unsigned char)va_arg(*args, t_ui32));
	else if (length == 8)
		return ((t_ui64)va_arg(*args, t_ui64));
	return ((t_ui64)(unsigned int)va_arg(*args, t_ui32));
}
