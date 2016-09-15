/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:32:14 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/15 19:08:21 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
 * get lowest unused room
 */

static int	glur(t_l_rooms *room, t_l_rooms **all, t_l_data *d)
{
	int	i;
	int	depth;
	int	lowestdindex;

	lowestdindex = -1;
	depth = -1;
	i = 0;
	print_room(room, d);
	d->i = 0;
	while (i++ < room->lindexes[0])
	{
		if (depth == -1 && all[room->lindexes[i]]->used == 0)
		{
			depth = all[room->lindexes[i]]->depth;
			lowestdindex = room->lindexes[i];
		}
		if (all[room->lindexes[i]]->depth < depth && !all[room->lindexes[i]]->used)
		{
			depth = all[room->lindexes[i]]->depth;
			lowestdindex = room->lindexes[i];
		}
	}
	return (lowestdindex);
}

static int	novalidpath(t_l_p *path, t_l_data *d)
{
	int			i;
	t_l_rooms	*current;

	current = d->all[path->room];
	i = 0;
	while (i++ < current->lindexes[0])
	{
		if (!d->all[current->lindexes[i]]->used || d->all[current->lindexes[i]]->startend == 2)
			return (0);
	}
	return (1);
}

t_l_p	*backtrack(t_l_p *path, t_l_data *d)
{
		while (path && path->n)
			path = path->n;
		d->all[path->room]->used = 1;
		if (path && path->p)
		path = path->p;
		if (path && path->n)
		{
			ft_printf("removing room with ", d->all[path->n->room]->name);
			print_room(d->all[path->n->room], d);
		free(path->n);
		}
		path->n = NULL;
		return (path);
}

static int	get_most_potential_paths(t_l_rooms **rooms)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (rooms[i]->startend != 1)
		i++;
	ret = rooms[i]->lindexes[0];
	i = 0;
	while (rooms[i]->startend != 2)
		i++;
	ret = rooms[i]->lindexes[0] < ret ? rooms[i]->lindexes[0] : ret;
	return (ret);
}

void	resolve(t_l_rooms *start, t_l_data *d)
{
	int	p;
	int	startint;
	t_l_rooms **a;
	t_l_rooms *sbck;
	t_l_p		*travel;

	sbck = start;
	a = d->all;
	p = get_most_potential_paths(d->all);
	ft_printf("%d %s\n", p, start->name);
	d->paths = (t_l_p**)malloc(sizeof(t_l_p*) * (p + 1));	
	d->paths[p] = NULL;
	startint = 0;
	while (a[startint]->startend != 1)
		startint++;
	d->i2 = 0;
	while (d->i2 < p)
	{
		d->paths[d->i2] = NULL;
		start = sbck;
		start->used = 0;
		d->paths[d->i2] = add_room_to_path(d->paths[d->i2], startint);
		while (42)
		{
			/*
			 * find lowest depth room with no used flag, and set flag to used
			 * while moving start to this room, until end is found. Repeat as
			 * many times as possible
			 */
			if (start->startend == 2)
				break ;
			d->paths[d->i2] = add_room_to_path(d->paths[d->i2], glur(start, d->all, d));
			travel = d->paths[d->i2];
			while (travel->n)
				travel = travel->n;
			if (a[travel->room]->startend == 2)
				break ;
			while (novalidpath(travel, d))
				travel = backtrack(d->paths[d->i2], d);
			if (start->startend == 1)
				start->used = 1;
			if (a[travel->room]->startend != 2)
				a[travel->room]->used = 1;
			start = a[travel->room];
		}
		print_path(d->paths[d->i2], d);
		d->i2++;
	}
	ft_printf("in the end I have %d paths\n", d->i2);
}
