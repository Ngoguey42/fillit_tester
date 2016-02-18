/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:42:27 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:29:34 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_memchr' looks for a value in a memory zone.
** 'c' is treated as an 'unsigned char'.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte			tofind;
	const t_byte	*p = (const t_byte*)s;

	tofind = (t_byte)c;
	while (n--)
	{
		if (*p == tofind)
			return ((void*)p);
		p++;
	}
	return (NULL);
}
