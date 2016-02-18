/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:17:15 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 11:56:45 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ==================> PRINTF HEART <================== **
*/

/*
** 'concat_parts' concatenates all 't_printf_part' together.
** 'build_specifiers' builds %substitutions.
** 'ft_getprintf' is the function called by every vprintf functions.
*/

int			build_nbr_0(t_printf_part *part, va_list *args)
{
	(void)part;
	(void)args;
	return (1);
}

static int	concat_parts(t_printf_part **beginning, char **ret)
{
	t_printf_part	*current;
	size_t			len;

	current = *beginning;
	len = final_string_size(current);
	if (!(*ret = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (-1);
	string_cat(*ret, 0);
	while (current)
	{
		string_cat((char*)current->str_ptr, current->str_size);
		string_cat(current->nbr_ptr, current->nbr_size);
		current = current->next;
	}
	string_cat(NULL, 0);
	return (len);
}

int			(*const g_specifiers[NUM_SPECIFIERS])(t_printf_part*, va_list *) = {
	build_nbr_0, build_nbr_1, build_nbr_1, build_nbr_3,
	build_nbr_4, build_nbr_5, build_nbr_6, build_nbr_7,
	build_nbr_8, build_nbr_15,
	build_nbr_16, build_nbr_17, build_nbr_19,
	build_nbr_20, build_nbr_21, build_nbr_22, build_nbr_23,
	build_nbr_24, build_nbr_25, build_nbr_26, NULL
};

static int	build_specifiers(t_printf_part **beginning, va_list *args)
{
	t_printf_part	*current;

	current = *beginning;
	while (current)
	{
		if (current->specifier)
			if (g_specifiers[current->specifier](current, args) < 1)
				return (0);
		if (current->flags & COLORS_FLAGS_FIELD)
			if (add_color_flag(current) < 1)
				return (0);
		current = current->next;
	}
	return (1);
}

int			ft_getprintf(char **ret, const char *format, va_list args)
{
	t_printf_part	*beginning[1];
	va_list			args2;
	int				i;

	if (parse_format(format, beginning) <= 0)
		return (-1);
	va_copy(args2, args);
	if (build_specifiers(beginning, &args2) <= 0)
		return (-1);
	i = concat_parts(beginning, ret);
	ptf_free_list(beginning);
	return (i);
}
