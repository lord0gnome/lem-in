/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:03:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/27 15:33:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	remove_link(t_l_links *room, t_l_links *remove)
{
	while (room && room->next && room->next != remove)
		room = room->next;
	if (room && remove)
		room->next = remove->next;
	free(remove);
	remove = NULL;
}

static void	test_duplicates(t_l_rooms *room)
{
	t_l_links	*cl;
	t_l_links	*rbck;

	cl = room->links;
	rbck = room->links;
	while (rbck)
	{
		cl = rbck;
		while (cl)
		{
			cl = cl->next;
			if (cl && rbck && cl != rbck && rbck->roomptr == cl->roomptr)
			{
				remove_link(room->links, cl);
				break ;
			}
		}
		if (cl)
			continue ;
		rbck = rbck->next;
	}
}

void		remove_dup_paths(t_l_rooms **all, int nrooms)
{
	int			i;
	t_l_links	*curr;

	i = 0;
	while (i < nrooms)
	{
		test_duplicates(all[i]);
		curr = all[i]->links;
		while (curr)
			curr = curr->next;
		i++;
	}
}

int			r_ncse(t_l_rooms **all, int *allindex, t_l_data *d)
{
	int	*aib;

	while (all[*allindex])
	{
		if (all[*allindex]->depth == -1)
		{
			aib = allindex;
			d->nrooms--;
			while (*allindex != -2)
			{
				*allindex = *(allindex + 1);
				allindex++;
			}
			allindex = aib;
		}
		allindex++;
	}
	return (1);
}
