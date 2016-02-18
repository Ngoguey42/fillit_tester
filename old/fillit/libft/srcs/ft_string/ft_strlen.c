/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:06:35 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 11:42:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strlen' calculates the length of a given 'C-string'.
*/

size_t	ft_strlen(const char *s)
{
	const char *eos;

	eos = s;
	while (*eos)
		eos++;
	return (eos - s);
}
