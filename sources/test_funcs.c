/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:47:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/30 13:40:38 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_path(t_l_p *path, t_l_data *d)
{
	int	nlinks;

	nlinks = 0;
	if (!d->showpaths)
		return ;
	while (path)
	{
		ft_printf("PATH index is %d\n", nlinks++);
		print_room(d->all[path->room], d);
		ft_printf("going to next index\n");
		if (d->slow && d->slow >= 1)
			ft_wait(d->slow);
		path = path->n;
	}
	if (d->slow && d->slow >= 1)
		ft_wait(d->slow);
}

void		print_room(t_l_rooms *room, t_l_data *d)
{
	int	i;

	if (!room)
	{
		ft_printf("this room is NULL\n");
		return ;
	}
	ft_printf("name[%s%s%s] ", GREEN, room->name, RESET);
	ft_printf("links[%s%d%s] ", CYAN, room->lindexes[0], RESET);
	ft_printf("used[%s%d%s] ", CYAN, room->used, RESET);
	if (room->startend == 1)
		ft_printf("%s[START] %s", GREEN, RESET);
	else if (room->startend == 2)
		ft_printf("%s[ END ] %s", RED, RESET);
	ft_printf("depth[%s%d%s] ", MAGENTA, room->depth, RESET);
	ft_printf("links are below\n");
	i = 0;
	while (i++ < room->lindexes[0])
	{
		ft_printf("Link %s%s%s", GREEN, d->all[room->lindexes[i]]->name, RESET);
		ft_printf(" depth = %s%d%s used ", MAGENTA,
		d->all[room->lindexes[i]]->depth, RESET);
		ft_printf("%s%d%s\n", CYAN, d->all[room->lindexes[i]]->used, RESET);
	}
	ft_putchar('\n');
}

int			count_rooms(t_l_rooms *first, t_l_data *d)
{
	int	ret;

	ret = 0;
	while (first)
	{
		ret++;
		first = first->next;
	}
	if (ret == 0)
		d->err->errno = 25;
	return (ret);
}

int			test_ants_first(t_s_list *antsline, t_l_error *err)
{
	antsline = antsline->prev;
	while (antsline)
	{
		if (antsline->flag != 0 && antsline->flag != 4)
			return (err->errno = 138);
		antsline = antsline->prev;
	}
	return (0);
}

int			test_strt_end(t_l_rooms *travel, t_l_error *err)
{
	int	start;
	int	end;

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
		return (err->errno = 7);
	if (start && !end)
		return (err->errno = 8);
	if (end && !start)
		return (err->errno = 9);
	if (end != 1 && start == 1)
		return (err->errno = 10);
	if (start != 1 && end == 1)
		return (err->errno = 11);
	return (err->errno = start != 1 && end != 1 ? 12 : 0);
}
