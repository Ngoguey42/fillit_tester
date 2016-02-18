/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:45:55 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:11:06 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_debug.h"
#include "libft.h"

static void	get_format_index(int index, char buf[5])
{
	const char	formats[][6] = {
		"%hhd", "%hhu", "%hd", "%hu",
		"%d", "%u", "%lld", "%llu",
		"%p", "%s", "%.3f", "%.3f", "%.3Lf", "%u", "%hhu"};

	ft_strlcpy(buf, formats[index], 6);
	return ;
}

static void	print_format(char buf[5], void *ptr, int i)
{
	if (i < 2 || i == 14)
		qprintf(buf, *(unsigned char*)ptr);
	else if (i < 4)
		qprintf(buf, *(unsigned short*)ptr);
	else if (i < 6 || i == 13)
		qprintf(buf, *(unsigned int*)ptr);
	else if (i < 8)
		qprintf(buf, *(unsigned long long int*)ptr);
	else if (i < 10)
		qprintf(buf, *(void**)ptr);
	else if (i == 10)
		qprintf(buf, *(float*)ptr);
	else if (i == 11)
		qprintf(buf, *(double*)ptr);
	else if (i == 12)
		qprintf(buf, *(long double*)ptr);
	else
		qprintf("bug");
}

static int	get_format(char *type, char buf[5])
{
	int			i;
	const char	types[][24] = {
		"char", "unsigned char", "short", "unsigned short",
		"int", "unsigned int", "long long int", "unsigned long long int",
		"void*", "char*", "float", "double", "long double", "size_t", "t_byte",
		""};

	i = 0;
	while (*types[i] != '\0' && !ft_strequ(types[i], type))
		i++;
	if (types[i] == NULL)
		return (0);
	get_format_index(i, buf);
	return (i);
}

void		ft_printvar(char s[3][50], void *ptr, int line)
{
	char	buf[5];
	int		i;

	qprintf("\033[33m%s:%d %s %s\033[0m = \033[31m", s[2], line, s[0], s[1]);
	if (!(i = get_format(s[0], buf)))
		qprintf("NYI");
	else
		print_format(buf, ptr, i);
	qprintf("\033[0m;\n");
	return ;
}
