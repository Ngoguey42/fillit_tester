/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftv_debug_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 17:19:30 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:19:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_vector.h"
#include "libft.h"
#include "ft_debug.h"

/*
**	'ftv_print'		format:
**					i(int)		I(skip int)
**					f(float)	F(skip float)
**					z(size_t)	Z(skip size_t)
**					s(str)		S(skip str)
**					p(ptr)		P(skip ptr)
**					c(char)		C(skip char)
**					u(uint)		U(skip uint)
**					d(double)	D(skip double)
**					t(short)	T(skip short)
*/

#define PT(P,OF,FMT,T) (qprintf(FMT, *(T*)(P + *OF)), 0)
#define INC(OF,T) (inc(OF, sizeof(T)), 0)
#define PINC(OF,T) (preinc(OF, sizeof(T)), 1)
#define EXEC(P,OF,TK,L,F,T) (PINC(OF,T) && L==TK && PT(P,OF,F,T)) || INC(OF,T)

static void		preinc(size_t *of, size_t pad)
{
	*of += (pad - *of % pad) % pad;
	return ;
}

static void		inc(size_t *of, size_t pad)
{
	*of += pad;
	return ;
}

static void		exec_format(void const *p, size_t *of, char tk)
{
	char const	l = ft_tolower(tk);

	if (l == 'i')
		EXEC(p, of, tk, l, "(%i)", int);
	else if (l == 'f')
		EXEC(p, of, tk, l, "%5.2f", float);
	else if (l == 'z')
		EXEC(p, of, tk, l, "#%zu", size_t);
	else if (l == 's')
		EXEC(p, of, tk, l, "\"%s\"", char*);
	else if (l == 'p')
		EXEC(p, of, tk, l, "%p", void*);
	else if (l == 'c')
		EXEC(p, of, tk, l, "'%c'", char);
	else if (l == 'u')
		EXEC(p, of, tk, l, "(%u)", unsigned int);
	else if (l == 'd')
		EXEC(p, of, tk, l, "%5.2f", double);
	else if (l == 't')
		EXEC(p, of, tk, l, "%hd", short);
	return ;
}

void			ftv_print(t_ftvector const *v, char const fmt[])
{
	size_t				fmti;
	size_t const		fmtend = ft_strlen(fmt);
	void const			*datptr = v->data;
	size_t				i;
	size_t				offset[1];

	i = 0;
	while (i < v->size)
	{
		fmti = 0;
		*offset = 0;
		qprintf("%-3zu ", i);
		while (fmti < fmtend)
		{
			exec_format(datptr, offset, fmt[fmti]);
			ft_putchar_fd(' ', 2);
			fmti++;
		}
		ft_putchar_fd('\n', 2);
		i++;
		datptr += v->chunk_size;
	}
	return ;
}

void			ftv_printn(t_ftvector const *v, char const fmt[], size_t n)
{
	size_t				fmti;
	size_t const		fmtend = ft_strlen(fmt);
	void const			*datptr = v->data;
	size_t				i;
	size_t				offset[1];

	i = 0;
	while (i < v->size && i < n)
	{
		fmti = 0;
		*offset = 0;
		qprintf("%-3zu ", i);
		while (fmti < fmtend)
		{
			exec_format(datptr, offset, fmt[fmti]);
			ft_putchar_fd(' ', 2);
			fmti++;
		}
		ft_putchar_fd('\n', 2);
		i++;
		datptr += v->chunk_size;
	}
	return ;
}
