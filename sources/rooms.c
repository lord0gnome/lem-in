/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:06:43 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/28 17:17:47 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l_rooms	*create_rooms(t_l_data *d, char *name)
{
	t_l_rooms	*new;

	if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
		return (NULL);
	new->next = NULL;
	new->links = NULL;
	new->larray = NULL;
	new->lindexes = NULL;
	new->used = 0;
	new->larray_len = 0;
	new->x = d->cx;
	new->y = d->cy;
	new->depth = -1;
	new->name = ft_strdup(name);
	new->startend = d->command;
	d->rooms = new;
	d->command = NOCOMMAND;
	return (new);
}

static void	set_room_data(t_l_rooms *new, t_l_data *d)
{
	new->next = NULL;
	new->links = NULL;
	new->larray = NULL;
	new->lindexes = NULL;
	new->larray_len = 0;
	new->depth = -1;
	new->used = 0;
	new->x = d->cx;
	new->y = d->cy;
	new->startend = d->command;
	d->command = NOCOMMAND;
}

int			add_room(t_l_data *d, char *name)
{
	t_l_rooms	*new;
	t_l_rooms	*first;

	if ((d->rooms))
	{
		first = (d->rooms);
		while (first)
		{
			if (!ft_strcmp(first->name, name) ||
					(d->cy == first->y && d->cx == first->x))
				return (0);
			if (first->next)
				first = first->next;
			else
				break ;
		}
		if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
			return (0);
		set_room_data(new, d);
		new->name = ft_strdup(name);
		first->next = new;
	}
	else
		create_rooms(d, name);
	return (1);
}
