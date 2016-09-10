/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 14:19:13 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/10 16:18:41 by guiricha         ###   ########.fr       */
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
	t_l_rooms *current;


	irooms = 0;
	indexes = (int *)malloc(sizeof(int) * d->nrooms + 1);
	indexes[0] = 0;
	while (++irooms < d->nrooms)
		indexes[irooms] = -1;
	indexes[irooms] = -2;
	irooms = 0;
	ir2 = 0;
	depth = 0;
	while (indexes[irooms] != -2)
	{
		current = all[indexes[irooms]];
		if (current->depth == -1)
			current->depth = depth;
		ft_printf("current room is %s\n", current->name);
		ilinks = 0;
		depth++;
		while (ilinks++ < current->lindexes[0])
		{
			if (all[current->lindexes[ilinks]]->depth == -1)
			{
				ft_printf("trying to add %s to next of tab\n", all[current->lindexes[ilinks]]->name);
				indexes[++ir2] = current->lindexes[ilinks];
				all[current->lindexes[ilinks]]->depth = depth;
			}
		}
		irooms++;
	}
}
