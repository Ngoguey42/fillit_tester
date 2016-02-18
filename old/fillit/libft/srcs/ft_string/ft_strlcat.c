/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:08:38 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:41:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strlcat' concatenates two 'C-strings' and guarantee to NUL-terminate the
** result.
** Returns 'src_len' plus 'dst_len'.
** If 'dst' wasn't fully copied, returns 'src_len' plus 'size' instead.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	ret;

	dst_len = ft_strlen(dst);
	ret = ft_strlen(src) + (size < dst_len ? size : dst_len);
	dst += dst_len;
	while ((dst_len++ + 1) < size && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
