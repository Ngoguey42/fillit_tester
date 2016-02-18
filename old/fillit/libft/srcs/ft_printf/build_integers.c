/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_integers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:38:25 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:04:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define STR_EMPTY (nbr == 0 && AND_I(PNUM_MASK) && precision == 0)

#define INT_HAS_PREFIX (nbr < 0 || AND_F(PLUS_MASK) || AND_F(SPAC_MASK))
#define INT_LEN_PLUS_PREFIX ((int)ft_strlen(str) + (INT_HAS_PREFIX ? 1 : 0))

#define OCT_HAS_PREFIX ((AND_F(HASH_MASK)) && nbr != 0)
#define OCT_LEN_PLUS_PREFIX ((int)ft_strlen(str) + (OCT_HAS_PREFIX ? 1 : 0))

#define HEX_HAS_PREFIX (AND_F(HASH_MASK) && nbr != 0)
#define HEX_LEN_PLUS_PREFIX ((int)ft_strlen(str) + (HEX_HAS_PREFIX ? 2 : 0))

/*
** 'build_nbr_1' %d %i.
** 'build_nbr_3' %u.
** 'build_nbr_4' %o.
** 'build_nbr_5' %x.
** 'build_nbr_17' %p.
*/

int		build_nbr_1(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_i64	nbr;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = get_signed_varg(part->length, args);
	str = STR_EMPTY ? (char*)ft_strdup("") : ft_lutoa_a(ABS(nbr), 10);
	if (precision > 0 && precision > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', precision, 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > INT_LEN_PLUS_PREFIX)
		str = ft_pad_string(str, '0', width - (INT_HAS_PREFIX ? 1 : 0), 1);
	if (nbr < 0)
		str = ft_pad_string(str, '-', (int)ft_strlen(str) + 1, 1);
	else if (AND_F(PLUS_MASK) || AND_F(SPAC_MASK))
		str = ft_pad_string(str, AND_F(PLUS_MASK) ? '+' : ' ',
			(int)ft_strlen(str) + 1, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}

int		build_nbr_3(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_ui64	nbr;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = get_unsigned_varg(part->length, args);
	str = STR_EMPTY ? (char*)ft_strdup("") : ft_lutoa_a(nbr, 10);
	if (precision > 0 && precision > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', precision, 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', width, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}

int		build_nbr_4(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_ui64	nbr;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = get_unsigned_varg(part->length, args);
	str = (nbr == 0 && precision == 0 && AND_I(PNUM_MASK) && width != 0 &&
		!AND_F(HASH_MASK)) ? (char*)ft_strdup("") : ft_lutoa_a(nbr, 8);
	if (precision > 0 && precision > OCT_LEN_PLUS_PREFIX)
		str = ft_pad_string(str, '0', precision - (OCT_HAS_PREFIX ? 1 : 0), 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > OCT_LEN_PLUS_PREFIX)
		str = ft_pad_string(str, '0', width - (OCT_HAS_PREFIX ? 1 : 0), 1);
	if (OCT_HAS_PREFIX)
		str = (char*)ft_strjoinfree("0", str, 0, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}

int		build_nbr_5(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_ui64	nbr;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = get_unsigned_varg(part->length, args);
	str = STR_EMPTY ? (char*)ft_strdup("") : ft_lutoa_a(nbr, 16);
	if (precision > 0 && precision > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', precision, 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > HEX_LEN_PLUS_PREFIX)
		str = ft_pad_string(str, '0', width - (HEX_HAS_PREFIX ? 2 : 0), 1);
	if (HEX_HAS_PREFIX)
		str = (char*)ft_strjoinfree("0x", str, 0, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}

int		build_nbr_17(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_ui64	nbr;
	char	*str;

	part->flags = part->flags | HASH_MASK;
	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = sizeof(void*) == 8 ? (t_ui64)va_arg(*args, t_ui64) :
		(t_ui32)va_arg(*args, t_ui32);
	str = STR_EMPTY ? (char*)ft_strdup("") : ft_lutoa_a(nbr, 16);
	if (precision > 0 && precision > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', precision, 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > ((int)ft_strlen(str) + 2))
		str = ft_pad_string(str, '0', width - 2, 1);
	str = (char*)ft_strjoinfree("0x", str, 0, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}
