/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:32:14 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/14 20:31:47 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	resolve(t_l_data *d, t_l_rooms **all, int *allindex)
{
	int i;
	t_l_rooms *st;
	int	potential;
	t_l_p 	*start;
	t_l_p	**allpaths;

	i = 0;
	while (all[allindex[i]]->startend != 2)
		i++;
	st = all[allindex[i]];
	d->endlinks = st->lindexes[0];
	ft_printf("end room is considered to be %s\n", st->name);
	print_room(st, d);
	i = 0;
	ft_putstr("\n\n\n");
	while (all[allindex[i]]->startend != 1)
		i++;
	st = all[allindex[i]];
	ft_printf("start room is considered to be %s\n", st->name);
	print_room(st, d);
	d->startlinks = st->lindexes[0];
	start = NULL;

	potential = d->startlinks > d->endlinks ? d->endlinks : d->startlinks;
	allpaths = (t_l_p **)malloc(sizeof(t_l_p *) * (potential + 1));
	allpaths[potential] = NULL;
	i = 0;
	while (i < potential)
	{
		allpaths[i] = (t_l_p *)malloc(sizeof(t_l_p));
		allpaths[i]->room = -1;
		allpaths[i]->n = NULL;
		if (start)
			start->n = allpaths[i];
		start = allpaths[i];
		d->i2 = 0;
		while (d->i2++ < st->lindexes[0])
		{
			print_room(all[st->lindexes[d->i2]], d);
			while (all[st->lindexes[d->i2]]->used)
				d->i2++;
			if (d->i2 >= st->lindexes[0])
			{
				continue ;
			}
			if (allpaths[i]->room == -1)
				allpaths[i]->room = st->lindexes[d->i2];
			allpaths[i]->room = all[st->lindexes[d->i2]]->depth < all[allpaths[i]->room]->depth ? st->lindexes[d->i2] : allpaths[i]->room;
		}
		all[allpaths[i]->room]->used = 1;
	}
}
