/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:52:41 by ngoguey           #+#    #+#             */
/*   Updated: 2015/01/13 08:24:05 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

#define SEARCHLF ft_memchr(cur->s + cur->start, '\n', cur->read - cur->start)

t_file_d	*get_fd_struct(t_file_d *current, int const fd)
{
	t_file_d	*new;

	while (current && current->next && current->fd != fd)
		current = current->next;
	if (current && current->fd == fd)
		return (current);
	new = (t_file_d*)malloc(sizeof(t_file_d));
	if (!new || !(new->firstcall = (t_readi**)malloc(sizeof(t_readi*))))
		return (NULL);
	*(new->firstcall) = NULL;
	new->next = NULL;
	new->fd = (int)fd;
	if (current)
		current->next = new;
	return (new);
}

static int	read_fd(t_file_d *fd)
{
	t_readi	*cur;

	if (!*(fd->firstcall))
	{
		cur = (t_readi*)malloc(sizeof(t_readi));
		if (!(*(fd->firstcall) = cur))
			return (-1);
		ft_bzero(cur, sizeof(t_readi));
		cur->read = read(fd->fd, cur->s, BUFF_SIZE);
	}
	cur = *(fd->firstcall);
	while (cur->read > 0 &&
		(cur->end = SEARCHLF ? (char*)SEARCHLF - cur->s : -1) < 0)
	{
		cur->next = (t_readi*)malloc(sizeof(t_readi));
		cur = cur->next;
		if (!cur)
			return (-1);
		ft_bzero(cur, sizeof(t_readi));
		cur->read = read(fd->fd, cur->s, BUFF_SIZE);
	}
	return (cur->read);
}

static int	concat_buffers(t_file_d *fd, char **line, int *w)
{
	t_readi	*cur;
	char	*s;

	cur = *fd->firstcall;
	if ((cur->end >= 0 ? cur->end : cur->read) >= cur->start)
		cur->end = (cur->end >= 0 ? cur->end : cur->read) - cur->start;
	*w = cur->end;
	while ((cur = cur->next))
		*w += (cur->end = (cur->end >= 0 ? cur->end : cur->read) - cur->start);
	s = (char*)ft_memalloc(sizeof(char) * (*w + 1));
	if (!(*line = s))
		return (-1);
	cur = *fd->firstcall;
	while (1)
	{
		ft_memcpy((void*)s, cur->s + cur->start, cur->end);
		s += cur->end;
		cur->start += cur->end + 1;
		cur->end = 0;
		if (cur->next)
			cur = cur->next;
		else
			return (cur->read);
	}
	return (0);
}

static void	clean_mess(t_file_d **first, t_file_d *cur, int delfd)
{
	t_file_d	*curfd;
	t_readi		*prev;

	while ((*(cur->firstcall))->next)
	{
		prev = *(cur->firstcall);
		*(cur->firstcall) = prev->next;
		free(prev);
	}
	if (delfd)
	{
		if (*first == cur)
			*first = cur->next;
		else
		{
			curfd = *first;
			while (curfd->next != cur)
				curfd = curfd->next;
			curfd->next = cur->next;
		}
		free(*(cur->firstcall));
		free(cur->firstcall);
		free(cur);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_file_d		*first[1] = {NULL};
	t_file_d			*current;
	int					rets;
	int					written;
	char				*tmp;

	current = get_fd_struct(*first, fd);
	*first = *first ? *first : current;
	if (!current)
		return (-1);
	rets = read_fd(current);
	if (rets < 0)
		return (-1);
	rets = concat_buffers(current, line ? line : &tmp, &written);
	clean_mess(first, current, !rets);
	if (!line)
		free(tmp);
	if (rets == 0 && written > 0)
		return (written);
	return (rets != 0);
}
