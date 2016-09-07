/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 12:40:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 16:11:41 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	get_link_list_length(t_l_links *list)
{
	int	ret;

	ret = 0;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}

int	set_larray_for_room(t_l_rooms *first)
{
	int			n;
	t_l_larray	**new;
	t_l_links	*links;

	if (!first)
		return (-1);
	links = first->links;
	n = get_link_list_length(first->links);
	first->larray_len = n;
	new = (t_l_larray **)malloc(sizeof(t_l_larray *) * (n + 1));
	if (!new)
		return (-1);
	new[n] = NULL;
	while (n--)
	{
		new[n] = (t_l_larray *)malloc(sizeof(t_l_larray));
		if (!new[n])
			return (-1);
		new[n]->rptr = links->roomptr;
		links = links->next;
	}
	first->larray = new;
	return (1);
}
