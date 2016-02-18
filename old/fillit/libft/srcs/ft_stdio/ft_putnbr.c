/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:24:57 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/31 14:11:22 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'ft_putnbr' prints a given integer.
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[50];

	ft_itoa_c(n, buf, 10);
	ft_putstr_fd(buf, fd);
	return ;
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
