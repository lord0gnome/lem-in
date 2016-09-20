/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/20 17:13:07 by guiricha         ###   ########.fr       */
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
			ft_putnbr(i);
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

static void	make_p_table(t_l_p **path, t_l_data *d, int *tlen)
{
	t_l_p *trav;

	d->i2 = 0;
	while (path[d->i2])
		d->i2++;
	d->pints = (int **)malloc(sizeof(int *) * d->i2 + 1);
	*tlen = d->i2;
	d->pints[d->i2] = NULL;
	d->i2 = 0;
	while (path[d->i2])
	{
		d->i = 0;
		trav = path[d->i2];
		d->pints[d->i2] = (int *)malloc(sizeof(int) * (p_len(trav) + 1));
		d->pints[d->i2][p_len(trav)] = -2;
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

static int	t_len(int **paths)
{
	return (**paths);
}

static int	det_paths(int **paths, int *ants, t_l_data *d)
{
	int	*tabs;
	int index;
	int	nants;

	*ants = 0;
	tabs = (int *)malloc(sizeof(int) * t_len(paths) + 1);
	tabs[t_len(paths)] = -1;
	index = 0;
	while (index < t_len(paths))
		tabs[index++] = 0;
	index = 0;
	nants = d->nants;
	while (nants)
	{
		nants--;
	}




	return (0);
}

void	make_ants_go(t_l_data *d, t_l_p **p, int *ants)
{
	int	i;
	int	path;
	int	tantsout;
	int	tlen;

	tlen = 0;
	tantsout = 0;
	make_p_table(p, d, &tlen);
	path = 0;
	test_p_table(d->pints, d->all);
	det_paths(d->pints, ants, d);
	while (42)
	{
		i = 0;
		tantsout += 4;
		while (ants[i] != -2 && i < tantsout)
		{
			while (ants[i] == -3)
				i++;
			if (ants[i] == -2)
				return;
			path = 0;
			if (d->all[ants[i]]->startend == 2)
				ants[i] = -3;
			if (ants[i] != -3)
			{
				ft_printf("L%d-", i + 1);
				ants[i] = move_ant(ants[i], d->pints[path]);
				ft_printf("%s ", d->all[ants[i]]->name);
			}
			i++;
		}
		ft_putchar('\n');
	}
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
