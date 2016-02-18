/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_bonuses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:32:41 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 12:33:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define STR_EMPTY (nbr == 0 && AND_I(PNUM_MASK) && precision == 0)

#define BIN_HAS_PREFIX (AND_F(HASH_MASK) && nbr != 0)
#define BIN_LEN_PLUS_PREFIX ((int)ft_strlen(str) + (BIN_HAS_PREFIX ? 2 : 0))

/*
** 'build_nbr_20' %b bits.
*/

int		build_nbr_20(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	t_ui64	nbr;
	char	*str;

	width = AND_I(WSTA_MASK) ? va_arg(*args, int) : part->width;
	precision = AND_I(PSTA_MASK) ? va_arg(*args, int) : part->precision;
	nbr = get_unsigned_varg(part->length, args);
	str = STR_EMPTY ? (char*)ft_strdup("") : ft_lutoa_a(nbr, 2);
	if (precision > 0 && precision > (int)ft_strlen(str))
		str = ft_pad_string(str, '0', precision, 1);
	else if ((!AND_I(PNUM_MASK) || precision < 0) && AND_F(ZERO_MASK) &&
	!AND_F(MINU_MASK) && width > BIN_LEN_PLUS_PREFIX)
		str = ft_pad_string(str, '0', width - (BIN_HAS_PREFIX ? 2 : 0), 1);
	if (BIN_HAS_PREFIX)
		str = (char*)ft_strjoinfree("0b", str, 0, 1);
	apply_width_integer_pad(part, &str, (int)ft_strlen(str), width);
	part->nbr_ptr = str;
	return (1);
}
