/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:56:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 09:46:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_atoi' translates a 'base 10 signed integer' inside a 'C-string'to an int.
** The function discards leading spaces and take an optional sign.
** Returns 0 if no integer is found.
** Behavior is undefined for numbers exceeding the 'int' capacity.
*/

int	ft_atoi(const char *str)
{
	int		sign;
	int		total;

	while (ft_isspace(*str))
		str++;
	sign = *str == '-' ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str : str - 1;
	total = 0;
	while (ft_isdigit(*++str))
		total = total * 10 + *str - '0';
	return (total * sign);
}
