/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:47:14 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 14:07:40 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ISIZE sizeof(int)
#define IMASK (ISIZE - 1)

/*
** 'ft_memset' sets every 'bytes' of a memory zone to 'c'.
** The first loop sets ISIZE bytes at a time.
** The second loop deals with trailing bytes.
** 'ft_memcset' returns the following pointer.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			t;
	unsigned int	ci;
	unsigned char	cc;
	unsigned int	*b_ip;
	unsigned char	*b_cp;

	cc = (unsigned char)c;
	if ((ci = (unsigned int)cc) != 0)
	{
		ci = (ci << 8) | ci;
		ci = (ci << 16) | ci;
	}
	b_ip = (unsigned int*)b;
	t = len / ISIZE;
	while (t--)
		*b_ip++ = ci;
	b_cp = (unsigned char*)b_ip;
	t = len % ISIZE;
	while (t--)
		*b_cp++ = cc;
	return (b);
}

void	*ft_memcset(void *b, int c, size_t len)
{
	size_t			t;
	unsigned int	ci;
	unsigned char	cc;
	unsigned int	*b_ip;
	unsigned char	*b_cp;

	cc = (unsigned char)c;
	if ((ci = (unsigned int)cc) != 0)
	{
		ci = (ci << 8) | ci;
		ci = (ci << 16) | ci;
	}
	b_ip = (unsigned int*)b;
	t = len / ISIZE;
	while (t--)
		*b_ip++ = ci;
	b_cp = (unsigned char*)b_ip;
	t = len % ISIZE;
	while (t--)
		*b_cp++ = cc;
	return (b + len);
}
