/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dec_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:18:53 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:03:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define WID part->width
#define PRE part->precision

#define DEC_HAS_PREFIX (type % 2 == 0 || AND_F(PLUS_MASK) || AND_F(SPAC_MASK))
#define DEC_LEN_PLUS_PREFIX (ft_strlen(str) + (DEC_HAS_PREFIX   ? 1 : 0))

static char		*build_zero(t_printf_part *part)
{
	char	*str;

	if (PRE == 0 && AND_F(HASH_MASK))
		str = ft_strdup("0.");
	else if (PRE > 0)
		str = ft_pad_string("0.", '0', -(PRE + 2), 0);
	else
		str = ft_strdup("0");
	return (str);
}

static char		*build_float(double nbr, t_printf_part *part, int type)
{
	char	*str;

	if (type >= 9)
		str = ft_strdup("nan");
	else if (type >= 7)
		str = ft_strdup("inf");
	else if (type >= 5 || (type >= 3 && PRE < 308))
		str = build_zero(part);
	else
		str = ptf_build_decnbr(nbr, part);
	if (type <= 6 && AND_F(ZERO_MASK) && !AND_F(MINU_MASK) &&
		WID > (int)(DEC_LEN_PLUS_PREFIX))
		str = ft_pad_string(str, '0', WID - (DEC_HAS_PREFIX ? 1 : 0), 1);
	if ((type % 2) == 0 && type != 10)
		str = (char*)ft_strjoinfree("-", str, 0, 1);
	else if (type <= 8 && (AND_F(PLUS_MASK) || AND_F(SPAC_MASK)))
		str = (char*)ft_strjoinfree(AND_F(PLUS_MASK) ? "+" : " ", str, 0, 1);
	return (str);
}

int				build_nbr_7(t_printf_part *part, va_list *args)
{
	double	nbr;
	char	*str;

	WID = AND_I(WSTA_MASK) ? va_arg(*args, int) : WID;
	PRE = AND_I(PSTA_MASK) ? va_arg(*args, int) : PRE;
	if (!AND_I(PNUM_MASK) || PRE < 0)
		PRE = 6;
	nbr = va_arg(*args, double);
	str = build_float(nbr, part, ft_dbltype(nbr));
	if (WID > 0 && WID > (int)ft_strlen(str))
	{
		if (part->flags & MINU_MASK)
			str = ft_pad_string(str, ' ', -WID, 1);
		else
			str = ft_pad_string(str, ' ', WID, 1);
	}
	else if (WID < 0 && ABS(WID) > (int)ft_strlen(str))
		str = ft_pad_string(str, ' ', WID, 1);
	part->nbr_ptr = str;
	return (1);
}
