/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_from_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:20:48 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 17:20:32 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		not_in_list(t_l_rooms *room, t_l_links *list)
{
	if (!room || !list)
		return (-1);
	while (list && list->roomptr)
	{
		if (!ft_strcmp(list->roomptr->name,room->name))
			return (0);
		list = list->next;
	}
	return (1);
}

int		set_depth_recursive(t_l_rooms *end)
{
	int larray_len;
	int	depth;
	t_l_links	*new;
	t_l_links	*new2;
	t_l_links	*strt;

	depth = 0;
	new = (t_l_links *)malloc(sizeof(t_l_links));
	if (!new)
		return (0);
	new->roomptr = end;
	new->next = NULL;
	new->roomptr->depth = depth;
	strt = new;
	depth++;
	while (new && new->roomptr)
	{
		larray_len = new->roomptr->larray_len;
		ft_printf("currently chcking room %s with larraylen of %d\n", new->roomptr->name, new->roomptr->larray_len);
		while (larray_len--)
		{
			ft_printf("current room checked is %s -- %d\n", new->roomptr->larray[larray_len]->rptr->name, new->roomptr->larray[larray_len]->rptr->depth);
			if (new->roomptr->larray[larray_len]->rptr->depth == -1)
				new->roomptr->larray[larray_len]->rptr->depth = depth;
			if (not_in_list(new->roomptr->larray[larray_len]->rptr, strt))
			{
				new2 = (t_l_links *)malloc(sizeof(t_l_links));
				new2->roomptr = new->roomptr->larray[larray_len]->rptr;
				new2->next = NULL;
				new->next = new2;
			}
		}
		new = new->next;
		depth++;
	}
	return (0);
}

void	set_room_depths_from_end(t_l_rooms *end)
{
	int	depth;
	int	larray_len;

	depth = 1;
	end->depth = 0;
	larray_len = end->larray_len;
	while (42)
	{
		while (larray_len)
		{
			larray_len--;
			end->larray[larray_len]->rptr->depth = depth;
		}
	}
}
