/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:42:41 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 11:25:53 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_memcmp' looks for differences between two memory zones.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_byte	*s1b = (t_byte*)s1;
	const t_byte	*s2b = (t_byte*)s2;

	while (n > 0)
	{
		if (*s1b != *s2b)
			return (*s1b - *s2b);
		s1b++;
		s2b++;
		n--;
	}
	return (0);
}
