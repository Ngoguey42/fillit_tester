/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:03:43 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:20:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isgraph' identifies an ascii graphical 'char'
*/

int	ft_isgraph(int c)
{
	if (c > ' ' && c <= '~')
		return ((c = ft_isalnum(c)) ? c : 16);
	return (0);
}
