/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlentype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:42:47 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/05 15:48:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t				ft_strlentype(char const *str, int (*typefun)(int c))
{
	size_t	len;

	len = 0;
	while (typefun(*str++))
		len++;
	return (len);
}
