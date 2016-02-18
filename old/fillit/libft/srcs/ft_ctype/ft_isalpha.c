/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:02:17 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 09:52:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_isalpha" identifies an ascii alphabetical 'char'.
*/

int	ft_isalpha(int c)
{
	if (ft_islower(c))
		return (2);
	return (ft_isupper(c));
}
