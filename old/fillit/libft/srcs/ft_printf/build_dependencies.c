/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_dependencies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:38:03 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:03:38 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 'apply_width_integer_pad' applies padding according to 'width'.
*/

void	apply_width_integer_pad(t_printf_part *part, char **sp, int l, int w)
{
	if (w < 0 && ABS(w) > l)
		*sp = ft_pad_string(*sp, ' ', w, 1);
	else if (AND_F(MINU_MASK) && w > l)
		*sp = ft_pad_string(*sp, ' ', -w, 1);
	else if (w > l)
		*sp = ft_pad_string(*sp, ' ', w, 1);
}
