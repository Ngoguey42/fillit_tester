/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:27:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 15:40:51 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strspn' calculates the length of the initial portion of 's1r' consisting
** of chars contained in 's2r'.
*/

size_t	ft_strspn(const char *str1, const char *str2)
{
	const char *s1 = str1;
	const char *s2;

	while (*s1)
	{
		s2 = str2;
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == '\0')
				return (s1 - str1);
		}
		s1++;
	}
	return (s1 - str1);
}
