/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:26:04 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:48:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strncpy' copies a 'C-string' into another one, until 'num' chars are
** copied.
** The second loop fills 'dst's trailing 'chars' to '\0'.
*/

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *s;

	s = dst;
	while (n > 0 && *src)
	{
		*s++ = *src++;
		n--;
	}
	while (n-- > 0)
		*s++ = '\0';
	return (dst);
}
