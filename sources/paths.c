/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 15:57:15 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/17 20:27:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_l_p	*add_room_to_path(t_l_p *current, int room)
{
	t_l_p	*new;
	t_l_p	*strt;

	strt = current;
	new = (t_l_p *)malloc(sizeof(t_l_p));
	while (current && current->n)
		current = current->n;
	new->n = NULL;
	new->p = NULL;
	new->room = room;
	if (current)
	{
		current->n = new;
		new->p = current;
		return (strt);
	}
	return (new);
}
