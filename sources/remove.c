/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:03:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 11:29:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	r_notconstartend(t_l_rooms **all, int *allindex, t_l_data *d)
{
	int	*aib;

	while (all[*allindex])
	{
		if (all[*allindex]->depth == -1)
		{
			aib = allindex;
			d->nrooms--;
			while (*allindex != -2)
			{
				*allindex = *(allindex + 1);
				allindex++;
			}
			allindex = aib;
		}
		allindex++;
	}
	return (1);
}
