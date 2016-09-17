/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:57:27 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/17 20:52:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		set_null_room_tab(t_l_rooms **tab, int nrooms)
{
	while (nrooms--)
		tab[nrooms] = NULL;
}

static void	set_end_and_start(t_l_data *d, t_l_rooms *travel, t_l_rooms *first)
{
	while (travel && travel->startend != 1)
		travel = travel->next;
	d->all[d->nrooms - 1] = travel;
	travel = first;
	while (travel && travel->startend != 2)
		travel = travel->next;
	d->all[0] = travel;
	travel = first;
}

void		init_room_tab(t_l_data *d, t_l_rooms *first)
{
	t_l_rooms	*travel;

	d->i = 0;
	d->all = (t_l_rooms **)malloc(sizeof(t_l_rooms*) * (d->nrooms + 1));
	d->all[d->nrooms] = NULL;
	travel = first;
	set_null_room_tab(d->all, d->nrooms);
	set_end_and_start(d, travel, first);
	while (travel)
	{
		d->i = 0;
		while (travel && travel->startend != 0)
			travel = travel->next;
		if (!travel)
			break ;
		while (d->all[d->i] != NULL && d->i < d->nrooms)
			d->i++;
		d->all[d->i] = travel;
		travel = travel->next;
	}
}
