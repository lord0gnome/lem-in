/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:10:14 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/02 14:46:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	rec_set_depths(t_l_rooms *start, int *depth)
{
	if (start->used)
		return ;
	start->used = 1;
	*depth = start->depth + 1;
	ft_printf("calling rec func on %s ", start->name);
	if (start->depth == -1 || start->depth > *depth)
	{
		ft_printf("whose depth was %d and its ", start->depth);
		start->depth = *depth;
		ft_printf("depth has been set at %d\n", start->depth);
	}
	else
		ft_printf("depth has not been set and stays at %d\n", start->depth);
	while (start->links)
	{
		rec_set_depths(start->links->roomptr, depth);
		start->links = start->links->next;
	}
}

void	set_depths(t_l_rooms *start)
{
	int depth;
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
