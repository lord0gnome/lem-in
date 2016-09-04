/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:10:14 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/04 16:17:37 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	rec_set_depths(t_l_rooms *start, int depth)
{
	t_l_links	*links;

	if (start->used == 1)
		return ;
	if (start->depth == -1)
		start->depth = depth;
	start->used = 1;
	links = start->links;
	depth++;
	while (links)
	{
		if (depth < links->roomptr->depth)
			links->roomptr->depth = depth;
		links = links->next;
	}
	links = start->links;
	while (links)
	{
		rec_set_depths(links->roomptr, depth);
		links = links->next;
	}
}

void	set_depths(t_l_rooms *start)
{
	int			depth;
	t_l_links	*links;

	links = NULL;
	depth = 0;
	while (start && !start->used)
	{
		if (!start->used && start->depth == -1)
		{
			start->depth = depth;
			depth++;
		}
		start->used = 1;
		links = start->links;
		while (links)
		{
			if (links->roomptr->depth == -1)
				links->roomptr->depth = depth;
			links->roomptr->used = 1;
			while (links && links->roomptr->used)
				links = links->next;
		}
		start = start->links->roomptr;
	}
}
