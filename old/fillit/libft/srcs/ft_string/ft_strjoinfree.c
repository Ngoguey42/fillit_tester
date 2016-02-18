/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:15:47 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:30:59 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2)
{
	char	*ret;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char*)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	if (s1 == s2 && (frees1 || frees2))
	{
		free(s1);
		return (ret);
	}
	if (frees1)
		free(s1);
	if (frees2)
		free(s2);
	return (ret);
}
