/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/24 16:23:58 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	test_p_table(int **table, t_l_rooms **all)
{
	int	i;

	while (*table)
	{
		i = 0;
		while ((*table)[i] != -2)
		{
			ft_printf("room at this index is %s\n", all[(*table)[i]]->name);
			i++;
		}
		ft_printf("bing\n");
		table++;
	}
}

static int	p_len(t_l_p *p)
{
	int	ret;

	ret = 0;
	while (p)
	{
		ret++;
		p = p->n;
	}
	return (ret);
}

static void	make_p_table(t_l_p **path, t_l_data *d)
{
	t_l_p *trav;

	d->i2 = 0;
	while (path[d->i2])
		d->i2++;
	d->pints = (int **)malloc(sizeof(int *) * d->i2 + 1);
	d->pints[d->i2] = NULL;
	d->i2 = 0;
	while (path[d->i2])
	{
		d->i = 0;
		trav = path[d->i2];
		d->pints[d->i2] = (int *)malloc(sizeof(int) * (p_len(trav) + 2));
		d->pints[d->i2][p_len(trav) + 1] = -2;
		d->pints[d->i2][d->i++] = p_len(trav);
		while (trav)
		{
			d->pints[d->i2][d->i] = trav->room;
			trav = trav->n;
			d->i++;
		}
		d->i2++;
	}
}

int	move_ant(int ant ,int *path)
{
	while ((*path) != -2)
	{
		if (*path == ant && *(path + 1) != -2)
		{
			path++;
			return (*path);
		}
		path++;
	}
	return (ant);
}

void	convert_ants_to_neg_indexes(int *ants, int *paths)
{
	int counter;
	int	i;

	i = 0;	
	while (*paths != -1)
	{
		counter = -(*paths);
		while (counter < 0)
		{
			ants[i++] = (counter++);	
		}
		paths++;
	}
}

int		get_i(int *paths, int pi)
{
	int ret;
	int	m;

	ret = 0;
	m = 0;
	while (paths[m] != -1 && m < pi)
	{
		ret += paths[m];
		m++;
	}
	return (ret);
}

int	get_highest(int *ants, int nants, int phighest)
{
	int	highest;

	highest = *ants;
	while (nants--)
	{
		highest = highest < *ants && *ants <= phighest ? *ants : highest;
		ants++;
	}
	return (highest);
}

int	*initantn(int *ants, int nants)
{
	int	n;
	int	i;
	int	highest;
	int	hb;
	int *antn;

	n = 0;
	i = 0;
	antn = (int *)malloc(sizeof(int) * nants + 1);
	antn[nants] = -1;
	hb = ants[n];
	while (ants[n])
	{
		hb = ants[n] > hb ? ants[n] : hb;
		n++;
	}
	hb++;
	n = 0;
	highest = get_highest(ants, nants, hb);
	while (n < nants)
	{
		i = 0;
		while (i < nants)
		{
			if (ants[i] == highest)
				antn[i] = ++n;
			i++;
		}
		hb = highest - 1;
		highest = get_highest(ants, nants, hb);
	}
	i = 0;
	return (antn);
}

char	test_scone(int **pints)
{
	int	i;

	i = 0;
	while (pints[i])
		if (pints[i++][0] == 2)
			return (1);
	return (0);
}

void	make_ants_go(t_l_data *d, t_l_p **p, int *ants)
{
	int	i;
	int	pi;
	int	imax;
	int	*paths;
	int	*antn;
	int	antput;

	make_p_table(p, d);
	paths = det_paths(d->nants, d->pints);
	convert_ants_to_neg_indexes(ants, paths);
	antn = initantn(ants, d->nants);
	i = 0;
	d->scone = test_scone(d->pints);
	antput = 0;
	while (d->nants)
	{
		pi = 0;
			antput = 0;
		while (paths[pi] != -1)
		{
			i = get_i(paths, pi);
			imax = i + paths[pi];
			while (i < imax)
			{
				if (ants[i] > 1 && ants[i] <= d->pints[pi][0])
				{
					if (!d->first && !d->scone)
						ft_putchar(' ');
					ft_printf("L%d-%s", antn[i], d->all[d->pints[pi][ants[i]]]->name);
					antput = 1;
				if (d->all[d->pints[pi][ants[i]]]->startend == 2)
					d->nants--;
				if (d->nants && d->scone)
					ft_putchar(' ');
					d->first = 0;
				}
				ants[i]++;
				i++;
			}
			pi++;
		}
		d->first = 1;
		if (!d->nants)
			return ;
		if (!d->scone && antput)
			ft_putchar('\n');
	}
	if (d->scone)
		ft_putchar('\n');
}

int		p_a_st(int *ants, t_l_rooms **all, int *allindex)
{
	while (*allindex != -2)
	{
		if (all[*allindex]->startend == START)
			break ;
		allindex++;
	}
	while (*ants != -2)
	{
		*ants = *allindex;
		ants++;
	}
	return (1);
}

int		make_ants(t_l_data *d)
{
	int	*ants;
	int	index;

	if ((ants = (int *)malloc(sizeof(int) * (d->nants + 1))) == NULL)
		return (0);
	ants[d->nants] = -2;
	index = 0;
	while (index < d->nants)
	{
		ants[index] = -1;
		index++;
	}
	d->ants = ants;
	return (1);
}
