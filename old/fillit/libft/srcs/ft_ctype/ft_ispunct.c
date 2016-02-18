/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:54:51 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:23:09 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_ispunct' identifies an ascii punctuation 'char'.
*/

int	ft_ispunct(int c)
{
	return ((c > ' ' && c <= '~' && !ft_isalnum(c)) * 16);
}
