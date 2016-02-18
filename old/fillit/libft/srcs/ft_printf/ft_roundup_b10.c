/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundup_b10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 07:54:37 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/22 09:31:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_roundup_b10(char *str)
{
	int	i;

	i = ft_strspn(str, "0123456789.");
	while (i--)
	{
		if (str[i] == '9')
			str[i] = '0';
		else if (str[i] == '.')
			continue ;
		else
		{
			str[i]++;
			break ;
		}
	}
	return (str);
}
