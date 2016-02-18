/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:20:38 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 12:15:34 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strchr' parses a 'string' looking for a specific value.
** 'c' is treated as a 'char'.
*/

char	*ft_strchr(const char *s, int c)
{
	char	tofind;

	tofind = (char)c;
	while (*s != tofind)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char*)s);
}
