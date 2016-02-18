/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color_tags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:36:23 by ngoguey           #+#    #+#             */
/*   Updated: 2016/02/05 14:14:17 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define EOF_ID 0
#define CMIN_ID 26
#define CMAX_ID 40
#define EOCALL_ID 42
#define BMIN_ID 44
#define BMAX_ID 58
#define EOBALL_ID 60
#define EOC_ID 62
#define EOB_ID 64

#define DEFAULT_COLOR1 9
#define DEFAULT_COLOR2 9

#define COLORS_STACK_SIZE 25

/*
** 'g_color_tags' contains color tags alias and escape codes. (see below)
** 'g_stacks' contains the colors stack for both font and background.
** 'g_ci' contains the current index for the font color stack.
** 'g_bi' contains the current index for the background color stack.
*/
/*
** 'get_color_tag_index' gets 'g_color_tags''s index for a given string
** 'track_escape_code' updates the stacks with existing color escape code.
** 'apply_previous_color' changes a color code to the previous color code.
** 'track_color_tags' substitute tags to escapes, and update stack.
** 'string_cat' writes in 'static str'. First/last call initiate/clean str.
*/

/*
** 'g_color_tags' :
** A lowercase tag changes font color.
** An uppercase tag changes the background color
** :eoc: and :eob: restore previous colors, updating the stack.
** :eoC:, :eoB: and :eof: empty the stack and restore default colors.
** Tags 2 to 7 apply special effects
** Tags 8 to 13 cancel special effects
*/

char const	g_color_tags[][6] = {
	"eof", "\033[0m",
	"lig", "\033[1m",
	"dar", "\033[2m",
	"und", "\033[4m",
	"LIG", "\033[5m",
	"inv", "\033[7m",
	"hid", "\033[8m",
	"eol", "\033[21m",
	"eod", "\033[22m",
	"eou", "\033[24m",
	"eoL", "\033[25m",
	"eoi", "\033[27m",
	"eoh", "\033[28m",
	"bla", "\033[30m",
	"red", "\033[31m",
	"gre", "\033[32m",
	"yel", "\033[33m",
	"blu", "\033[34m",
	"mag", "\033[35m",
	"cya", "\033[36m",
	"whi", "\033[37m",
	"eoC", "\033[30m",
	"BLA", "\033[40m",
	"RED", "\033[41m",
	"GRE", "\033[42m",
	"YEL", "\033[43m",
	"BLU", "\033[44m",
	"MAG", "\033[45m",
	"CYA", "\033[46m",
	"WHI", "\033[47m",
	"eoB", "\033[40m",
	"eoc", "\033[30m",
	"eob", "\033[40m",
};

static char	g_stacks[2][COLORS_STACK_SIZE];
static int	g_ci;
static int	g_bi;

int				coi(const char *str)
{
	int	i;

	i = 0;
	str++;
	while (i < NUM_C_TAGS * 2 && ft_strncmp(str, g_color_tags[i], 3))
		i += 2;
	return (i);
}

static void		track_escape_code(char *str)
{
	int		i;

	i = ft_atoi(str + 2);
	str += 2;
	if (!((i >= 30 && i <= 49) || i == 0) || i % 10 == 8 || !ft_isdigit(*str))
		return ;
	while (ft_isdigit(*str))
		str++;
	if (*str != 'm')
		return ;
	if (i == 39)
		g_ci = 0;
	else if (i == 49)
		g_bi = 0;
	else if (i == 0)
	{
		g_bi = 0;
		g_ci = 0;
	}
	else if (i < 40)
		g_stacks[0][++g_ci] = i - 30;
	else
		g_stacks[1][++g_bi] = i - 40;
	return ;
}

static void		apply_previous_color(char *char_p, int isfont)
{
	if (isfont)
	{
		if (g_stacks[0][!g_ci ? 0 : --g_ci] == -1)
			*char_p += DEFAULT_COLOR1;
		else
			*char_p += g_stacks[0][g_ci];
	}
	else
	{
		if (g_stacks[1][!g_bi ? 0 : --g_bi] == -1)
			*char_p += DEFAULT_COLOR1;
		else
			*char_p += g_stacks[1][g_bi];
	}
}

static size_t	track_color_tags(char **strp, char **s1p)
{
	int	j;

	if ((j = coi(*s1p)) >= NUM_C_TAGS * 2)
		return (0);
	ft_strcpy(*strp, g_color_tags[j + 1]);
	if (j == EOCALL_ID || j == EOF_ID)
		g_ci = 0;
	if (j == EOBALL_ID || j == EOF_ID)
		g_bi = 0;
	if (j >= CMIN_ID && j <= CMAX_ID)
		g_stacks[0][++g_ci] = (j - CMIN_ID) / 2;
	else if (j >= BMIN_ID && j <= BMAX_ID)
		g_stacks[1][++g_bi] = (j - BMIN_ID) / 2;
	else if (j == EOC_ID || j == EOCALL_ID)
		apply_previous_color(&(*strp)[3], 1);
	else if (j == EOB_ID || j == EOBALL_ID)
		apply_previous_color(&(*strp)[3], 0);
	*s1p += 5;
	(*strp) += (j < NUM_SMALLC_TAGS * 2) ? 4 : 5;
	return (4);
}

void			string_cat(char *s1, size_t len)
{
	static char	*str = NULL;

	if (!str || !s1)
	{
		if (!s1)
			str = NULL;
		else
			str = s1;
		g_stacks[1][0] = -1;
		g_stacks[0][0] = -1;
		g_ci = 0;
		g_bi = 0;
		return ;
	}
	while (len-- > 0)
	{
		if (len >= 4 && *s1 == ':' && s1[4] == ':' && coi(s1) < NUM_C_TAGS * 2)
			len -= track_color_tags(&str, &s1);
		else
		{
			if (len >= 4 && !ft_strncmp(s1, "\033[", 2))
				track_escape_code(s1);
			*str++ = *s1++;
		}
	}
}
