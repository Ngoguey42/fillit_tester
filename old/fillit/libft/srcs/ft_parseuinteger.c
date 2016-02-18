/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseuinteger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 19:19:43 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 14:23:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_parseuinteger(char *str, size_t *uiptr)
{
	size_t	len;

	len = 0;
	*uiptr = 0;
	while (ft_isdigit(*str))
	{
		*uiptr *= 10;
		*uiptr += *str - '0';
		str++;
		len++;
	}
	return (len);
}
