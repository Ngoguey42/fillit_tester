/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:56:34 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:23:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Skip spaces
**	Consider sign +/-
**	Skip 0x or 0b header for base 16 & 2
**	Save digits while isdigit_base(*str, base)
*/

int	ft_atoi_base(const char *str, int base)
{
	int		sign;
	int		total;

	if (!str || base < 2 || base > 36)
		return (0);
	total = 0;
	while (ft_isspace(*str))
		str++;
	sign = *str == '-' ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str : str - 1;
	if (str[1] == '0' && ((base == 2 && str[2] == 'b')
			|| (base == 16 && str[2] == 'x')))
		str = str + 2;
	while (ft_isdigit_base(*++str, base))
		total = total * base + *str - '0';
	return (total * sign);
}
