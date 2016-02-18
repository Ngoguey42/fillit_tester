/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 15:45:44 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:40:47 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_H
# define FT_CONTAINERS_H

# include "ft_set.h"
# include "ft_list.h"
# include "ft_vector.h"
# include "libft.h"

/*
** Conversions **
** 					functions do not handle initializations.
** 					functions do 	 handle reserve.
**					functions do not handle memcpy (funptr does)
*/

int		ft_set_to_vector(t_ftset const *s, t_ftvector *v
							, void (*cpy)(), void *ext);

#endif
