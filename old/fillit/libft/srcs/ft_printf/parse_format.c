/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:24:09 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/07 18:32:04 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** static 'new_part' allocates a new 't_printf_part'.
** static 'get_control_char' validates a char read inside a %substitution.
** static 'populate_store_tab' populates the table handling 'control_char'.
** static 'parse_part' store all informations inside a 't_printf_part'.
** 'parse_format' parse the whole printf format.
*/

/*
** 'get_control_char' return values
** 0	none
** 1	percent			1char max
** 2	flags			any char part of CHARS_FLAGS
** 3	width			n consecutive char, starting with (1-9)
** 4	dot				erreur sans precision	1char max
** 5	precision		n consecutive char, starting with (0-9)
** 6	length			1char max
** 7	length 2		1char max
** 8	specifier		1char max
*/

static t_printf_part	*new_part(const char *str)
{
	t_printf_part	*new;

	new = (t_printf_part*)malloc(sizeof(t_printf_part) * 1);
	if (!new)
		return (NULL);
	new->str_ptr = str;
	new->nbr_ptr = "";
	new->nbr_size = -1;
	new->flags = 0;
	new->info = 0;
	new->width = 0;
	new->precision = 0;
	new->length = 0;
	new->specifier = 0;
	new->next = NULL;
	return (new);
}

static char				get_control_char(char c, char p_opt)
{
	if (c == '\0')
		return (0);
	if (p_opt == 0 && c == '%')
		return (1);
	if (ft_strchr(CHARS_FLAGS, c) && p_opt < 3)
		return (2);
	if ((ft_isdigit(c) || c == '*') && p_opt < 6)
	{
		if (p_opt < 4)
			return (3);
		else
			return (5);
	}
	if (c == '.' && p_opt < 4)
		return (4);
	if (ft_strchr(CHARS_LENGTH, c) && p_opt < 7)
	{
		if (p_opt < 6)
			return (6);
		else
			return (7);
	}
	if (ft_strchr(CHARS_SPECIFIERS, c) && p_opt < 8)
		return (8);
	return (0);
}

static void				populate_store_tab(int (*store_opt[9])
											(char c, t_printf_part *part))
{
	store_opt[0] = store_opt_1;
	store_opt[1] = store_opt_1;
	store_opt[4] = store_opt_1;
	store_opt[2] = store_opt_2;
	store_opt[3] = store_opt_3;
	store_opt[5] = store_opt_5;
	store_opt[6] = store_opt_6;
	store_opt[7] = store_opt_7;
	store_opt[8] = store_opt_8;
}

static int				parse_part(t_printf_part *part)
{
	const char	*str;
	char		opt;
	char		p_opt;
	int			(*store_opt[9])(char c, t_printf_part *part);

	populate_store_tab(store_opt);
	part->str_size = ft_strcharlen(part->str_ptr, '%');
	str = part->str_ptr + part->str_size;
	p_opt = 0;
	while ((opt = get_control_char(*str, p_opt)))
	{
		if (!store_opt[(size_t)opt]((char)*str, part))
			return (-1);
		p_opt = opt;
		str++;
	}
	if (*str != '\0' && !(part->next = new_part(str)))
		return (-1);
	return (1);
}

int						parse_format(const char *format,
										t_printf_part **beginning)
{
	t_printf_part *current;

	if (!(current = new_part(format)))
		return (-1);
	*beginning = current;
	if (!parse_part(current))
		return (-1);
	while ((current = current->next))
	{
		if (parse_part(current) < 0)
			return (-1);
	}
	return (1);
}
