/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:40:30 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:23:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lutoa(t_ui64 value, char *str, int base)
{
	char	*save;
	int		i;

	if (base > 36 || base < 2 || !(save = str))
		return (NULL);
	if (value == 0)
		*(str++) = '0';
	i = 0;
	while (value != 0)
	{
		str[i++] = BASE_NBRS[value % base];
		value /= base;
	}
	str[i] = '\0';
	ft_revstr(str);
	return (save);
}
