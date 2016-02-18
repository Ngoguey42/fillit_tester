/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbltype.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 12:05:29 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/06 12:06:15 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DBLTYPE_H
# define FT_DBLTYPE_H

# include "ft_typedefs.h"

# ifndef IEEE_DOUBLE_BIG_ENDIAN
#  define IEEE_DOUBLE_BIG_ENDIAN 0
# endif

# if IEEE_DOUBLE_BIG_ENDIAN

union					u_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		t_ui32			manh:20;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		unsigned char	sig:1;
		unsigned short	exp:11;
		unsigned char	nan:1;
		t_ui32			manh:19;
		t_ui32			manl:32;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manh:32;
		t_ui32			manl:32;
	}					s;
	double				d;
};

# else

union					u_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:20;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_nan_dbl_extract
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:19;
		unsigned char	nan:1;
		unsigned short	exp:11;
		unsigned char	sig:1;
	}					s;
	double				d;
};

union					u_dbl_shape
{
	struct
	{
		t_ui32			manl:32;
		t_ui32			manh:32;
	}					s;
	double				d;
};
# endif

typedef union u_dbl_extract		t_dbl_extract;
typedef union u_nan_dbl_extract	t_nan_dbl_extract;
typedef union u_dbl_shape		t_dbl_shape;

/*
** Math constants.
*/
# define M_INFINITY (1.0/0.0)
# define M_MINFINITY (-1.0/0.0)
# define M_NAN (0.0/0.0)
# define M_PD_MAXU (0x1.ffffffffffffep-1023)
# define M_PD_MINU (0x1.0p-1074)

#endif
