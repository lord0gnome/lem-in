/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_from_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:20:48 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/05 19:17:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		set_depth_recursive(t_l_rooms *end)
{
	int larray_len;
	int	depth;
	t_l_links	*new;
	t_l_links	*new2;

	depth = 0;
	new = (t_l_links *)malloc(sizeof(t_l_links));
	if (!new)
		return (0);
	new->roomptr = end;
	new->next = NULL;
	new->roomptr->depth = depth;
	depth++;
	while (new && new->roomptr)
	{
		larray_len = new->roomptr->larray_len;
		ft_putnbr(larray_len);
		while (larray_len--)
		{
			if (new->roomptr->larray[larray_len] && new->roomptr->larray[larray_len]->rptr->depth == -1)
			{
				ft_putstr("I like cake");
				ft_putstr(new->roomptr->larray[larray_len]->rptr->name);
			new->roomptr->larray[larray_len]->rptr->depth = depth;
			new2 = (t_l_links *)malloc(sizeof(t_l_links));
			new2->next = NULL;
			new->next = new2;
			new2->roomptr = new->roomptr->larray[larray_len]->rptr;
			}
		}
		new = new->next;
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
