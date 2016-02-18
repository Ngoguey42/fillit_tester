/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbltype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:59:03 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:06:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_dbltype.h"

/*
**	+norm	1
**	-norm	2
**	+denorm	3
**	-denorm	4
**	+zero	5
**	-zero	6
**	+inf	7
**	-inf	8
**	nan		9
**	qnan	10
*/

#define INF_NAN_EXP			0x7FF
#define INF_HMANT			0x0
#define INF_LMANT			0x0
#define ZERO_DENORM_EXP		0x0
#define ZERO_HMANT			0x0
#define ZERO_LMANT			0x0

int	ft_dbltype(double nbr)
{
	t_dbl_extract		extract;
	t_nan_dbl_extract	extractnan;

	extract.s.sig = 0;
	extractnan.s.nan = 0;
	extract.d = nbr;
	if (extract.s.exp == INF_NAN_EXP)
	{
		if (extract.s.manh == INF_HMANT && extract.s.manl == INF_LMANT)
			return (7 + extract.s.sig);
		else
		{
			extractnan.d = nbr;
			(void)extractnan;
			return (9 + extractnan.s.nan);
		}
	}
	if (extract.s.exp == ZERO_DENORM_EXP)
	{
		if (extract.s.manh == ZERO_HMANT && extract.s.manl == ZERO_LMANT)
			return (5 + extract.s.sig);
		else
			return (3 + extract.s.sig);
	}
	return (1 + extract.s.sig);
}
