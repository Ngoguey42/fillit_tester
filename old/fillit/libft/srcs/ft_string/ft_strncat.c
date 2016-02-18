/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:25:37 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 13:11:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_strncat' copies 'n' characters from a 'C-string' to another.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	ft_strlcpy(s1 + ft_strlen(s1), s2, n + 1);
	return (s1);
}
