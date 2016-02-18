/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:44:54 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 12:13:25 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_memccpy' copies bytes until a certain char is reached.
** 'c' is treated as un 'unsigned char'.
** A pointer to the subsequent 'byte' in 'dst' is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_byte			tofind;
	t_byte			*dstp;
	const t_byte	*srcp = (t_byte*)src;

	tofind = (t_byte)c;
	dstp = (t_byte*)dst;
	while (n--)
	{
		*dstp++ = *srcp;
		if (*srcp == tofind)
			return ((void*)dstp);
		srcp++;
	}
	return (NULL);
}
