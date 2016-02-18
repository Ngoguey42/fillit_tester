/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:46:38 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 13:47:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** 'ft_memdel' frees the memory zone pointed by ap, an sets it to NULL.
*/

void	ft_memdel(void **ap)
{
	if (!*ap)
		return ;
	free(*ap);
	*ap = NULL;
}
