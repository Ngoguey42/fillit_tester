/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_chars_and_strings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:33:52 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:04:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define WID part->width
#define STR part->nbr_ptr
#define PRE part->precision

/*
** 'build_nbr_15' %c.
** 'build_nbr_16' %s.
** 'build_nbr_19' %%.
*/
/*
** %c
** if (c == '\0')
** (1) convert '\0' to '\1' and remember it in unused int precision;
** (2) deal with Width;
** (3) save strlen;
** (4) convert '\1' back to '\0'
*/

int		build_nbr_15(t_printf_part *part, va_list *args)
{
	char	c;

	if (part->length > 0 && CHARS_LENGTH[part->length - 1] == 'l')
		return (build_nbr_25(part, args));
	part->width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	c = (char)va_arg(*args, int);
	PRE = c == 0 ? 1 : 0;
	if (!(STR = ft_strnew(1)))
		return (0);
	STR[0] = PRE ? 1 : c;
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
	if (PRE)
		STR[ft_strcharlen(STR, '\1')] = '\0';
	return (1);
}

int		build_nbr_16(t_printf_part *part, va_list *args)
{
	int		width;

	if (part->length > 0 && CHARS_LENGTH[part->length - 1] == 'l')
		return (build_nbr_26(part, args));
	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	STR = (char*)va_arg(*args, char*);
	STR = (STR == NULL) ? ft_strdup("(null)") : ft_strdup(STR);
	if (AND_I(PNUM_MASK) && PRE >= 0 && PRE < (int)ft_strlen(STR))
		STR[PRE] = '\0';
	if (width > 0 && width > (int)ft_strlen(STR))
	{
		if (AND_F(MINU_MASK))
			STR = ft_pad_string(STR, ' ', -width, 1);
		else
			STR = ft_pad_string(STR, PAD_CHAR, width, 1);
	}
	else if (width < 0 && ABS(width) > (int)ft_strlen(STR))
		STR = ft_pad_string(STR, ' ', width, 1);
	return (1);
}

int		build_nbr_19(t_printf_part *part, va_list *args)
{
	int		width;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	(void)PRE;
	if (width > 1)
	{
		if (AND_F(MINU_MASK))
			STR = ft_pad_string("%", ' ', -width, 0);
		else
			STR = ft_pad_string("%", PAD_CHAR, width, 0);
	}
	else if (width < -1)
		STR = ft_pad_string("%", ' ', width, 0);
	else
		STR = (char*)ft_strdup("%");
	return (1);
}
