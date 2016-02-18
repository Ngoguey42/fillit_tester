/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:41:46 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/01 11:26:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_maxintlen' returns the maximum length of an int for a
** given 'sizeof(int)' and 'base'.
** Length is rounded up for uncommon bases.
*/

int		ft_maxintlen(size_t sizeofint, int base)
{
	const int		base2_sizes[4] = {16, 32, 0, 64};
	const int		base8_sizes[4] = {6, 12, 0, 22};
	const int		base10_sizes[4] = {6, 11, 0, 20};
	const int		base16_sizes[4] = {5, 9, 0, 17};
	const int		base36_sizes[4] = {4, 7, 0, 14};

	if (base > 36 || base < 2 || sizeofint < 2 || sizeofint > 8)
		return (0);
	if (base < 8)
		return (base2_sizes[sizeofint / 2 - 1]);
	if (base < 10)
		return (base8_sizes[sizeofint / 2 - 1]);
	if (base < 16)
		return (base10_sizes[sizeofint / 2 - 1]);
	if (base < 36)
		return (base16_sizes[sizeofint / 2 - 1]);
	return (base36_sizes[sizeofint / 2 - 1]);
}
