/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:01:09 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/30 14:27:28 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		init_link(t_l_rooms *init, t_l_rooms *link)
{
	t_l_links	*lr1to2;

	if ((lr1to2 = (t_l_links *)malloc(sizeof(t_l_rooms))) == NULL)
		return (0);
	lr1to2->next = NULL;
	lr1to2->roomptr = link;
	init->links = lr1to2;
	return (1);
}

int		new_link_for_one(t_l_rooms *r1, t_l_rooms *r2)
{
	t_l_links	*new1;
	t_l_links	*lr1to2;

	lr1to2 = r1->links;
	if (!(new1 = (t_l_links *)malloc(sizeof(t_l_links))))
		return (0);
	while (lr1to2->next)
		lr1to2 = lr1to2->next;
	new1->next = NULL;
	new1->roomptr = r2;
	lr1to2->next = new1;
	return (1);
}

int		new_link(t_l_rooms *r1, t_l_rooms *r2)
{
	t_l_links	*new1;
	t_l_links	*new2;
	t_l_links	*lr1to2;
	t_l_links	*lr2to1;

	lr1to2 = r1->links;
	lr2to1 = r2->links;
	if (!(new1 = (t_l_links *)malloc(sizeof(t_l_links))))
		return (0);
	if (!(new2 = (t_l_links *)malloc(sizeof(t_l_links))))
		return (0);
	while (lr1to2->next)
		lr1to2 = lr1to2->next;
	while (lr2to1->next)
		lr2to1 = lr2to1->next;
	new1->next = NULL;
	new2->next = NULL;
	new1->roomptr = r2;
	new2->roomptr = r1;
	lr1to2->next = new1;
	lr2to1->next = new2;
	return (1);
}

int		add_link(t_l_rooms *r1, t_l_rooms *r2, t_l_data *d)
{
	if (!r1 || !r2)
		return (d->err->errno = 150);
	if (!r1->links && !r2->links)
	{
		init_link(r1, r2);
		init_link(r2, r1);
	}
	else if (!r1->links)
	{
		init_link(r1, r2);
		new_link_for_one(r2, r1);
	}
	else if (!r2->links)
	{
		init_link(r2, r1);
		new_link_for_one(r1, r2);
	}
	else if (r1->links && r2->links)
		new_link(r1, r2);
	return (0);
}
