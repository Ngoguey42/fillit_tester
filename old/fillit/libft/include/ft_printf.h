/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:35:17 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:00:50 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "libft.h"

/*
** TODOLIST
** recheck les arguments size
** take care of memory leaks in add_color_flags.c
*/

# include <stdarg.h>
# define VATYPE		va_arg
# define VASTA		va_start
# define VACPY		va_copy
# define VAEND		va_end

/*
** FLAGS
*/
# define CHARS_FLAGS "-+ #0!$MNHIJK_\'"
# define MINU_MASK 0x1
# define PLUS_MASK 0x2
# define SPAC_MASK 0x4
# define HASH_MASK 0x8
# define ZERO_MASK 0x10
# define EXCL_MASK 0x20
# define DOLL_MASK 0x40
# define APOS_MASK 0x4000

# define FIRT_C_FLAG_ID		7
# define NUM_COLOR_FLAGS 	7
# define COLORS_FLAGS_FIELD	0x3F80
# define SIZE_OF_FLAGS		(sizeof(TYPE_OF_FLAGS) * 8)
# define TYPE_OF_FLAGS		unsigned short
# include "ft_printfdefs.h"

/*
** INFO
*/
# define WSTA_MASK	0x1
# define PSTA_MASK	0x2
# define PNUM_MASK	0x4

/*
** LENGTH, SPECIFIERS
*/
# define CHARS_LENGTH		"jztLhl"
# define NUM_DBL_CHAR_LEN	2
# define CHARS_SPECIFIERS	"diuoxXfFcsp%brDUOCS"
# define NUM_SPECIFIERS		(sizeof(CHARS_SPECIFIERS) + 1)

/*
** MACROS
*/
# define AND_F(x) (part->flags & x)
# define AND_I(x) (part->info & x)
# define PAD_CHAR part->flags & ZERO_MASK ? '0' : ' '

/*
** MISC
*/
# define NUM_C_TAGS 33
# define NUM_SMALLC_TAGS 7

/*
** BUFFERS
*/
# define DEFAULT_SCREEN_WIDTH 75
# define DEFAULT_COLS_SPACER ' '
# define DEFAULT_FILLER ' '

/*
** For external use.
*/
int		ft_getprintf(char **ret, const char *format, va_list args);
void	ptf_free_list(t_printf_part **beginning);

int		parse_format(const char *format, t_printf_part **beginning);
int		final_string_size(t_printf_part *current);
int		coi(const char *str);
int		add_color_flag(t_printf_part *p);
void	string_cat(char *s1, size_t len);

int		store_opt_1(char c, t_printf_part *part);
int		store_opt_2(char c, t_printf_part *part);
int		store_opt_3(char c, t_printf_part *part);
int		store_opt_5(char c, t_printf_part *part);
int		store_opt_6(char c, t_printf_part *part);
int		store_opt_7(char c, t_printf_part *part);
int		store_opt_8(char c, t_printf_part *part);

/*
** Specifiers building.
*/
int		build_nbr_0(t_printf_part *part, va_list *args);
int		build_nbr_1(t_printf_part *part, va_list *args);
int		build_nbr_3(t_printf_part *part, va_list *args);
int		build_nbr_4(t_printf_part *part, va_list *args);
int		build_nbr_5(t_printf_part *part, va_list *args);
int		build_nbr_6(t_printf_part *part, va_list *args);
int		build_nbr_7(t_printf_part *part, va_list *args);
int		build_nbr_8(t_printf_part *part, va_list *args);
int		build_nbr_13(t_printf_part *part, va_list *args);
int		build_nbr_14(t_printf_part *part, va_list *args);
int		build_nbr_15(t_printf_part *part, va_list *args);
int		build_nbr_16(t_printf_part *part, va_list *args);
int		build_nbr_17(t_printf_part *part, va_list *args);
int		build_nbr_19(t_printf_part *part, va_list *args);
int		build_nbr_20(t_printf_part *part, va_list *args);
int		build_nbr_21(t_printf_part *part, va_list *args);
int		build_nbr_22(t_printf_part *part, va_list *args);
int		build_nbr_23(t_printf_part *part, va_list *args);
int		build_nbr_24(t_printf_part *part, va_list *args);
int		build_nbr_25(t_printf_part *part, va_list *args);
int		build_nbr_26(t_printf_part *part, va_list *args);
t_i64	get_signed_varg(t_byte length, va_list *args);
t_ui64	get_unsigned_varg(t_byte length, va_list *args);

/*
** %i %d %u %x %X %o %p dependency.
*/
void	apply_width_integer_pad(t_printf_part *part, char **sp, int l, int w);

/*
** %a %A dependencies.
*/
char	*ft_build_unnormalized(double nbr, t_printf_part *part, int i);
char	*ft_build_normalized(double nbr, t_printf_part *part);
void	round_mantissa_b16(char **ptr, int pre, int *int_part_two);

char	*ptf_build_decnbr(double nbr, t_printf_part *part);

/*
** %S dependencies.
*/
size_t	npnt_len(char *str, t_printf_part *part, int p);
void	npnt_cat(char **ret, char src, char *input, int *color_status);

/*
** debug
*/
void	inspect_part(t_printf_part *part);

/*
** misc.
*/
double	ft_log10(double nb);
double	ft_ceil(double nb);
double	ft_floor(double nb);
int		ft_dbltype(double nbr_ref);
char	*ft_roundup_b10(char *str);
char	*ft_pad_string(char *str, char c, int n, int freestr);

#endif
