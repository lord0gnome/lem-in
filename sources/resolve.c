/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 14:32:14 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 12:42:13 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		novalidpath(t_l_p *path, t_l_data *d)
{
	int			i;
	t_l_rooms	*current;

	current = d->all[path->room];
	i = 0;
	while (i++ < current->lindexes[0])
	{
		if (d->all[current->lindexes[i]]->startend != 1 &&
				(!d->all[current->lindexes[i]]->used ||
			d->all[current->lindexes[i]]->startend == 2))
			return (0);
	}
	if (current->startend == 1)
		return (-1);
	return (1);
}

t_l_p			*backtrack(t_l_p *path, t_l_data *d)
{
	while (path && path->n)
		path = path->n;
	d->all[path->room]->used = 1;
	if (path && path->p)
		path = path->p;
	if (path && path->n)
		free(path->n);
	path->n = NULL;
	return (path);
}

static int		get_most_potential_paths(t_l_rooms **rooms)
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

static int		res_loop(t_l_data *d, t_l_rooms **a, t_l_p *t, t_l_rooms *s)
{
	int	ret;

	while (42)
	{
		if (s->startend == 2)
			return (1);
		d->paths[d->i2] = add_room_to_path(d->paths[d->i2], glur(s, d->all, d));
		t = d->paths[d->i2];
		while (t->n)
			t = t->n;
		if (a[t->room]->startend == 2)
			return (1);
		while ((ret = novalidpath(t, d)) == 1)
			t = backtrack(d->paths[d->i2], d);
		if (ret == -1)
			return (0);
		if (s->startend == 1)
			s->used = 1;
		if (a[t->room]->startend != 2)
			a[t->room]->used = 1;
		s = a[t->room];
	}
}

void			resolve(t_l_rooms *start, t_l_data *d)
{
	int			p;
	int			startint;
	t_l_rooms	**a;
	t_l_rooms	*sbck;
	t_l_p		*travel;

	sbck = start;
	a = d->all;
	p = get_most_potential_paths(d->all);
	d->paths = (t_l_p**)malloc(sizeof(t_l_p*) * (p + 1));
	d->paths[p] = NULL;
	startint = 0;
	while (a[startint]->startend != 1)
		startint++;
	travel = NULL;
	while (d->i2 < p)
	{
		d->paths[d->i2] = NULL;
		start = sbck;
		start->used = 0;
		d->paths[d->i2] = add_room_to_path(d->paths[d->i2], startint);
		if ((d->i = res_loop(d, a, travel, start)) == 0)
			break ;
		d->i2++;
	}
}
