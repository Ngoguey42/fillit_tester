/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 15:36:45 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:22:51 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>
# include <stdarg.h>
# include "ft_typedefs.h"

/*
** -
** Strings.h
** -
*/
/*
** Copying:
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *s1, const char *s2, size_t num);
size_t	ft_strlcpy(char *s1, const char *s2, size_t num);

char	*ft_strccpy(char *dst, const char *src);
/*
** Concatenation:
*/
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcatfree(char *s1, char *s2);
/*
** Comparison:
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(const char *s1, const char *s2, size_t n);
int		ft_match(char *s1, char *s2);
int		ft_voidstrcmp(const void *s1, const void *s2);
int		ft_voiduintcmp(const void *s1, const void *s2);
int		ft_voidintcmp(const void *s1, const void *s2);
int		ft_cmpi_e(const void *a, const void *b);
int		ft_cmpi_l(const void *a, const void *b);
int		ft_cmpi_le(const void *a, const void *b);
int		ft_cmpi_g(const void *a, const void *b);
int		ft_cmpi_ge(const void *a, const void *b);

int		ft_cmpui_e(const void *a, const void *b);
int		ft_cmpui_l(const void *a, const void *b);
int		ft_cmpui_le(const void *a, const void *b);
int		ft_cmpui_g(const void *a, const void *b);
int		ft_cmpui_ge(const void *a, const void *b);
/*
** Searching:
*/
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strspn(const char *str1, const char *str2);
size_t	ft_strcspn(const char *s1r, const char *s2r);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
/*
** Other:
*/
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n);
void	ft_strclr(char *s);
size_t	ft_strcharlen(const char *str, const char delim);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memcset(void *b, int c, size_t len);
int		get_next_line(int const fd, char **line);

#endif
