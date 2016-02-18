/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_uppercases2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 12:17:06 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/09 12:17:07 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 'build_nbr_22' %D
** 'build_nbr_23' %U
** 'build_nbr_24' %O
*/

int		build_nbr_22(t_printf_part *part, va_list *args)
{
	part->length = 6;
	return (build_nbr_1(part, args));
}

int		build_nbr_23(t_printf_part *part, va_list *args)
{
	part->length = 6;
	return (build_nbr_3(part, args));
}

int		build_nbr_24(t_printf_part *part, va_list *args)
{
	part->length = 6;
	return (build_nbr_4(part, args));
}
