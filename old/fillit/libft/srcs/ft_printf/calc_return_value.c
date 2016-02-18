/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_return_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:14:36 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:43:52 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 'subpart_len' calculates the string's length with color escape codes.
** 'final_string_size' calculates the printf return value and string length.
*/

static int	subpart_len(const char *str, size_t len)
{
	int	i;
	int	j;

	i = len;
	while (i-- > 4)
	{
		if (*str == ':' && str[4] == ':' &&
			(j = coi(str)) < NUM_C_TAGS * 2)
		{
			len += (j < NUM_SMALLC_TAGS * 2) ? -1 : 0;
			str += 4;
			i -= 4;
		}
		str++;
	}
	return (len);
}

int			final_string_size(t_printf_part *current)
{
	size_t	len;

	len = 0;
	while (current)
	{
		if (current->nbr_size < 0)
			current->nbr_size = ft_strlen(current->nbr_ptr);
		len += subpart_len(current->str_ptr, current->str_size);
		len += subpart_len(current->nbr_ptr, current->nbr_size);
		current = current->next;
	}
	return (len);
}
