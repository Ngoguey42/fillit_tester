/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:02:01 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:13:39 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isalnum' identifies an ascii alphanumeric 'char'.
*/

int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (4);
	return (ft_isalpha(c));
}
