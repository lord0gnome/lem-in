/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/22 19:26:04 by guiricha         ###   ########.fr       */
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
		d->pints[d->i2] = (int *)malloc(sizeof(int) * (p_len(trav) + 2));
		d->pints[d->i2][p_len(trav) + 1] = -2;
		d->pints[d->i2][d->i++] = p_len(trav) - 2;
		ft_putnbr(d->pints[d->i2][0]);
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

void	make_do(int *ants, int nants, int *antpaths, t_l_rooms **all)
{
	int	i;
	int	npaths;
	int	pindex;

	npaths = 0;
	i = nants;
	while (antpaths[npaths] != -1)
		npaths++;
	i = 0;
	while (ants[i] != -2)
	{
		pindex = 0;
		if (ants[i] != -3 && all[ants[i]]->startend != 1)
		{
		}
	}
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
		//	ft_printf("ant number %d is now = to %d\n", i + 1, counter);
			ants[i++] = counter++;	
		}
		paths++;
	}
}

void	convert_ants_to_paths(int *paths, int *ants)
{
	int	i;
	int	pin;

	i = 0;
	pin = 0;
	while (ants[i] != -2)
	{
		pin = paths[pin] == -1 ? 0 : pin;
		while (paths[pin] != -1)
		{
			ft_printf("paths[pin] value is %d\n", paths[pin]);
			if (paths[pin])
			{
				ants[i] = pin;
				ft_printf("setting ant number %d to %dst path\n", i + 1, pin);
				paths[pin]--;
				i++;
				pin++;
				break;
			}
			pin++;
		}
	}
}

void	make_ants_go(t_l_data *d, t_l_p **p, int *ants)
{
	int	i;
	int	increm;
	int	path;
	int	tantsout;
	int	tlen;
	int	*paths;
	int npaths;
	int n;

	tlen = 0;
	tantsout = 0;
	make_p_table(p, d, &tlen);
	//test_p_table(d->pints, d->all);
	paths = det_paths(d->nants, d->pints);
	npaths = 0;
	while (paths[npaths] != -1)
		npaths++;
	convert_ants_to_neg_indexes(ants, paths);
//	convert_ants_to_paths(paths,ants);
	i = 0;
	increm = 0;
	while (42)
	{
		n = 0;
		i = 0;
		while (ants[i] >= 0 && ants[i] < d->pints[n][0])
		{
			ft_printf("ant number is %d and room is %s\n", ants[i], d->all[d->pints[0][i]]->name);
			ft_wait(10);
			i++;
		}
		while (i < d->nants)
		{
			ants[i++]++;
		}
		i = 0;
	}
	path = 0;

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
