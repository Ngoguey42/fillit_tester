/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:34:59 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/08 16:23:03 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#ifdef LIBFT_INTERNAL_USE_STD
# include <string.h>
#endif

void		*ft_memdup(void const *p, size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	LIBFT_MEMCPY(new, p, size);
	return (new);
}
