/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:34:43 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/03 19:34:46 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcharlen(const char *str, const char delim)
{
	const char *eos;

	eos = str;
	while (*eos != '\0' && *eos != delim)
		eos++;
	return (eos - str);
}
