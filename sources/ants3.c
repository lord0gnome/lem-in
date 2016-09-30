/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:55:20 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/30 11:45:35 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			get_highest(int *ants, int nants, int phighest)
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

int			*initantn(int *ants, int nants, int i)
{
	int	n;
	int	highest;
	int	hb;
	int *antn;

	n = -1;
	if ((antn = (int *)malloc(sizeof(int) * nants + 1)) == NULL)
		return (NULL);
	antn[nants] = -1;
	hb = ants[++n];
	while (ants[n++])
		hb = ants[n] > hb ? ants[n] : hb;
	hb++;
	n = 0;
	highest = get_highest(ants, nants, hb);
	while (n < nants)
	{
		i = -1;
		while (++i < nants)
			if (ants[i] == highest)
				antn[i] = ++n;
		hb = highest - 1;
		highest = get_highest(ants, nants, hb);
	}
	return (antn);
}

char		test_scone(int **pi, int *a, t_l_data *d, int *pa)
{
	int	i;

	i = 0;
	while (pi[i])
	{
		if (pi[i][0] == 2)
		{
			pi[0] = pi[i];
			pi[1] = NULL;
			pa[0] = d->nants;
			pa[1] = -1;
			free(a);
			make_ants(d);
			return (1);
		}
		i++;
	}
	return (0);
}

int			lowest(int *antn, int *plowest)
{
	int	i;
	int	ret;

	i = 0;
	ret = -1;
	while (antn[i] != -1)
	{
		if (antn[i] == *plowest + 1)
			ret = i;
		i++;
	}
	*plowest = antn[ret];
	return (ret);
}

int			*initanti(int *antn, int nants)
{
	int	i;
	int	set;
	int	lo;
	int	*anti;

	if ((anti = (int *)malloc(sizeof(int) * (nants + 1))) == NULL)
		return (NULL);
	anti[nants] = -1;
	i = 0;
	set = 0;
	lo = 0;
	while (nants)
	{
		set = lowest(antn, &lo);
		anti[i] = set;
		i++;
		nants--;
	}
	return (anti);
}
