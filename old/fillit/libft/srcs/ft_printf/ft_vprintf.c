/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 09:00:12 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:39:47 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, const char *format, va_list args)
{
	int		len;
	char	*ret;

	ret = NULL;
	len = ft_getprintf(&ret, format, args);
	if ((!ret && len > 0) || len < 0)
		return (-1);
	else if (!ret)
		return (0);
	ft_memcpy(str, ret, len + 1);
	free(ret);
	return (len);
}

int	ft_vprintf(const char *format, va_list arg)
{
	int		len;
	char	*ret[1];

	len = ft_getprintf(ret, format, arg);
	if ((!*ret && len > 0) || len < 0)
		return (-1);
	else if (!*ret)
		return (0);
	if (len > 0)
		ft_putstr(*ret);
	free(*ret);
	return (len);
}

int	ft_vdprintf(int fd, const char *format, va_list arg)
{
	int		len;
	char	*ret[1];

	len = ft_getprintf(ret, format, arg);
	if (len >= 0)
		ft_putstr_fd(*ret, fd);
	return (len);
}
