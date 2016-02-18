/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:33:10 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/17 16:57:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "libft.h"

# define LISTNODE struct s_ftlist_node
# define LISTNODEC struct s_ftlist_node const

/*
** t_ftlist_node must be at the beginning of the storage struct.
** i could implement offset easily.
** Although next/prev must have the same order in 't_ftlist_node' / 't_ftlist'.
*/

typedef struct		s_ftlist_node
{
	LISTNODE		*next;
	LISTNODE		*prev;
}					t_ftlist_node;

typedef struct		s_ftlist
{
	LISTNODE		*next;
	LISTNODE		*prev;
	size_t			chunk_size;
	size_t			size;
}					t_ftlist;

/*
** * Initialization functions **
** *
** 'ftl_init_instance'	Initializes all values in 'l'.
** *
** 'ftl_uninitialized'	Returns a default head.
*/
void				ftl_init_instance(t_ftlist *l, size_t chunk_size);
t_ftlist			ftl_uninitialized(void);

/*
** Adding **
*/
int					ftl_emplace_back(t_ftlist *l, LISTNODEC *node);
int					ftl_push_back(t_ftlist *l, LISTNODEC *node);
int					ftl_push_front(t_ftlist *l, LISTNODEC *node);
int					ftl_insert_pos(t_ftlist *l, LISTNODE *pos, LISTNODEC *node);
int					ftl_insert_sort(
	t_ftlist *l, LISTNODEC *node, int64_t (*cmp)());
void				ftl_splice_one_back(
	t_ftlist *dst, t_ftlist *src, LISTNODE *node);

/*
** Removing **
** *
** 'ftl_release'	For each links: pops it out, calls dea if not null, frees it
** *
** 'ftl_pop_back'	Pops it out, calls dea if not null, frees it.
**						Undefined if l->size == 0
** *
** 'ftl_pop_front'	Pops it out, calls dea if not null, frees it.
**						Undefined if l->size == 0
** *
** 'ftl_erase_pos'	Pops it out, calls dea if not null, frees it.
** 						Undefined if 'pos' is not a link.
** *
*/
void				ftl_release(t_ftlist *l, void (*dea)());
void				ftl_pop_back(t_ftlist *l, void (*dea)());
void				ftl_pop_front(t_ftlist *l, void (*dea)());
void				ftl_erase_pos(t_ftlist *l, LISTNODE *pos, void (*dea)());

/*
** Browsing **
*/
void				ftl_foreach(t_ftlist const *l, void (*fun)(), void *ext);
void				ftl_foreach2(
	t_ftlist const *l, void (*fun)(), void *ext1, void *ext2);
void				ftl_foreachi(t_ftlist const *l, void (*fun)(), void *ext);
void				ftl_foreach_if(t_ftlist const *l, void (*fun)(), void *ext
									, bool (*pred)());
void				ftl_foreachi_if(t_ftlist const *l, void (*fun)(), void *ext
									, bool (*pred)());

/*
** Conversions **
*/
LISTNODE			*ftl_end(t_ftlist *l);
LISTNODEC			*ftl_cend(t_ftlist const *l);

# define FTL_END(L) ftl_end((L))
# define FTL_CEND(L) ftl_cend((L))

/*
** # define FTL_END(P) ((t_ftlist_node*)(P))
** # define FTL_CEND(P) ((t_ftlist_node const*)(P))
*/

# undef LISTNODE
# undef LISTNODEC

#endif
