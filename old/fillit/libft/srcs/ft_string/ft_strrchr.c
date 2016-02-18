/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:03 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 12:08:49 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strchr' parses a 'C-string' looking for the last occurence of a specific
** value.
** 'c' is treated as a 'char'.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	tofind;
	char	*pos;

	tofind = (char)c;
	pos = NULL;
	while (1)
	{
		if (*s == tofind)
			pos = (char*)s;
		if (*s++ == '\0')
			return (pos);
	}
}
