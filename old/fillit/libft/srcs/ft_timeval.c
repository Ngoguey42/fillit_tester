/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeval.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 13:58:49 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/10 13:59:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_timeval.h"
#include <stddef.h>

struct timeval			ft_timeval_diff(struct timeval x, struct timeval y)
{
	int		nsec;

	if (x.tv_usec < y.tv_usec)
	{
		nsec = (y.tv_usec - x.tv_usec) / 1000000 + 1;
		y.tv_usec -= 1000000 * nsec;
		y.tv_sec += nsec;
	}
	if (x.tv_usec - y.tv_usec > 1000000)
	{
		nsec = (x.tv_usec - y.tv_usec) / 1000000;
		y.tv_usec += 1000000 * nsec;
		y.tv_sec -= nsec;
	}
	return ((struct timeval){x.tv_sec - y.tv_sec, x.tv_usec - y.tv_usec});
}

double					ft_timeval_tosec(struct timeval t)
{
	return ((double)t.tv_usec / 1000000.f + (double)t.tv_sec);
}

double					ft_timeval_elapsed(struct timeval old)
{
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	return (ft_timeval_tosec(ft_timeval_diff(cur, old)));
}
