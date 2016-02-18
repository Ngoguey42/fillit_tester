/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:40:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:41:12 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_lutoa_a(t_ui64 value, int base)
{
	char	*str;
	int		i;

	if ((i = ft_maxintlen(sizeof(t_ui64), base)) == 0 ||
	base > 36 || base < 2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	return (ft_lutoa(value, str, base));
}
