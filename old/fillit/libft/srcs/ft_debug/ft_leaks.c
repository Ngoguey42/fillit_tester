/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:44:17 by ngoguey           #+#    #+#             */
/*   Updated: 2015/07/23 10:07:43 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_debug.h"

void		ft_leaks(void)
{
	char	buf[128];

	snprintf(buf, 128, "leaks %d", getpid());
	system(buf);
	exit(0);
	return ;
}
