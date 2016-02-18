/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endianness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 15:03:34 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 15:32:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdbool.h>
#include "i386/endian.h"

uint16_t	ft_i16toh(uint16_t i, bool big_endian)
{
	if (BYTE_ORDER == LITTLE_ENDIAN)
	{
		if (big_endian)
			return ((i & 0xff00) >> 8 | (i & 0x00ff) << 8);
		else
			return (i);
	}
	if (big_endian)
		return (i);
	else
		return ((i & 0xff00) >> 8 | (i & 0x00ff) << 8);
}

uint32_t	ft_i32toh(uint32_t i, bool big_endian)
{
	if (BYTE_ORDER == LITTLE_ENDIAN)
	{
		if (big_endian)
			return (((i & 0xff000000) >> 24) | ((i & 0x00ff0000) >> 8) |
					((i & 0x0000ff00) << 8) | ((i & 0x000000ff) << 24));
		else
			return (i);
	}
	if (big_endian)
		return (i);
	else
		return (((i & 0xff000000) >> 24) | ((i & 0x00ff0000) >> 8) |
				((i & 0x0000ff00) << 8) | ((i & 0x000000ff) << 24));
}

uint64_t	ft_i64toh(uint64_t i, bool big_endian)
{
	if (BYTE_ORDER == LITTLE_ENDIAN)
	{
		if (big_endian)
			return (((i & 0xff00000000000000ULL) >> 56) |
					((i & 0x00ff000000000000ULL) >> 40) |
					((i & 0x0000ff0000000000ULL) >> 24) |
					((i & 0x000000ff00000000ULL) >> 8) |
					((i & 0x00000000ff000000ULL) << 8) |
					((i & 0x0000000000ff0000ULL) << 24) |
					((i & 0x000000000000ff00ULL) << 40) |
					((i & 0x00000000000000ffULL) << 56));
		else
			return (i);
	}
	if (big_endian)
		return (i);
	else
		return (((i & 0xff00000000000000ULL) >> 56) |
				((i & 0x00ff000000000000ULL) >> 40) |
				((i & 0x0000ff0000000000ULL) >> 24) |
				((i & 0x000000ff00000000ULL) >> 8) |
				((i & 0x00000000ff000000ULL) << 8) |
				((i & 0x0000000000ff0000ULL) << 24) |
				((i & 0x000000000000ff00ULL) << 40) |
				((i & 0x00000000000000ffULL) << 56));
}
