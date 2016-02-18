/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:18:48 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:09:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "ft_dbltype.h"

/*
**	+0		/	-inf
**	-0		/	-inf
**	-inf	/	nan
**	+inf	/	+inf
**	+nan	/	nan
**	<0		/	nan
*/

/*
**	+norm	1 ret
**	-norm	2 nan	0
**	+denorm	3 ret
**	-denorm	4 nan	0
**	+zero	5 -inf
**	-zero	6 -inf	0
**	+inf	7 +inf
**	-inf	8 nan	0
**	nan		9 nan
**	qnan	10 nan
*/

#define QUOTIENT 0x1.a934f0979a372p+1

static int		denorm_retexp(t_ui64 nbr)
{
	int				i;
	unsigned char	*ptr;

	ptr = ((unsigned char*)&nbr) + 6;
	i = 51;
	while (i > 0)
	{
		if (*ptr & 0b00001000)
			return (i - 1074);
		i--;
		nbr = nbr << 1;
	}
	return (-1074);
}

static double	get_mant(double nb)
{
	double			mant;
	int				i;
	int				k;

	mant = 0.5;
	i = 51;
	k = 0;
	while ((nb *= nb) > 1 && (51 - k + i + 1) >= 0)
	{
		if (nb >= 2)
		{
			nb /= 2;
			if (!k)
				k = i;
			else
				((char*)&mant)[(51 - k + i + 1) / 8] |=
					(1 << ((51 - k + i + 1) % 8));
		}
		if (!k)
			mant /= 2;
		i--;
	}
	return (mant);
}

double			ft_log10(double nb)
{
	int				type;
	double			retexp;
	t_dbl_extract	ex;

	ex.s.exp = 0;
	if ((type = ft_dbltype(nb)) >= 5 && type <= 7)
		return ((type == 7) ? M_INFINITY : M_MINFINITY);
	else if (type >= 4 || type == 2)
		return (M_NAN);
	ex.d = nb;
	if (type == 1)
		retexp = (double)ex.s.exp - 1023;
	else
	{
		retexp = (double)denorm_retexp((t_ui64)ex.s.manl +
		(t_ui64)ex.s.manh * 0x100000000);
		ex.d *= 0x04000000;
		ex.d *= 0x04000000;
	}
	ex.s.exp = 0b01111111111;
	nb = ex.d;
	return (nb > 1 ? (get_mant(nb) + retexp) / QUOTIENT : retexp / QUOTIENT);
}
