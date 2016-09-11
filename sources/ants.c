/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/11 19:21:19 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_l_ants	*add_ants(t_l_data *d)
{
	int			antid;
	t_l_ants	*new;
	t_l_ants	*prev;
	t_l_ants	*first;

	antid = 0;
	first = NULL;
	prev = NULL;
	if (d->nants <= 0)
		return (NULL);
	while (d->nants--)
	{
		if ((new = (t_l_ants *)malloc(sizeof(t_l_ants))) == NULL)
			return (NULL);
		new->id = antid++;
		new->next = NULL;
		new->room = d->rooms;
		if (!first)
			first = new;
		if (prev)
			prev->next = new ? new : NULL;
		prev = new;
	}
	return (first);
}
