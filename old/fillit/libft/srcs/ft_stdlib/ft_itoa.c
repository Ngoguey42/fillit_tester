/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:12:05 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 13:39:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_itoa' converts a 'signed base 10 integer' to a 'C-string'.
** An optional negative sign if first written, then the number is writen
** backward and the string reversed afterward. This way the function also
** handles the INT_MIN value.
*/

char	*ft_itoa(int n)
{
	return (ft_itoa_a(n, 10));
}
