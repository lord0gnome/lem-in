/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:06:43 by guiricha          #+#    #+#             */
/*   Updated: 2016/07/04 17:00:43 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	add_room(t_l_data *d, char *name)
{
	t_l_rooms	*new;

	if (d->rooms)
	{
		while (d->rooms->next)
			d->rooms = d->rooms->next;
		if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
			return (-1);
		d->rooms->next = new;
		new->next = NULL;
		new->connections = NULL;
		new->x = d->cx;
		new->y = d->cy;
		new->name = ft_strdup(name);
		new->startend = d->command;
	}
	else
	{
		if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
			return (-1);
		new->next = NULL;
		new->connections = NULL;
		new->name = ft_strdup(name);
		new->startend = d->command;
		new->x = d->cx;
		new->y = d->cy;
		d->rooms = new;
	}
	return (1);
}
