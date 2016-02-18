/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:46:55 by ngoguey           #+#    #+#             */
/*   Updated: 2015/02/03 11:22:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_memmove' copies the 'n' first bytes of 'source' to 'destination'.
** This function also handle overlap.
*/

void	*ft_memcpyhis(void *dst, const void *src, size_t len)
{
	void *tmp_dst;
	void *tmp_src;

	if (src == dst)
		return (dst);
	tmp_dst = dst;
	tmp_src = (void*)src;
	while (len >= sizeof(t_ui64))
	{
		*((t_ui64*)tmp_dst) = *((t_ui64*)tmp_src);
		tmp_dst += sizeof(t_ui64);
		tmp_src += sizeof(t_ui64);
		len -= sizeof(t_ui64);
	}
	while (len > 0)
	{
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		tmp_dst++;
		tmp_src++;
		len--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *tmp_dst;
	void *tmp_src;

	if (src >= dst)
		return (ft_memcpyhis(dst, src, len));
	tmp_dst = dst + len;
	tmp_src = ((void*)src) + len;
	while (len >= sizeof(t_ui64))
	{
		tmp_dst -= sizeof(t_ui64);
		tmp_src -= sizeof(t_ui64);
		*((t_ui64*)tmp_dst) = *((t_ui64*)tmp_src);
		len -= sizeof(t_ui64);
	}
	while (len > 0)
	{
		tmp_dst--;
		tmp_src--;
		*((t_byte*)tmp_dst) = *((t_byte*)tmp_src);
		len--;
	}
	return (dst);
}

void	*ft_memmovemine(void *dst, const void *src, size_t len)
{
	char		*dstc;
	const char	*srcc = (const char*)src;

	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		dstc = (char*)dst;
		while (len-- > 0)
			dstc[len] = (char)srcc[len];
	}
	return (dst);
}
