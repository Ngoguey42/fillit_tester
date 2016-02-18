/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 08:32:19 by ngoguey           #+#    #+#             */
/*   Updated: 2015/06/03 16:12:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_crealloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = malloc(new_size)))
		return (NULL);
	if (new_size < old_size)
		old_size = new_size;
	if (ptr && old_size > 0)
	{
		ft_memcpy(new, ptr, old_size);
		free(ptr);
		ft_bzero(new + old_size, new_size - old_size);
	}
	else
		ft_bzero(new + old_size, new_size);
	return (new);
}
