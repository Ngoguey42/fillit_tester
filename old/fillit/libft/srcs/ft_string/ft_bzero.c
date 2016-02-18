/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:57:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 11:16:58 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_bzero' sets every 'bytes' of a memory zone to 0.
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
