/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:03:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/12 10:13:01 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isdigit_base' identifies an ascii digit 'char' based on its base.
*/

int	ft_isdigit_base(int c, int base)
{
	if (ft_isdigit(c) && (c - '0') < base)
		return (1);
	if (ft_islower(c) && (c - 'a' + 10) < base)
		return (1);
	if (ft_isupper(c) && (c - 'A' + 10) < base)
		return (1);
	return (0);
}
