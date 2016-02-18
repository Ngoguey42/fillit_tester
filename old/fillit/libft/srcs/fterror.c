/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fterror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 14:03:59 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 14:06:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fterror.h"
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#ifdef LIBFT_INTERNAL_USE_STD
# include <stdio.h>
# include <string.h>
#endif

void			ft_enomem(void)
{
	ft_putendl_fd("\033[31mError\033[0m: ENOMEM", 2);
	LFT_EXIT(1);
}

void			fte_assert(bool pred, char const *strings[3], int line)
{
	if (!pred)
	{
		LFT_DPTF(2, "\033[31mAssertion failed[\033[0m"
				"%s:%d\033[31m]:\033[0m (%s)\n",
				strings[1], line, strings[2]);
		LFT_EXIT(1);
	}
	return ;
}

int				fte_error(char const *strings[3], int line, ...)
{
	va_list		ap;

	LFT_DPTF(2, "\033[31mError[\033[0m%28s:%-3d\033[31m]: \033[0m",
				strings[1], line);
	va_start(ap, line);
	LFT_VDPTF(2, strings[2], ap);
	va_end(ap);
	LFT_FFLUSH(stderr);
	ft_putchar_fd('\n', 2);
	return (1);
}

int				fte_errorno(char const *strings[3], int line, ...)
{
	int const	err = errno;
	va_list		ap;

	LFT_DPTF(2, "\033[31mError[\033[0m%28s:%-3d\033[31m]: \033[0m",
				strings[1], line);
	va_start(ap, line);
	LFT_DPTF(2, strings[2], ap);
	va_end(ap);
	LFT_FFLUSH(stderr);
	LFT_DPTF(2, "\033[31m(\033[0m%s\033[31m)\033[0m\n", LFT_STRERROR(err));
	return (1);
}
