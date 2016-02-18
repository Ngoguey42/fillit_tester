/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:08:08 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 14:16:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strequ' compares two 'C-strings'.
*/

int	ft_strequ(char const *s1, char const *s2)
{
	return (!ft_strcmp(s1, s2));
}
