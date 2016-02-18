/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:33 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:55:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strnstr' locates a 'C-string' occurence in another one.
*/

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;

	if ((len = ft_strlen(s2)) > 0)
		while (ft_strncmp(s1, s2, len))
			if (!*s1++)
				return (NULL);
	return ((char*)s1);
}
