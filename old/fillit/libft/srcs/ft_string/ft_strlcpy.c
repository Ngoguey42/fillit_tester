/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:06:45 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:41:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strlcpy' copies a 'C-string' into another one, until 'size' chars are
** copied and guarantee to NUL-terminate the result.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	while (size > 1 && *src)
	{
		*dst++ = *src++;
		size--;
	}
	if (size >= 1)
		*dst = '\0';
	return (len);
}
