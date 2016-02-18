/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/12 10:34:29 by ngoguey           #+#    #+#             */
/*   Updated: 2015/08/12 17:30:21 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
#include "ft_debug.h"
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include "ft_set.h"

typedef struct		s_setint
{
	t_ftset_node	node;
	int				i;
}					t_setint;

typedef struct		s_setfloats
{
	t_ftset_node	node;
	int				index;
	float			f[8];
}					t_setfloats;

int			cmpint(t_setint const *max, t_setint const *min)
{
	return (min->i - max->i);
}


int			cmpfloats(t_setfloats const *max, t_setfloats const *min)
{
	/* return (memcmp(min->f, max->f, sizeof(float) * 1)); */
	return (memcmp(min->f, max->f, sizeof(float) * 8));
}

#define GETINT(N) ((N) == NULL ? 42 : ((t_setint*)(N))->i)
#define NODE(V) ((t_ftset_node*)(t_setint[1]){(t_setint)\
			  {(t_ftset_node){NULL, NULL, NULL, 0u}, (V)}})


#define NODEF(...) \
	((t_ftset_node*)(t_setfloats[1]){(t_setfloats)		 \
									 {(t_ftset_node){NULL, NULL, NULL, 0u} \
									  , 0								\
									  , {__VA_ARGS__}					\
									 }})


#define qprintf(...)

t_ui64		g_count = 0;
#define MAXLVL 9

#define H(N) ((N) == NULL ? 0 : (N)->height)

int		check_order_and_size_and_balance(t_ftset  *s, int curlevel)
{
	t_ftset_node 			*node;
	t_setint 				*cur;
	int						prev = -1;
	int						tot = 0;
	int						bal;

	node = fts_begin(s);
	while (node != NULL)
	{
		tot++;
		cur = (t_setint*)node;
		if (prev >= cur->i)
		{
			lprintf("BAD ORDER (%02dvs%02d)\n", prev, cur->i);
			return (1);
		}
		bal = H(node->r) - H(node->l);
		/* qprintf("(%d)", bal); */
		
		if (ABS(bal) > 1)
		{
			lprintf("TREE NOT BALANCED FFS\n");
			return (1);
		}
		node = fts_next(node);
	}
	if (tot != (int)s->size || tot != curlevel + 1)
	{
		lprintf("SET SIZE IS BAD");
		return (1);
	}
	return (0);
}

int		check_heights(t_ftset *s)
{
	t_ftset_node 			*node;
	
	if ((s->size > 0 && s->head->height != s->height))
	{
		lprintf("SET HEIGHT BAD");
		return (1);
	}
	node = fts_begin(s);
	qprintf("HEIGHTS: ");
	while (node != NULL)
	{
		
		int const		lh = node->l == NULL ? -1 : node->l->height;
		int const		rh = node->r == NULL ? -1 : node->r->height;
		int const		maxh_sons = MAX(lh, rh);
		
		qprintf("%02zu->", node->height);
		if ((maxh_sons == -1 && node->height != 1)
			|| (maxh_sons != -1 && (int)node->height != maxh_sons + 1))
		{
			lprintf("FAILED with node(%02i)[h=%d]{%p}  l(%02i)[h=%d]{%p}  r(%02i)[h=%d]{%p}"
			, GETINT(node)
			, (int)node->height
			, node
			
			, GETINT(node->l)
			, node->l == NULL ? 42 : (int)node->l->height
			, node->l
			
			, GETINT(node->r)
			, node->r == NULL ? 42 : (int)node->r->height
			, node->r
			);
			return (1);
		}
		node = fts_next(node);
	}
	qprintf("\n");
	return (0);
}

void		print_set(t_ftset  *s)
{
	t_ftset_node 			*node;
	t_setint 				*cur;

	node = fts_begin(s);
	qprintf("VALUES : ");
	while (node != NULL)
	{
		cur = (t_setint*)node;
		qprintf("%02d->", cur->i, node);
		node = fts_next(node);
	}
	qprintf("\n");
}


int		is_taken(int used[MAXLVL], int level, int const i)
{
	while (--level >= 0)
	{
		// qprintf("CMP: %d vs %d\n", used[level], i);
		if (used[level] == i)
			return (1);
	}
	return (0);
}
void build_set(t_ftset set[1], int used[MAXLVL], int const level)
{
	qprintf("\n");
	t_ftset_insertion	results[1];
	
	g_count++;
	fts_init_instance(set, sizeof(t_setint), &cmpint);
	int j;
	qprintf("GO: ");
	for (j = 0; j <= level; j++)
		qprintf("%d", used[j]);
	qprintf("\n");
	for (j = 0; j <= level; j++)
	{
		if (fts_insert(set, NODE(used[j]), results))
		{
			qprintf("EMEMBORDEL\n");
			exit(1);
		}
	}
	print_set(set);
	return ;
}

void test_all_comb(int used[MAXLVL], int const level)
{
	t_ftset				set[1];

	used[level] = 0;
	while (used[level] < MAXLVL)
	{
		if (!is_taken(used, level, used[level]))
		{
			if (level == MAXLVL - 1 || 1) //change here to test intermediate
			{
				build_set(set, used, level);
				if (check_order_and_size_and_balance(set, level))
				{
					lprintf("ORDER BROKEN\n");
					exit(1);
				}
				if (check_heights(set))
				{
					lprintf("HEIGHTS BROKEN\n");
					exit(1);
				}
				fts_release(set, NULL);
			}
			if (level < MAXLVL - 1)
				test_all_comb(used, level + 1);
		}
		// qprintf("\n");
		used[level]++;
	}
	return ;
}

#include <time.h>

int			main(void)
{
	srand(time(NULL));
	qprintf("hello world\n");
	if (1) //error tests
	{
		int					used[MAXLVL] = {0};

		test_all_comb(used, 0);
		lprintf("tests %llu combo", g_count);
	}
	if (0) // insert speed test
	{
		qprintf("hello\n");
		
		t_ftset				set[1];
	t_ftset_insertion	results[1];
		
		fts_init_instance(set, sizeof(t_setfloats), &cmpfloats);


		int i;
		int const num_vertex = 1000 * 1000 * 10;
		for (i = 0 ; i < num_vertex; i++)
		{
			float			f[8] = {
				(float)rand(), (float)rand(), (float)rand(), (float)rand(),
				(float)rand(), (float)rand(), (float)rand(), (float)rand(),
			};
			int const num_same = 1;
			int j;
			for (j = 0; j < num_same; j++)
			{
				fts_insert(set, NODEF(f[0],f[1],f[2],f[3],
									  f[4],f[5],f[6],f[7]), results);
				/* qprintf("ins(%d)", results->inserted); */
			
			}
		}
		lprintf("done size:%zu  height:%zu", set->size, set->height);
		/* lprintf("height: %d", check_heights(set)); */
		/* lprintf("check_order_and_size_and_balance: %d", */
				/* check_order_and_size_and_balance(set, set->size - 1)); */
		
		
		
	}
	return (0);
}
