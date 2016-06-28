/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:59:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/28 16:56:06 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ants	*new_ant(t_l_data *d)
{
	t_l_ants	*new;
	
	if ((new = (t_l_ants *)malloc(sizeof(t_l_ants))) == NULL)
		return (NULL);
}

t_ants	*generate_ants(t_l_data *d)
{
	t_l_ants	**start;
	t_l_ants	*new;

	if (d->nants <= 0)
		return (d->err->errno = 250);
	while (d->nants)
	{
		if ((new = (t_l_ants *)malloc(sizeof(t_l_ants))) == NULL)
			return (NULL);
		new->id = d->nants;
		new->next = NULL;
		new->room = NULL;
	}
}
