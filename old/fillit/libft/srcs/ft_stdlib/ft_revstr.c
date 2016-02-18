/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:34:10 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 13:41:56 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_revstr' reverses a 'C-string'.
*/

char	*ft_revstr(char *str)
{
	size_t	i;
	char	c;
	char	*save;

	save = str;
	i = ft_strlen(str);
	while (i >= 2)
	{
		c = *str;
		*str = str[i - 1];
		str[i - 1] = c;
		str++;
		i -= 2;
	}
	return (save);
}
