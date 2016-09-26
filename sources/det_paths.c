/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:13:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/26 11:31:35 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int *init_ret(int **paths)
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

void	print_path_ant_distribution(int *path_ants)
{
	int i;

	i = 0;
	while (*path_ants != -1)
	{
		ft_printf("index %d has %d ants in it\n", i++, *path_ants);
		path_ants++;
	}
}


int	*det_paths(int nant, int **paths, t_l_data *d)
{
	int	diff;
	int *ret;
	int	tot;

	ret = init_ret(paths);
	d->i = 0;
	while (paths[d->i] && nant)
	{
		diff = 0;
		if (paths[d->i + 1])
			diff = ft_abs(paths[d->i][0] - paths[d->i + 1][0]);
		d->i2 = d->i;
		d->i = 0;
		while (d->i <= d->i2 && diff && nant)
		{
			d->i = d->i > d->i2 ? 0 : d->i;
			if (nant - diff >= 0)
			{
				nant -= diff;
				ret[d->i] += diff;
			}
			else if (nant - 1 >= 0)
			{
				tot = 0;
				while (tot < diff && nant - 1 >= 0)
				{
					tot++;
					ret[d->i]++;
					nant--;
				}
			}
			d->i++;
		}
		d->i = d->i2;
		d->i++;
	}
	d->i = 0;
	while (nant)
	{
		d->i = ret[d->i] == -1 ? 0 : d->i;
		ret[d->i]++;
		nant--;
		d->i++;
	}
	return (ret);
}
