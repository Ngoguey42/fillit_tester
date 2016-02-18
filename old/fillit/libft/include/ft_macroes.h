/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macroes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 16:21:10 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 13:14:48 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROES_H
# define FT_MACROES_H

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MAX(V1, V2) ((V1) > (V2) ? V1 : V2)
# define MIN(V1, V2) ((V1) < (V2) ? V1 : V2)
# define ROUND_FTOI(A) ((A) > 0.f ? (int)((A) + 0.5f) : (int)((A) - 0.5f))
# define BASE_NBRS "0123456789abcdefghijklmnopqrstuvwxyz"

# define SIZE_ARRAY(A) (sizeof((A)) / sizeof(*(A)))
# define STRIDE_ARRAY(A) (sizeof(*(A)))
# define END_ARRAY(A) ((void*)(A) + sizeof((A)))
# define REACH_OFFSET(TYPE, P, OFF) ((TYPE*)((void*)(P) + (size_t)(OFF)))

# ifdef __CYGWIN__
#  define PRINTSIZEOF(T) qprintf("sizeof(%s) = %uBytes\n", #T, sizeof(T))
# else
#  define PRINTSIZEOF(T) qprintf("sizeof(%s) = %zuBytes\n", #T, sizeof(T))
# endif

# define NARG_2(A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,Z,...) Z
# define NARG_(...) NARG_2(__VA_ARGS__,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
# define NARG(...) NARG_(42, ##__VA_ARGS__)

#endif
