/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_nonprintable_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 09:08:43 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:03:35 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ONECHARPTR(PTR) char	*PTR
#define D_CHARPTR(p1, p2, p3) ONECHARPTR(p1); ONECHARPTR(p2); ONECHARPTR(p3)

/*
** %S non printable chars:
** %S	Coloured text, Hexadecimal notation, Escapes codes whenever possible.
**			'\t' and '\n' not substituted. '$' added to '\n'.
** %zS	Same as '%S' but uses keyboard shortcuts instead of Hexadecimal.
** %lS	Same as '%S' but uses Decimal instead of Hexadecimal.
** %hS	Same as '%S' but prints '?' .
** '!'	Flag, Removes colour.
** '$'	Substitutes '\n' to code.
** ' '	Substitutes '\t' to code.
** '#'	Removes Hexadecimal/Decimal prefixes.
** '0'	Substitutes escapes codes to number codes.
** %!zS	Same as cat -e.
** %! $0hS	Same as file names..
** %.*S	Stops printing after PRECISION chars.
*/

static char	*control(char c)
{
	char	s1[3];
	char	s2[3];

	ft_strcpy(s1, "M-");
	ft_strcpy(s2, "^x");
	if (c >= 0)
		*s1 = '\0';
	if (c == '\x7F' || c == -1)
		s2[1] = '?';
	else if (c >= 0)
		s2[1] = c + 64 * 1;
	else if (c <= -97)
		s2[1] = c + 64 * 3;
	else
	{
		s2[0] = c + 64 * 2;
		s2[1] = '\0';
	}
	return (ft_strjoin(s1, s2));
}

static char	*escape(char c)
{
	if (c == '\f')
		return ("f");
	else if (c == '\n')
		return ("n");
	else if (c == '\r')
		return ("r");
	else if (c == '\033')
		return ("e");
	else if (c == '\b')
		return ("b");
	else if (c == '\a')
		return ("a");
	else if (c == '\t')
		return ("t");
	return ("v");
}

static char	*numeric(char c, t_printf_part *part, int prefix)
{
	char		s1[3];
	t_readbit	u;
	char		*tmp;

	ft_strcpy(s1, "\\d");
	if (!prefix)
		s1[0] = '\0';
	else if (part->length != 6)
		s1[1] = 'x';
	if (part->length == 6 || c >= 0)
	{
		tmp = ft_itoa_a(c, part->length == 6 ? 10 : 16);
		return (ft_strjoinfree(s1, tmp, 0, 1));
	}
	u.s = c;
	return (ft_strjoinfree(s1, ft_itoa_a((int)u.u, 16), 0, 1));
}

static char	*reveal_non_printables(char *str, t_printf_part *part, int p)
{
	int		i;
	char	*ret;
	char	*save;

	ret = (char*)ft_memalloc(sizeof(char) * npnt_len(str, part, p));
	if (!(save = ret))
		return (NULL);
	i = AND_F(EXCL_MASK) ? -1 : 0;
	while ((!AND_I(PNUM_MASK) && *str) || (AND_I(PNUM_MASK) && p-- > 0))
	{
		if (ft_isprint(*str) || (*str == '\t' && !AND_F(SPAC_MASK)) ||
		(*str == '\n' && !AND_F(DOLL_MASK)))
			npnt_cat(&ret, *str, *str == '\n' ? ft_strdup("$\n") : NULL, &i);
		else if (part->length == 5)
			npnt_cat(&ret, *str, ft_strdup("?"), &i);
		else if (ft_isescape(*str) && !AND_F(ZERO_MASK))
			npnt_cat(&ret, *str, ft_strjoin("\\", escape(*str)), &i);
		else if (part->length == 2)
			npnt_cat(&ret, *str, control(*str), &i);
		else
			npnt_cat(&ret, *str, numeric(*str, part, !AND_F(HASH_MASK)), &i);
		str++;
	}
	npnt_cat(&ret, '\0', NULL, &i);
	return (save);
}

int			build_nbr_21(t_printf_part *part, va_list *args)
{
	int		width;
	int		precision;
	char	*str;

	width = part->info & WSTA_MASK ? va_arg(*args, int) : part->width;
	precision = part->info & PSTA_MASK ? va_arg(*args, int) : part->precision;
	str = (char*)va_arg(*args, char*);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = reveal_non_printables(str, part, precision < 0 ?
								(int)ft_strlen(str) : precision);
	if (!str)
		return (0);
	if (width > 0 && width > (int)ft_strlen(str))
	{
		if (part->flags & MINU_MASK)
			str = ft_pad_string(str, ' ', -width, 1);
		else
			str = ft_pad_string(str, PAD_CHAR, width, 1);
	}
	else if (width < 0 && ABS(width) > (int)ft_strlen(str))
		str = ft_pad_string(str, ' ', width, 1);
	part->nbr_ptr = str;
	return (1);
}
