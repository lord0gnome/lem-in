/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:19:13 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/11 19:31:57 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_depth(t_l_rooms **all, t_l_data *d)
{
	int	irooms;
	int ilinks;
	int	ir2;
	int	*indexes;
	int	depth;
	int	dlevel;
	t_l_rooms *current;


	dlevel = 1;
	irooms = 0;
	indexes = (int *)malloc(sizeof(int) * d->nrooms + 1);
	indexes[0] = 0;
	while (++irooms < d->nrooms)
		indexes[irooms] = -1;
	indexes[irooms] = -2;
	irooms = 0;
	ir2 = 0;
	depth = 0;
	while (indexes[irooms] != -2 && indexes[irooms] != -1)
	{
		current = all[indexes[irooms]];
		if (current->depth == -1)
			current->depth = depth;
		if (depth == 0)
			depth++;
		ilinks = 0;
		while (ilinks++ < current->lindexes[0])
		{
			if (all[current->lindexes[ilinks]]->depth == -1)
			{
				indexes[++ir2] = current->lindexes[ilinks];
				all[current->lindexes[ilinks]]->depth = depth;
				dlevel--;
			}
		}
		if (dlevel <= 0)
		{
			dlevel = current->lindexes[0];
			depth++;
		}
		irooms++;
	}
	d->allindex = indexes;
}
