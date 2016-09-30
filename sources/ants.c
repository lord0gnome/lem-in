/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/30 10:59:25 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	prepare_ants(t_l_data *d, t_l_p **p, int *ants)
{
	make_p_table(p, d);
	d->plen = det_paths(d->nants, d->pint, d);
	convert_ants_to_neg_indexes(d->ants, d->plen);
	d->scone = test_scone(d->pint, ants, d, d->plen);
	if (d->scone)
		ants = d->ants;
	d->antn = initantn(ants, d->nants, 0);
	if (!d->anti)
	{
		d->err->errno = 100;
		exitfunc(d->err->errno, d);
	}
	d->anti = initanti(d->antn, d->nants);
	if (!d->anti)
	{
		d->err->errno = 100;
		exitfunc(d->err->errno, d);
	}
}

static void	make_ants_go_loop(t_l_data *d, int i, int pi, int *ants)
{
	while (d->nants)
	{
		d->f = 0;
		i = 0;
		while (i < d->nants)
		{
			pi = 0;
			while (d->anti[i] >= get_i(d->plen, pi + 1))
				pi++;
			if (ants[d->anti[i]] > 0 && ants[d->anti[i]] < d->pint[pi][0])
			{
				ft_printf(d->f ? " L%d-%s" : "L%d-%s", i + 1,
						d->all[d->pint[pi][1 + ants[d->anti[i]]]]->name);
				d->f = 1;
			}
			ants[d->anti[i]]++;
			i++;
		}
		if (!d->f)
			break ;
		ft_putstr("\n");
	}
}

void		make_ants_go(t_l_data *d, t_l_p **p, int *ants)
{
	int	i;
	int	pi;

	prepare_ants(d, p, ants);
	if (d->scone)
		ants = d->ants;
	pi = 0;
	i = -1;
	while (++i < d->nants)
		ants[d->anti[i]] += 2;
	make_ants_go_loop(d, i, pi, ants);
}

int			make_ants(t_l_data *d)
{
	int	*ants;
	int	index;

	if ((ants = (int *)malloc(sizeof(int) * (d->nants + 1))) == NULL)
		return (d->err->errno = 100);
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
