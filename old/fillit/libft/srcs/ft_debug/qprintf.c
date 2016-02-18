/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 11:48:37 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 11:54:23 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

/*
** 'qprintf' calls a stderr printf, and flushes the stream afterward.
** (Quiet Printf)
*/

int	qprintf(const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, fmt);
	ret = vfprintf(stderr, fmt, ap);
	va_end(ap);
	fflush(stderr);
	return (ret);
}
