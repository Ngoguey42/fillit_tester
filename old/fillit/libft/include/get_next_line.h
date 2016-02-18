/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:36:57 by ngoguey           #+#    #+#             */
/*   Updated: 2014/12/02 09:54:24 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

typedef struct			s_readi
{
	char				s[BUFF_SIZE];
	int					read;
	int					start;
	int					end;
	struct s_readi		*next;
}						t_readi;

typedef struct			s_file_d
{
	int					fd;
	t_readi				**firstcall;
	struct s_file_d		*next;
}						t_file_d;

#endif
