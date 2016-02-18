/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:37:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 14:48:54 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strcpy' copies a 'C-string' into another one.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	char	*dst_save;

	dst_save = dst;
	while (1)
		if ((*dst++ = *src++) == '\0')
			return (dst_save);
}
