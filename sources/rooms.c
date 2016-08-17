/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:06:43 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/17 21:00:03 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l_rooms	*create_rooms(t_l_data *d, char *name)
{
	t_l_rooms	*new;

	if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
		return (NULL);
	new->next = NULL;
	new->connections = NULL;
	new->x = d->cx;
	new->y = d->cy;
	new->name = ft_strdup(name);
	new->startend = d->command;
	d->rooms = new;
	return (new);
}

int		add_room(t_l_data *d, char *name)
{
	t_l_rooms	*new;
	t_l_rooms	*first;

	if ((d->rooms))
	{
		first = (d->rooms);
		while (first && first->next)
			first = first->next;
		if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
			return (0);
		new->next = NULL;
		new->connections = NULL;
		new->x = d->cx;
		new->y = d->cy;
		new->name = ft_strdup(name);
		new->startend = d->command;
		first->next = new;
	}
	else
		new = create_rooms(d, name);
	d->command = NOCOMMAND;
	return (1);
}
