/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:19:13 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/14 18:52:46 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_depth(t_l_rooms **all, t_l_data *d)
{
	int	irooms;
	int ilinks;
	int	ir2;
	int	*indexes;
	t_l_rooms *current;


	irooms = 0;
	indexes = (int *)malloc(sizeof(int) * d->nrooms + 1);
	indexes[0] = 0;
	while (++irooms < d->nrooms)
		indexes[irooms] = -1;
	indexes[irooms] = -2;
	irooms = 0;
	ir2 = 0;
	while (indexes[irooms] != -2 && indexes[irooms] != -1)
	{
		current = all[indexes[irooms]];
		if (current->depth == -1)
			current->depth = 0;
		ilinks = 0;
		while (ilinks++ < current->lindexes[0])
		{
			if (all[current->lindexes[ilinks]]->depth == -1 ||
					current->depth + 1 < all[current->lindexes[ilinks]]->depth)
			{
				indexes[++ir2] = current->lindexes[ilinks];
				all[current->lindexes[ilinks]]->depth = current->depth + 1;
			}
		}
		irooms++;
	}
	d->allindex = indexes;
}
