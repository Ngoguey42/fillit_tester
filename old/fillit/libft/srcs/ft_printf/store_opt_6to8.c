/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_opt_6to8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:34:15 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 18:34:26 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Options to store
** 6	length			store_opt_6
** 7	length 2		store_opt_7
** 8	specifier		store_opt_8
*/

int	store_opt_6(char c, t_printf_part *part)
{
	part->length = ft_strcharlen(CHARS_LENGTH, c) + 1;
	return (1);
}

int	store_opt_7(char c, t_printf_part *part)
{
	t_byte	prev_len;
	size_t	const_len;

	if (part->length != ft_strcharlen(CHARS_LENGTH, c) + 1)
		return (0);
	prev_len = part->length;
	const_len = ft_strlen(CHARS_LENGTH);
	if (prev_len > const_len - NUM_DBL_CHAR_LEN)
		part->length = prev_len + NUM_DBL_CHAR_LEN;
	else
		return (0);
	return (1);
}

int	store_opt_8(char c, t_printf_part *part)
{
	part->specifier = ft_strcharlen(CHARS_SPECIFIERS, c) + 1;
	return (1);
}
