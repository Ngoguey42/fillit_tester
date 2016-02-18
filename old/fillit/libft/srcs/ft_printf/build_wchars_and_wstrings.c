/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_wchars_and_wstrings.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 09:06:54 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:04:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

#define WID part->width
#define STR part->nbr_ptr
#define PRE part->precision

/*
** 'build_nbr_25' %C.
** 'build_nbr_26' %S.
*/

static int		write_wint(wint_t wint, char *buf)
{
	if (wint < 0x80)
		buf[0] = ((wint >> 0) & 0x7F) | 0x00;
	else if (wint < 0x0800)
	{
		buf[0] = ((wint >> 6) & 0x1F) | 0xC0;
		buf[1] = ((wint >> 0) & 0x3F) | 0x80;
	}
	else if (wint < 0x010000)
	{
		buf[0] = ((wint >> 12) & 0x0F) | 0xE0;
		buf[1] = ((wint >> 6) & 0x3F) | 0x80;
		buf[2] = ((wint >> 0) & 0x3F) | 0x80;
	}
	else if (wint < 0x110000)
	{
		buf[0] = ((wint >> 18) & 0x07) | 0xF0;
		buf[1] = ((wint >> 12) & 0x3F) | 0x80;
		buf[2] = ((wint >> 6) & 0x3F) | 0x80;
		buf[3] = ((wint >> 0) & 0x3F) | 0x80;
	}
	return (0);
}

int				build_nbr_25(t_printf_part *part, va_list *args)
{
	wint_t	wint;

	WID = AND_I(WSTA_MASK) ? va_arg(*args, int) : WID;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	wint = va_arg(*args, wint_t);
	if ((part->nbr_ptr = ft_strnew(4)) == NULL)
		return (0);
	(void)write_wint(wint, part->nbr_ptr);
	STR[0] = (wint == 0) ? 1 : STR[0];
	if (part->width > 1)
	{
		if (AND_F(MINU_MASK))
			STR = ft_pad_string(STR, ' ', -part->width, 1);
		else
			STR = ft_pad_string(STR, PAD_CHAR, part->width, 1);
	}
	else if (part->width < -1)
		STR = ft_pad_string(STR, ' ', part->width, 1);
	part->nbr_size = ft_strlen(STR);
	if (wint == 0)
		part->nbr_ptr[ft_strcharlen(STR, '\1')] = '\0';
	return (1);
}

static size_t	fake_wstrlen(wchar_t *wstr)
{
	size_t	tot;

	tot = 0;
	while (*wstr++ != 0)
		tot++;
	return (tot);
}

static char		*write_wstr(wchar_t *wstr)
{
	char	*str;
	char	*save;

	if (wstr == NULL)
		return (ft_strdup("(null)"));
	if ((str = ft_strnew(fake_wstrlen(wstr) * 4 + 1)) == NULL)
		return (NULL);
	save = str;
	while (*wstr != 0)
	{
		write_wint((wint_t)*wstr, str);
		str += ft_strlen(str);
		wstr++;
	}
	return (save);
}

int				build_nbr_26(t_printf_part *part, va_list *args)
{
	wchar_t	*wstr;

	WID = AND_I(WSTA_MASK) ? va_arg(*args, int) : WID;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	wstr = va_arg(*args, wchar_t*);
	if ((STR = write_wstr(wstr)) == NULL)
		return (0);
	if (AND_I(PNUM_MASK) && PRE >= 0 && PRE < (int)ft_strlen(STR))
		STR[PRE] = '\0';
	if (WID > 0 && WID > (int)ft_strlen(STR))
	{
		if (AND_F(MINU_MASK))
			STR = ft_pad_string(STR, ' ', -WID, 1);
		else
			STR = ft_pad_string(STR, PAD_CHAR, WID, 1);
	}
	else if (WID < 0 && ABS(WID) > (int)ft_strlen(STR))
		STR = ft_pad_string(STR, ' ', WID, 1);
	return (1);
}
