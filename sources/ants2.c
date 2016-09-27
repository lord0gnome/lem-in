/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:54:05 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/26 17:03:12 by guiricha         ###   ########.fr       */
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
		ft_printf("going to next index of tab**\n");
		table++;
	}
}

int		pl(t_l_p *p)
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

int		make_p_table(t_l_p **path, t_l_data *d)
{
	t_l_p *t;

	d->i2 = 0;
	while (path[d->i2])
		d->i2++;
	if ((d->pint = (int **)malloc(sizeof(int *) * d->i2 + 1)) == NULL)
		return (d->err->errno = 100);
	d->pint[d->i2] = NULL;
	d->i2 = -1;
	while (path[++d->i2])
	{
		d->i = 0;
		t = path[d->i2];
		if ((d->pint[d->i2] = (int *)malloc(sizeof(int) * (pl(t) + 2))) == NULL)
			return (d->err->errno = 100);
		d->pint[d->i2][pl(t) + 1] = -2;
		d->pint[d->i2][d->i++] = pl(t);
		while (t)
		{
			d->pint[d->i2][d->i] = t->room;
			t = t->n;
			d->i++;
		}
	}
	return (0);
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
			ants[i++] = (counter++);
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
