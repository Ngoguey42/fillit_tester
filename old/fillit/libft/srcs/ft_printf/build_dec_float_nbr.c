/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dec_float_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:44:19 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:04:09 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "math.h"

#define PRE part->precision

static char		*build_intpart(double nbr, int *round, int i)
{
	int		exp;
	char	*str;
	char	*save;
	double	lol;
	double	tmp;

	if (nbr < 1)
		return (ft_strdup("0"));
	exp = (int)ft_ceil(ft_log10(nbr));
	i = 0;
	lol = 1;
	while (i++ < (exp - 1))
		lol *= 10;
	str = (char*)malloc((exp + 1) * sizeof(char));
	save = str;
	while (exp--)
	{
		tmp = ft_floor(nbr / lol);
		*str++ = (int)tmp + '0';
		nbr = nbr - tmp * lol;
		lol /= 10;
	}
	*round = nbr < 0.5 ? 0 : 1;
	*str = '\0';
	return (save);
}

static char		*build_decpart(double nbr, int pre, int *round)
{
	char	*str;
	char	*save;
	double	div;
	double	tmp;

	str = (char*)malloc((pre + 1) * sizeof(char));
	div = 1;
	save = str;
	nbr -= ft_floor(nbr);
	while (pre--)
	{
		div /= 10;
		tmp = ft_floor(nbr / div);
		*str++ = (int)tmp + '0';
		nbr = nbr - tmp * div;
	}
	*round = (nbr / div) < 0.5 ? 0 : 1;
	*str = '\0';
	return (save);
}

char			*ptf_build_decnbr(double nbr, t_printf_part *part)
{
	char	*str;
	int		round;

	round = 0;
	str = build_intpart(ABS(nbr), &round, 0);
	if (PRE > 0)
	{
		str = ft_strjoinfree(str, ".", 1, 0);
		str = ft_strjoinfree(str, build_decpart(ABS(nbr), PRE, &round), 1, 1);
	}
	if (round)
		ft_roundup_b10(str);
	return (str);
}
