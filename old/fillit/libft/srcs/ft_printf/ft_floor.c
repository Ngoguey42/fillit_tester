/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:57:35 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:07:37 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define TWOFORTYTWO 0x1.0p+52
#define TWOSIXTYTWO 0x1.0p+64L

/*
**	+norm	1 	( >2^51 : x)( <1 : +0.1)(round)
**	-norm	2 	( <2^51 : x)( >-1 : -0.0)(round)
**	+denorm	3 	+1.0
**	-denorm	4 	-0.0
**	+zero	5 	x
**	-zero	6 	x
**	+inf	7 	x
**	-inf	8 	x
**	nan		9 	x
**	qnan	10 	x
*/

static double	round_mantissa(long double nb, int type)
{
	long double	nbround;

	if (type == 1)
	{
		nbround = (nb + TWOSIXTYTWO) - TWOSIXTYTWO;
		nbround = (nb - TWOSIXTYTWO) + TWOSIXTYTWO;
	}
	else
	{
		nbround = (nb - TWOSIXTYTWO) + TWOSIXTYTWO;
		nbround = (nb + TWOSIXTYTWO) - TWOSIXTYTWO;
	}
	if (nbround > nb)
		return ((double)(nbround) - 1);
	return ((double)nbround);
}

double			ft_floor(double nb)
{
	int		type;

	if (((type = ft_dbltype(nb)) == 4) || (type == 2 && nb > -1))
		return (-1.0);
	else if (type == 3 || (type == 1 && nb < 1))
		return (+0.0);
	else if (type <= 2 && ABS(nb) < TWOFORTYTWO)
		return (round_mantissa((long double)nb, type));
	else if (type <= 2)
		return (nb - 1);
	return (nb);
}
