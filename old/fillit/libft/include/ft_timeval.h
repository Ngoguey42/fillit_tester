/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeval.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/10 13:57:59 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/10 13:59:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIMEVAL_H
# define FT_TIMEVAL_H

# include <sys/time.h>

struct timeval			ft_timeval_diff(struct timeval x, struct timeval y);
double					ft_timeval_tosec(struct timeval t);
double					ft_timeval_elapsed(struct timeval old);

#endif
