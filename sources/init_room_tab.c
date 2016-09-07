/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:57:27 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 20:52:22 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_null_room_tab(t_l_rooms **tab, int nrooms)
{
	while (nrooms--)
		tab[nrooms] = NULL;
}

void	init_room_tab(t_l_data *d, t_l_rooms *first)
{
	t_l_rooms	*travel;
	int			index;

	index = 0;
	d->all = (t_l_rooms **)malloc(sizeof(t_l_rooms*) * (d->nrooms + 1));
	d->all[d->nrooms] = NULL;
	travel = first;
	set_null_room_tab(d->all, d->nrooms);
	while (travel && travel->startend != 1)
		travel = travel->next;
	if (travel)
	{
		d->all[d->nrooms - 1] = travel;
	ft_printf("start room [%s] placed in index %d of all[]\n", travel->name, d->nrooms - 1);
	}
	travel = first;
	while (travel && travel->startend != 2)
		travel = travel->next;
	if (travel)
	{
		d->all[0] = travel;
	ft_printf("end room [%s] placed in index %d of all[]\n", travel->name, 0);
	}
	travel = first;
	while (travel)
	{
		index = 0;
		while (travel && travel->startend != 0)
		{
			ft_printf("apparently, room [%s] is start or end\n", travel->name);
		travel = travel->next;
		}
		if (!travel)
			break ;
		while (d->all[index] != NULL && index < d->nrooms)
			index++;
	ft_printf("room [%s] placed in index %d of all[]\n", travel->name, index);
		d->all[index] = travel;
		travel = travel->next;
	}
	index = 0;
}
