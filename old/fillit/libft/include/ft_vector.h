/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 16:34:05 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/07 19:27:18 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"

typedef struct	s_ftvector
{
	void		*data;
	size_t		size;
	size_t		capacity;
	size_t		chunk_size;
}				t_ftvector;

/*
** * Initialization functions **
** *
** 'ftv_init_instance'	Does the very first allocation of 'data' in v.
** 'ftv_init_alloc'		Does the very first allocation of 'data' and allocs v.
*/
void			ftv_init_instance(t_ftvector *v, size_t chunk_size);
t_ftvector		*ftv_init_alloc(size_t chunk_size);
t_ftvector		ftv_uninitialized(void);
int				ftv_copy(t_ftvector *dst, t_ftvector const *src);

/*
** * Destruction functions **
** *
** 'ftv_release'		Calls 'del' on each if not NULL, then calls free
**							on data.
** 'ftv_pop_back'		Calls 'del' on last if not NULL, then decreases 'size'.
** 'ftv_clear'			Calls 'del' on each if not NULL, then sets 'size' to 0.
** *
*/
void			ftv_release(t_ftvector *v, void (*del)(void*));
void			ftv_pop_back(t_ftvector *v, void (*del)(void*));
void			ftv_clear(t_ftvector *v, void (*del)(void*));

/*
** * Capacity functions **
** *
** 'ftv_reserve'		Reallocates 'data' to 'newcapacity'.
** 'ftv_shrink_to_fit'	Reallocates 'data' to 'size'.
*/
int				ftv_reserve(t_ftvector *v, size_t newcapacity);
int				ftv_double_capacity(t_ftvector *v);
int				ftv_shrink_to_fit(t_ftvector *v);

/*
** * Data functions **
** *
** 'ftv_push_back'		Copies the #(chunk_size) first bytes pointed by ptr
**							at the back of data, may reallocate data.
** 'ftv_push_back_unsafe'Copies the #(chunk_size) first bytes pointed by ptr
**							at the back of data.
** 'ftv_assign'			Assigns #(chunk_size) bytes pointed by ptr
** 							to all #(size) chunks.
** 'ftv_insert_count'	Copies #(count) times the #(chunk_size) first bytes
** 							pointed by ptr at the back of data, may reallocate
** 							data.
** 'ftv_insert_range'	Copies the #(chunk_size * count) first bytes
** 							pointed by ptr at the back of data, may reallocate
** 							data.
*/
int				ftv_push_back(t_ftvector *v, void const *ptr);
void			ftv_push_back_unsafe(t_ftvector *v, void const *ptr);
void			ftv_assign(t_ftvector *v, void const *ref);
int				ftv_insert_count(t_ftvector *v, void const *ref, size_t count);
int				ftv_insert_range(t_ftvector *v, void const *ref, size_t count);

/*
** * Browsing functions **
*/
size_t			ftv_find_index(t_ftvector const *v, void const *ref);
void			*ftv_find_ptr(t_ftvector const *v, void const *ref);
bool			ftv_find(t_ftvector const *v, void const *ref);

void			ftv_foreach0(t_ftvector const *v, void (*fun)());
void			ftv_foreach(t_ftvector const *v, void (*fun)(), void *ext);
void			ftv_foreach2(t_ftvector const *v, void (*fun)(), void *e1
								, void *e2);
void			ftv_foreach_if(t_ftvector const *v, void (*fun)(), void *ext,
								bool (*cond)());
void			ftv_foreachi(t_ftvector const *v, void (*fun)(), void *ext);

/*
** * Iteration functions **
*/
void const		*ftv_end(t_ftvector const *v);

/*
** * Debug functions **
*/
void			ftv_summarize(t_ftvector const *v);
void			ftv_print(t_ftvector const *v, char const fmt[]);
void			ftv_printn(t_ftvector const *v, char const fmt[], size_t n);

#endif
