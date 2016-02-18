/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:09:03 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:21:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isxdigit' identifies an ascii hexadecimal digit 'char'.
*/

int	ft_isxdigit(int c)
{
	if (ft_isdigit(c))
		return (4);
	return (((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) * 64);
}
