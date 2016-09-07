/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:57:27 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 18:21:54 by guiricha         ###   ########.fr       */
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
	while (travel && travel->startend != 1)
		travel = travel->next;
	if (travel)
		d->all[d->nrooms - 1] = travel;
	set_null_room_tab(d->all, d->nrooms);
	ft_printf("end room [%s] placed in index %d of all[]\n", travel->name, d->nrooms - 1);
	travel = first;
	while (travel && travel->startend != 2)
		travel = travel->next;
	if (travel)
		d->all[0] = travel;
	ft_printf("start room [%s] placed in index %d of all[]\n", travel->name, 0);
	while (first)
	{
		index = 0;
		if (first->startend != 0)
			first = first->next;
		if (!first)
			return ;
		while (d->all[index] != NULL)
			index++;
	ft_printf("room [%s] placed in index %d of all[]\n", first->name, index);
		d->all[index] = first;
		first = first->next;
	}
	index = 0;
	while (index < d->nrooms)
	{
ft_putstr(d->all[index++]->name);
	}
}
