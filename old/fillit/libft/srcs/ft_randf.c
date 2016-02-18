/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:09:36 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:09:37 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define PRECISION 1000000
#define PRECISIONF ((float)PRECISION)

float			ft_randf01(void)
{
	return ((float)(rand() % PRECISION) / (PRECISIONF - 1.f));
}

float			ft_randf0(void)
{
	return ((float)(rand() % PRECISION) / (PRECISIONF - 1.f) - 0.5f);
}
