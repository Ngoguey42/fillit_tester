/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:16:41 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 14:31:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strequ' compares two 'C-strings', or until 'n' chars a compared.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return (!ft_strncmp(s1, s2, n));
}
