/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:13:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/26 16:51:28 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	*init_ret(int **paths)
{
	int *ret;
	int	i;

	i = 0;
	while (paths[i])
		i++;
	ret = (int *)malloc(sizeof(int) * (i + 1));
	ret[i] = -1;
	i = 0;
	while (*paths++)
		ret[i++] = 0;
	return (ret);
}

void		add_to_dplen(int tot, t_l_data *d, int nant)
{
	tot = 0;
	while (tot < d->i2 && nant - 1 >= 0)
	{
		tot++;
		d->plen[d->i]++;
		nant--;
	}
}

int			det_paths2(int nant, t_l_data *d, int **paths, int ibck)
{
	int	tot;

	d->i2 = 0;
	if (paths[d->i + 1])
		d->i2 = ft_abs(paths[d->i][0] - paths[d->i + 1][0]);
	ibck = d->i;
	d->i = -1;
	tot = 0;
	while (++d->i <= ibck && d->i2 && nant)
	{
		d->i = d->i > ibck ? 0 : d->i;
		if (nant - d->i2 >= 0)
		{
			nant -= d->i2;
			d->plen[d->i] += d->i2;
		}
		else if (nant - 1 >= 0)
		{
			add_to_dplen(tot, d, nant);
		}
	}
	d->i = ibck;
	d->i++;
	return (nant);
}

int			*det_paths(int nant, int **paths, t_l_data *d)
{
	int	ibck;

	d->plen = init_ret(paths);
	d->i = 0;
	ibck = 0;
	while (paths[d->i] && nant)
	{
		nant = det_paths2(nant, d, paths, ibck);
	}
	d->i = 0;
	while (nant)
	{
		d->i = d->plen[d->i] == -1 ? 0 : d->i;
		d->plen[d->i]++;
		nant--;
		d->i++;
	}
	return (d->plen);
}
