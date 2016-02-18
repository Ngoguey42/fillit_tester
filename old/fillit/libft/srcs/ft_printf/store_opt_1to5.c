/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_opt_1to5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:33:57 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 18:34:00 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** Options to store
** 0	none			store_opt_1
** 1	percent			store_opt_1
** 2	flags			store_opt_2
** 3	width			store_opt_3
** 4	dot				store_opt_1
** 5	precision		store_opt_5
*/

int	store_opt_1(char c, t_printf_part *part)
{
	(void)c;
	(void)part;
	return (1);
}

int	store_opt_2(char c, t_printf_part *part)
{
	t_byte	bit;

	bit = (t_byte)ft_strcharlen(CHARS_FLAGS, c);
	part->flags = part->flags | (1 << bit);
	return (1);
}

int	store_opt_3(char c, t_printf_part *part)
{
	if (AND_I(WSTA_MASK) || (c == '*' && part->width > 0))
		return (0);
	if (c == '*')
		part->info = part->info | WSTA_MASK;
	else
		part->width = part->width * 10 + c - '0';
	return (1);
}

int	store_opt_5(char c, t_printf_part *part)
{
	if (AND_I(PSTA_MASK) || (c == '*' && part->precision > 0))
		return (0);
	if (c == '*')
		part->info = part->info | PSTA_MASK;
	else
		part->precision = part->precision * 10 + c - '0';
	part->info = part->info | PNUM_MASK;
	return (1);
}
