/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 21:33:59 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/17 21:35:28 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		glur(t_l_rooms *room, t_l_rooms **all, t_l_data *d)
{
	int	i;
	int	z;
	int	lowestdindex;

	lowestdindex = -1;
	z = -1;
	i = 0;
	d->i = 0;
	while (i++ < room->lindexes[0])
	{
		if (z == -1 && all[room->lindexes[i]]->used == 0)
		{
			z = all[room->lindexes[i]]->depth;
			lowestdindex = room->lindexes[i];
		}
		if (all[room->lindexes[i]]->depth < z && !all[room->lindexes[i]]->used)
		{
			z = all[room->lindexes[i]]->depth;
			lowestdindex = room->lindexes[i];
		}
	}
	return (lowestdindex);
}
