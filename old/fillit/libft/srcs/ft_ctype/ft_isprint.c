/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:26:25 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:19:56 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isprint' idenfities an ascii printable 'char'.
*/

int	ft_isprint(int c)
{
	if (c == ' ')
		return (128);
	return (ft_isgraph(c));
}
