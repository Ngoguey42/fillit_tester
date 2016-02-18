/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:20:54 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:23:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_c(int value, char *str, int base)
{
	char	*save;
	int		i;

	if (base > 36 || base < 2 || !(save = str))
		return (NULL);
	if (value < 0)
		*(str++) = '-';
	else if (value == 0)
		*(str++) = '0';
	i = 0;
	while (value != 0)
	{
		str[i++] = BASE_NBRS[ABS(value) % base];
		value /= base;
	}
	str[i] = '\0';
	ft_revstr(str);
	return (save);
}
