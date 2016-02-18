/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:20:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 20:26:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_a(int value, int base)
{
	char	*str;
	int		i;

	i = ft_maxintlen(sizeof(int), base);
	if ((i = ft_maxintlen(sizeof(int), base)) == 0 ||
	base > 36 || base < 2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	return (ft_itoa_c(value, str, base));
}
