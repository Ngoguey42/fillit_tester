/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:28:26 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 19:45:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdbool.h>
# include <stdint.h>

/*
** Internal policy regarding standard library
**	any debug function may std libs (including qprintf)
**	any other generic function must use (libft) || (LFT_*PTF macroes)
*/

/*
**# define LIBFT_INTERNAL_USE_STD
*/

# ifdef LIBFT_INTERNAL_USE_STD

#  define LIBFT_REALLOC(ptr, olds, news)	realloc((ptr), (news))
#  define LIBFT_MEMCPY						memcpy
#  define LIBFT_MEMCMP						memcmp
#  define LFT_PTF							printf
#  define LFT_DPTF							dprintf
#  define LFT_VPTF							vprintf
#  define LFT_VDPTF							vdprintf
#  define LFT_FFLUSH(ARG)					fflush((ARG))
#  define LFT_STRERROR						strerror
#  define LFT_EXIT(ARG)						exit((ARG))

# else

#  define LIBFT_REALLOC(ptr, olds, news)	ft_realloc((ptr), (olds), (news))
#  define LIBFT_MEMCPY						ft_memcpy
#  define LIBFT_MEMCMP						ft_memcmp
#  define LFT_PTF							ft_printf
#  define LFT_DPTF							ft_dprintf
#  define LFT_VPTF							ft_vprintf
#  define LFT_VDPTF							ft_vdprintf
#  define LFT_FFLUSH(ARG)
#  define LFT_STRERROR						ft_strerror
#  define LFT_EXIT(ARG) 	ft_putendl_fd("Exit should not be used!", 2)

# endif

# include "ft_typedefs.h"
# include "ft_macroes.h"
# include "ft_stdio.h"
# include "ft_stdlib.h"
# include "ft_ctype.h"
# include "ft_string.h"

void			ft_skiptype(char **pptr, int (*typefun)(int c));
void			ft_skipntype(char **pptr, int (*typefun)(int c));
size_t			ft_parseuinteger(char *str, size_t *uiptr);
size_t			ft_strlentype(char const *str, int (*typefun)(int c));

int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				ft_abs(int x);
float			ft_fmax(float a, float b);
float			ft_fmin(float a, float b);
float			ft_fabs(float x);

float			ft_randf01(void);
float			ft_randf0(void);

uint16_t		ft_i16toh(uint16_t i, bool big_endian);
uint32_t		ft_i32toh(uint32_t i, bool big_endian);
uint64_t		ft_i64toh(uint64_t i, bool big_endian);

#endif
