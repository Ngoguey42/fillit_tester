/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:11:32 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 14:28:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_strjoin' concatenates two 'C-strings' into a new one.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	if (s2)
		len += ft_strlen(s2);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s1)
		ret = ft_strcpy(ret, s1);
	if (s2)
		ret = ft_strcat(ret, s2);
	ret[len] = '\0';
	return (ret);
}
