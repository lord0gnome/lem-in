/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:01:09 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/18 17:10:52 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		create_links_both_empty(t_l_rooms *r1, t_l_rooms *r2)
{
	t_l_links	*lr1to2;
	t_l_links	*lr2to1;

	if ((lr1to2 = (t_l_links *)malloc(sizeof(t_l_rooms))) == NULL)
		return (NULL);
	if ((lr2to1 = (t_l_links *)malloc(sizeof(t_l_rooms))) == NULL)
		return (NULL);
	lr1to2->next = NULL;
	lr1to2->roomptr = r2;
	lr2to1->next = NULL;
	lr2to1->roomptr = r1;
	r1->links = lr1to2;
	r2->links = lr2to1;
	return (1);
}

int		add_link(t_l_rooms *r1, t_l_rooms *r2)
{
	t_l_rooms	*new;
	t_l_rooms	*first;
	t_l_links	*lr1to2;
	t_l_links	*lr2to1;

	if (r1->links && r2->links)
	{
		while (r1->links->next)
			r1->links = r1->links->next;
		while (r2->links->next)
			r2->links = r2->links->next;
		if ((lr1to2 = (t_l_links *)malloc(sizeof(t_l_rooms))) == NULL)
			return (NULL);
		if ((lr2to1 = (t_l_links *)malloc(sizeof(t_l_rooms))) == NULL)
			return (NULL);
	}
	{
		first = (d->rooms);
		while (first && first->next)
			first = first->next;
		if ((new = (t_l_rooms *)malloc(sizeof(t_l_rooms))) == NULL)
			return (0);
		new->next = NULL;
		new->links = NULL;
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
