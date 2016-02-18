/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:02:41 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 12:16:29 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** TODO:
** remplacer les for pour etre a la norme
** mettre une libft
** matcher le sujet au niveau des erreurs
** verifier le parser
** verifier les fonctions interdites
** changer les fonctions de string.h pour libft.h
*/
# include "libft.h"
# include "ft_debug.h" //remove

# include <stdbool.h> //FROM LIBFT
# include <stdint.h> //FROM LIBFT
# include <stddef.h> //FROM LIBFT
# include <stdio.h> //REMOVE
# include <time.h> //REMOVE
# include <string.h> //REMOVE
# include <assert.h> //TO REMOVE LATER

typedef struct	s_vec2i //FROM LIBFT?
{
	int			x;
	int			y;
}				t_vec2i;

/*
** Shape ID
*/

typedef struct
{
	int			sid;
	uintmax_t	mask;
	__uint128_t	mask128;
	int			w;
	int			h;
	t_vec2i		dt[4];
	t_vec2i		finalpos;
	char		character;
}				t_piece;

# define MAP_W 13

typedef char		t_map[MAP_W][MAP_W];

typedef struct
{
	t_piece		pcs[27];
	int			lastpid;
}				t_ppool;

int				flt_parse(char const *fname, t_ppool p[1]);
void			flt_solve(t_ppool *pool);
bool			flt_solve64(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solve128(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solve128_plus(
	uintmax_t const m, t_ppool *const pool, int const w, int const pid);
bool			flt_solveptr(
	t_map m, t_ppool *const pool, int const w, int const pid);

#endif
