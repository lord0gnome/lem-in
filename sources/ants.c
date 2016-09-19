/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 13:20:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
