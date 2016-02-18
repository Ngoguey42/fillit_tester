/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:00:37 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:03:23 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define NOBI(NAME) char	*NAME
#define NORMBITCH(N1, N2, N3) NOBI(N1); NOBI(N2); NOBI(N3)

/*
** (n < 0) pad right
** (n > 0) pad left
** Undefined if |n| < ft_strlen(str)
*/

char	*ft_pad_string(char *str, char c, int n, int freestr)
{
	NORMBITCH(ret, rets, strs);
	if (!(ret = (char*)malloc(ABS(n) + 1)))
		return (NULL);
	n += n < 0 ? ft_strlen(str) : -ft_strlen(str);
	rets = ret;
	if (n > 0)
	{
		while (n--)
			*ret++ = c;
		n = 0;
	}
	strs = str;
	while (*str)
		*ret++ = *str++;
	if (n < 0)
	{
		while (n++)
			*ret++ = c;
	}
	*ret = '\0';
	if (freestr)
		free(strs);
	return (rets);
}
