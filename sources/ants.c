/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 17:31:02 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	test_p_table(int **table, t_l_rooms **all)
{
	while (*table)
	{
		while (**table != -2)
		{
			ft_printf("room at this index is %s\n", all[**table]->name);
			*table = *table + 1;
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

static int	has_ant(int room, int *ants)
{
	while (*ants != -2)
	{
		if (room == *ants)
			return (1);
		ants++;
	}
	return (0);
}

int	move_ant(int ant ,int *path, int *ants)
{
	while ((*path) != -2)
	{
		if (*path == ant && *(path + 1) != -2)
		{
			path++;
			if (!has_ant(*(path), ants))
				return (*path);
			else
				break ;
		}
		path++;
	}
	return (ant);
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
	while (42)
	{
		i = 0;
		tantsout += tlen;
		while (ants[i] != -2 && i < tantsout)
		{
			while (ants[i] == -3 && ants[i] != -2)
				i++;
			if (ants[i] == -2)
				return;
			path = d->pints[path] == NULL ? 0 : path;
			ft_printf("L%d-", i + 1);
			ants[i] = move_ant(ants[i], d->pints[path], ants);
			ft_printf("%s ", d->all[ants[i]]->name);
			ft_wait(50);
			if (d->all[ants[i]]->startend == 2)
				ants[i] = -3;
			path++;
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
