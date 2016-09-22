/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 13:13:06 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/22 17:45:03 by guiricha         ###   ########.fr       */
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

int	*det_paths(int nant, int **paths)
{
	int	i;
	int	diff;
	int *ret;
	int	ibck;
	int	tot;

	ret = init_ret(paths);
	i = 0;
	while (paths[i] && nant)
	{
		diff = 0;
		if (paths[i + 1])
			diff = ft_abs(paths[i][0] - paths[i + 1][0]);
		ft_printf("the diff is currently %d\n", diff);
		ibck = i;
		i = 0;
		while (i <= ibck && diff && nant)
		{
			i = i > ibck ? 0 : i;
			if (nant - diff >= 0)
			{
				nant -= diff;
				ret[i] += diff;
			}
			else if (nant - 1 >= 0)
			{
				tot = 0;
				while (tot < diff && nant - 1 >= 0)
				{
					tot++;
					ret[i]++;
					nant--;
				}
			}
			i++;
		}
		i = ibck;
		i++;
	}
	i = 0;
	while (nant)
	{
		i = ret[i] == -1 ? 0 : i;
		ret[i]++;
		nant--;
		i++;
	}
	print_path_ant_distribution(ret);
	return (ret);
}
