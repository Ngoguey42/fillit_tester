/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 03:54:04 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/04 05:15:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arg.h"

t_arg_parser		ft_arg_create(int ac, char const *const *av)
{
	return ((t_arg_parser){NULL, '\0', 0, ac, 0, ft_strlen(*av) - 1, av});
}

static int			is_digit(char const *str)
{
	while (ft_isblank(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	return (*str == '\0');
}

enum e_arg			ft_arg_next(t_arg_parser *p, enum e_arg expected)
{
	char const	*str;

	str = p->priv_av[p->priv_stri];
	if (str[p->priv_chari + 1] == '\0')
	{
		if (p->priv_stri + 1 >= p->priv_ac)
			return (FTARG_NONE);
		str = p->priv_av[++p->priv_stri];
		if (str[0] == '-' && expected != FTARG_INT && expected != FTARG_STRING)
			p->priv_chari = 0;
		else if (expected != FTARG_STRING && is_digit(str))
		{
			p->i = ft_atoi(str);
			p->priv_chari = ft_strlen(str) - 1;
			return (FTARG_INT);
		}
		else
		{
			p->s = str;
			p->priv_chari = ft_strlen(str) - 1;
			return (FTARG_STRING);
		}
	}
	p->c = str[++p->priv_chari];
	return (FTARG_OPTION);
}

char const			*ft_arg_name(enum e_arg arg)
{
	char const *const arr[] = {"None", "Option", "String", "Int"};

	return (arr[arg]);
}
