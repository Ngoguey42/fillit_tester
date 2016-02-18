/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 14:10:42 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/04 14:48:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "libft.h"

/*
** 'lprintf' calls a stderr printf, and flushes the stream afterward.
**				size < tty width.
** (quiet Line Printf)
*/

int		lprintf(const char *fmt, ...)
{
	int				ret;
	va_list			ap;
	struct winsize	w;
	char			buf[256];

	ft_bzero(&w, sizeof(struct winsize));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	va_start(ap, fmt);
	vsnprintf(buf, fmin(w.ws_col + 1, 255), fmt, ap);
	ret = fprintf(stderr, "%s\n", buf);
	va_end(ap);
	fflush(stderr);
	return (ret);
}
