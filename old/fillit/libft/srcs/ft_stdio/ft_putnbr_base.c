/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:25:14 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:20:02 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int n, int base)
{
	if (base < 2 || base > 36)
		return ;
	if (n < 0)
	{
		ft_putchar('-');
		if (n <= -base)
			ft_putnbr_base(-(n / base), base);
		ft_putchar(BASE_NBRS[-(n % base)]);
		return ;
	}
	if (n >= base)
		ft_putnbr_base(n / base, base);
	ft_putchar(BASE_NBRS[n % base]);
}

void	ft_putunbr_base(unsigned int n, int base)
{
	if (base < 2 || base > 36)
		return ;
	if (n >= (unsigned int)base)
		ft_putunbr_base(n / (unsigned int)base, base);
	ft_putchar(BASE_NBRS[n % (unsigned int)base]);
}
