/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdefs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:58:53 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/01 14:02:27 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFDEFS_H
# define FT_PRINTFDEFS_H

/*
** Main struct (linked list). (One for each '%' in format)[+1].
** 'str_ptr' pointer in format. Following format beginning or
** previous specifier, 'str_size' to locate the end.
** 'nbr_ptr' string resulting of the %subsitution, 'nbr_size' long.
** 'flags', 'info', 'width', 'precision', 'length', 'specifier' read in format.
** 'next' points next link.
*/

typedef struct				s_printf_part
{
	const char				*str_ptr;
	size_t					str_size;
	char					*nbr_ptr;
	int						nbr_size;
	TYPE_OF_FLAGS			flags;
	unsigned char			info;
	int						width;
	int						precision;
	unsigned char			length;
	unsigned char			specifier;
	struct s_printf_part	*next;
}							t_printf_part;

typedef union				u_readbit
{
	unsigned char			u;
	char					s;
}							t_readbit;

typedef	t_byte				*t_valist;

#endif
