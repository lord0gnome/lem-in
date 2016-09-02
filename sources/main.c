/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/02 14:46:44 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_l_data	*data;
	t_l_error	*err;
	int	depth;

	depth = 0;
	err = init_l_error();
	data = init_l_data(err);
	parse_arguments(data, argc, argv);
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	if (read(data->fd, NULL, 0) < 0)
		return (ft_printf("ERROR : Read a directory / Other read error"));
	parse_line(data);
	if (data->repairorder)
		test_order(data);
	ft_print_members(data->lines);
	init_all(data);
	if (data->err->errno != 0 && !data->ignoreerr)
		ft_printf("ERROR : %d, %s\n", err->errno, err->errstr);
	if (data->nants == -1)
		data->err->errno = 132;
	test_strt_end(data->rooms, err);
	data->ants = add_ants(data);
	data->frst = data->rooms;
	while (data->frst && data->frst->startend != 1)
		data->frst = data->frst->next;
	rec_set_depths(data->frst, &depth);
	ft_print_members(data->lines);
	while (data->frst)
	{
		ft_printf("room %s has links below and is %d room, it's depth is %d, and it's traveled flag is %d\n", data->frst->name, data->frst->startend, data->frst->depth, data->frst->used);
		while (data->frst->links)
		{
			ft_putendl(data->frst->links->roomptr->name);
			data->frst->links = data->frst->links->next;
		}
		ft_putchar('\n');
		data->frst = data->frst->next;
	}
	while(data->ants)
	{
		ft_printf("ant nbr is %d\nIts room is %s\n", data->ants->id, data->ants->room->name);
		data->ants = data->ants->next;
	}
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	return (0);
}
