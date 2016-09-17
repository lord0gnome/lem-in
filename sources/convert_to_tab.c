/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 12:40:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/17 20:32:00 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			get_link_list_length(t_l_links *list)
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

static int	*make_new(int n)
{
	int	*new;

	new = (int *)malloc(sizeof(int) * (n + 2));
	if (!new)
		return (new);
	new[0] = n;
	new[n + 1] = -1;
	return (new);
}

int			set_lindexes_for_room(t_l_rooms **t, t_l_data *d)
{
	t_l_links	*links;
	int			index;
	int			*new;

	index = 0;
	while (index < d->nrooms)
	{
		links = t[index]->links;
		d->i = get_link_list_length(links);
		if ((new = make_new(d->i)) == NULL)
			return (0);
		d->i2 = index;
		while (d->i-- && links)
		{
			index = 0;
			while (t[index] != links->roomptr)
				index++;
			new[d->i + 1] = index;
			links = links->next;
		}
		index = d->i2;
		t[index]->lindexes = new;
		index++;
	}
	return (1);
}
