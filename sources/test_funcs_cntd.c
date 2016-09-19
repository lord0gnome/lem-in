/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs_cntd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:42:28 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 12:49:46 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	remove_noconnects(t_l_rooms *start, t_l_data *d)
{
	t_l_rooms *previous;
	t_l_rooms *tofree;

	previous = NULL;
	while (start)
	{
		tofree = NULL;
		if (start->links == NULL && (d->nrooms--) != -42)
		{
			if (previous)
				previous->next = start->next;
			else if (start == d->frst)
				d->rooms = start->next;
			tofree = start;
		}
		previous = start;
		start = start->next;
		if (tofree)
		{
			free(tofree);
			previous = NULL;
		}
	}
}
