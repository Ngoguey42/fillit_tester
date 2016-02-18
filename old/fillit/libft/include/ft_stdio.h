/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 15:33:25 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 15:33:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stddef.h>
# include <stdarg.h>
# include "ft_typedefs.h"

/*
** -
** stdio.h
** -
*/
int		ft_vprintf(const char *format, va_list arg);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vsprintf(char *s, const char *format, va_list arg);
int		ft_vsnprintf(char *s, size_t n, const char *format, va_list arg);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);
int		ft_snprintf(char *s, size_t n, const char *format, ...);

/*
** Character input/output:
*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr(int i);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);

void	ft_putnbr_base(int n, int base);
void	ft_putunbr_base(unsigned int n, int base);
void	ft_putnchar(char c, size_t n);

#endif
