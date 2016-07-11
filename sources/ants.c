/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/07/11 15:00:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	add_ants(t_l_data *d)
{
	t_l_ants	*new;
	t_l_ants	*prev;

	prev = NULL;
	if (d->nants <= 0)
		return (d->err->errno = 250);
	while (d->nants)
	{
		if ((new = (t_l_ants *)malloc(sizeof(t_l_ants))) == NULL)
			return (-1);
		new->id = d->nants - 1;
		new->next = prev;
		new->room = d->rooms;
		d->nants--;
		prev = new;
	}
	d->ants = new;
	return (d->nants);
}
