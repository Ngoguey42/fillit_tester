/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 10:33:58 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:24:10 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SET_H
# define FT_SET_H

# include "libft.h"

# define SETNODE struct s_ftset_node
# define SETNODEC struct s_ftset_node const
# define RESULT t_ftset_insertion

typedef struct		s_ftset_node
{
	SETNODE			*parent;
	SETNODE			*l;
	SETNODE			*r;
	size_t			height;
}					t_ftset_node;

typedef struct		s_ftset
{
	SETNODE			*head;
	size_t			size;
	size_t			height;
	size_t			chunk_size;
	int				(*cmp)();
}					t_ftset;

typedef struct		s_ftset_insertion
{
	SETNODE			*ptr;
	bool			inserted;
}					t_ftset_insertion;

/*
** * Initialization functions **
*/
void				fts_init_instance(t_ftset *s, size_t chunk_size
										, int (*cmp)());
t_ftset				fts_uninitialized(void);

/*
** * Destruction functions **
*/
void				fts_release(t_ftset *s, void (*dea)());

/*
** * Insertion functions **
*/
int					fts_insert(t_ftset *s, SETNODEC *node, RESULT *status);

/*
** * Iteration functions **
*/
void				fts_foreach(t_ftset *s, void (*fun)(), void *ext);
void				fts_foreachi(t_ftset *s, void (*fun)(), void *ext);
SETNODE				*fts_next(SETNODE *node);
SETNODE				*fts_begin(t_ftset *set);
SETNODEC			*fts_cnext(SETNODEC *node);
SETNODEC			*fts_cbegin(t_ftset const *set);

/*
** * Internal functions **
*/
SETNODE				*fts_build_cur(t_ftset *const s, SETNODEC *const new
								, RESULT *const status, SETNODE *const cur);
void				fts_increment_parents_heights(SETNODEC *son
													, SETNODE *parent);
SETNODE				*fts_gen_node(t_ftset *s, SETNODE *parent, SETNODEC *new
							, RESULT *status);
void				fts_repair_sons_link(SETNODE *son, SETNODE *parent);
void				fts_repair_node_height(SETNODE *node);
void				fts_repair_parents_link(SETNODE *son, SETNODE *parent
										, SETNODE const *oldson);
void				fts_repair_parents_heights(SETNODE *node);
SETNODE				*fts_rebalance_node(SETNODE *cur);

# undef SETNODE
# undef SETNODEC
# undef RESULT

#endif
