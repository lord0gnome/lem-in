/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:47:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/15 19:08:21 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_path(t_l_p *path, t_l_data *d)
{
	int	nlinks;

	nlinks = 0;
	while (path)
	{
		ft_printf("PATH index is %d\n", nlinks++);
		print_room(d->all[path->room], d);
		ft_printf("going to next index\n");
		path = path->n;
	}
}

void	print_room(t_l_rooms *room, t_l_data *d)
{
	int	i;

	if (!room)
	{
		ft_printf("this room is NULL\n");
		return ;
	}
	ft_printf("name[%s%s%s] ", GREEN, room->name, RESET);
	ft_printf("links[%s%d%s] ",CYAN, room->lindexes[0], RESET);
	ft_printf("used[%s%d%s] ",CYAN, room->used, RESET);
	if (room->startend == 1)
		ft_printf("%s[START] %s", GREEN, RESET);
	else if (room->startend == 2)
		ft_printf("%s[ END ] %s", RED, RESET);
	ft_printf("depth[%s%d%s] ", MAGENTA, room->depth, RESET);
	ft_printf("links are below\n");
	i = 0;
	while (i++ < room->lindexes[0])
	{
		ft_printf("Link %s%s%s",GREEN, d->all[room->lindexes[i]]->name, RESET);
	ft_printf(" depth = %s%d%s used ", MAGENTA, d->all[room->lindexes[i]]->depth, RESET);
	ft_printf("%s%d%s\n",CYAN, d->all[room->lindexes[i]]->used, RESET);
	}
	ft_putchar('\n');
}

void	remove_noconnects(t_l_rooms *start, t_l_data *d)
{
	t_l_rooms *previous;
	t_l_rooms *tofree;

	previous = NULL;
	while (start)
	{
		tofree = NULL;
		if (start->links == NULL)
		{
			d->nrooms--;
			ft_printf("room %s has no links, it is useless\n", start->name);
			if (previous)
				previous->next = start->next;
			else
			{
				d->frst = start->next;
				d->rooms = start->next;
			}
			tofree = start;
		}
		previous = start;
		start = start->next;
		if (tofree)
		{
			free(tofree);
			tofree = NULL;
			previous = NULL;
		}
	}
}

int	count_rooms(t_l_rooms *first)
{
	int	ret;

	ret = 0;
	while (first)
	{
		ret++;
		first = first->next;
	}
	return (ret);
}

int	test_ants_first(t_s_list *antsline, t_l_error *err)
{
	antsline = antsline->prev;
	while (antsline)
	{
		if (antsline->flag != 0)
			return (err->errno = 138);
		antsline = antsline->prev;
	}
	return (0);
}

int	test_strt_end(t_l_rooms *travel, t_l_error *err)
{
	char	start;
	char	end;

	start = 0;
	end = 0;
	while (travel)
	{
		if (travel->startend == 1)
			start++;
		if (travel->startend == 2)
			end++;
		travel = travel->next;
	}
	if (!start && !end)
		return (err->errno = 134);
	if (start && !end)
		return (err->errno = 135);
	if (end && !start)
		return (err->errno = 136);
	if (end != 1)
		return (err->errno = 137);
	if (start != 1)
		return (err->errno = 138);
	return (0);
}
