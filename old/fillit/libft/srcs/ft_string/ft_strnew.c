/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:26:27 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 14:37:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strnew' allocates a string with a given size, an sets every chars to 0.
*/

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(sizeof(char) * (size + 1)));
}
