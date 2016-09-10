/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 12:40:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/08 16:37:48 by guiricha         ###   ########.fr       */
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

int	set_lindexes_for_room(t_l_rooms **t, t_l_data *d)
{
	int			n;
	t_l_links	*links;
	int			index;
	int			i2;
	int			*new;

	index = 0;
	while (index < d->nrooms)
	{
//		ft_printf("current room at index [%d] is [%s]\n", index, t[index]->name);
		links = t[index]->links;
		n = get_link_list_length(links);
		new = (int *)malloc(sizeof(int) * (n + 2));
		if (!new)
			return (-1);
//		ft_printf("created new table of ints of length %d and setting indexes %d to -1 and 0 to %d\n", n + 2, n + 1, n);
		new[n + 1] = -1;
		new[0] = n;
		i2 = index;
		while (n-- && links)
		{
			index = 0;
			while (t[index] != links->roomptr)
				index++;
			new[n + 1] = index;
//			ft_printf("new link for room [%s] with name %s\n", t[i2]->name,t[index]->name);
			links = links->next;
		}
		index = i2;
		t[index]->lindexes = new;
		index++;
	}
	return (1);
}
