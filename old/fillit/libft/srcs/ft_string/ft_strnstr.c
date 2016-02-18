/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:20:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 12:05:41 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strnstr' locates a 'C-string' occurence the first 'n' chars of another
** one.
*/

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	s2len;

	len = ft_strlen(s1);
	len = (n < len) ? n : len;
	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char*)s1);
	while (len && len-- >= s2len)
	{
		if (!ft_strncmp(s1, s2, s2len))
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
