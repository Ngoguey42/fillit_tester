/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:34:49 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/05 14:10:57 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define TAG_ST g_color_flags[2 * i - FIRT_C_FLAG_ID * 2]
#define TAG_EN g_color_flags[2 * i - FIRT_C_FLAG_ID * 2 + 1]

/*
** 'g_color_flags' contains color flags.
*/
/*
** 'add_color_flag' adds color flags to %subsitutions strings.
*/

char const	g_color_flags[][11] = {
	":blu::MAG:", ":eob::eoc:",
	":mag::CYA:", ":eob::eoc:",
	":whi::BLU:", ":eob::eoc:",
	":bla::GRE:", ":eob::eoc:",
	":red::YEL:", ":eob::eoc:",
	":cya::RED:", ":eob::eoc:",
	":und:", ":eou:",
};

int	add_color_flag(t_printf_part *p)
{
	int				i;
	TYPE_OF_FLAGS	f;
	char			*s;
	size_t			si;

	i = SIZE_OF_FLAGS;
	f = 0x1 << (i - 1);
	while (--i >= FIRT_C_FLAG_ID)
	{
		if (i <= FIRT_C_FLAG_ID + NUM_COLOR_FLAGS - 1 && p->flags & f)
		{
			si = p->nbr_size > 0 ? (t_ui32)p->nbr_size : ft_strlen(p->nbr_ptr);
			if ((s = (char*)ft_memalloc(sizeof(char) * (si + 21))) == NULL)
				return (0);
			ft_strcpy(s, TAG_ST);
			ft_memcpy((void*)(s + ft_strlen(s)), p->nbr_ptr, si);
			ft_strcpy(s + ft_strlen(TAG_ST) + si, TAG_EN);
			p->nbr_size = si > 0 ?
			si + ft_strlen(TAG_ST) + ft_strlen(TAG_EN) : (t_ui32)p->nbr_size;
			free(p->nbr_ptr);
			p->nbr_ptr = s;
		}
		f >>= 1;
	}
	return (1);
}
