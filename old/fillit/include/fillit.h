/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:02:41 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/18 14:52:28 by ngoguey          ###   ########.fr       */
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


/*
**	Test session: (TimeOut at 1sec), vs https://github.com/LeGuit/fillit
**
** debug flt_solveptr:
**		1x113	OK
**		2x3000	2.688ms(avg)
**		8x1000	3.603ms(avg)
**		11x200	29.478ms(avg)
**		15x200	?
**		26x200	216.332ms(avg)	32TimeOuts
**
** debug flt_solve64:
**		1x113	OK
**		2x3000	3.974ms(avg)
**		8x1000	3.163ms(avg)
**		11x200	11.917ms(avg)
**		15x200	489.947ms(avg)	77TimeOuts
**		26x200	N/A
**
** debug flt_solve128:
**		1x113	OK
**		2x3000	2.59ms(avg)
**		8x1000	3.544ms(avg)
**		11x200	20.919ms(avg)
**		15x200	?
**		26x200	181.893ms(avg)	20TimeOuts
**
** debug flt_solve128_plus:
**		1x113	OK
**		2x3000	2.799ms(avg)
**		8x1000	5.158ms(avg)
**		11x200	37.138ms(avg)	2TimeOuts
**		15x200	598.642ms(avg)	90TimeOuts
**		26x200	200.848ms(avg)	29TimeOuts
**
*/

/*
** 3 4.000000
** 4 4.000000
** 5 5.000000
** 6 5.000000
** 7 6.000000
** 8 6.000000
** 9 6.000000
** 10 7.000000	EASY
** 11 7.000000
** 12 7.000000	HARD
** 13 8.000000	EASY
** 14 8.000000
** 15 8.000000
** 16 8.000000	HARD
** 17 9.000000	EASY
** 18 9.000000
** 19 9.000000
** 20 9.000000	HARD
** 21 10.000000	EASY
** 22 10.000000
** 23 10.000000
** 24 10.000000
** 25 10.000000	HARD
** 26 11.000000	EASY
*/

#endif
