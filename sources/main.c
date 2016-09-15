/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/15 19:08:21 by guiricha         ###   ########.fr       */
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
	int	number;
	int	n2;

	n2 = 0;
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
	//ft_print_members(data->lines);
	init_all(data);
	data->nrooms = count_rooms(data->rooms);
	ft_printf("number of rooms is [%d]\n", data->nrooms);
	if (data->err->errno != 0 && !data->ignoreerr)
		ft_printf("ERROR : %d, %s\n", err->errno, err->errstr);
	if (data->nants == -1)
		data->err->errno = 132;
	test_strt_end(data->rooms, err);
//	data->ants = add_ants(data);
	data->frst = data->rooms;
	remove_noconnects(data->frst, data);
	init_room_tab(data, data->frst);
	set_lindexes_for_room(data->all, data);
	number = 0;
	set_depth(data->all, data);
	//flip_allindex(data->allindex);
	megatest(data);
	ft_printf("number of rooms is [%d]\n", data->nrooms);
	while (data->frst->startend != 1)
		data->frst = data->frst->next;
	resolve(data->frst, data);
/*	while (number < data->nrooms)
	{
		ft_printf("Room is [%s] with values below\nstartend :	%d\ndepth :		%d\nx/y :		%d / %d\n", data->all[number]->name, data->all[number]->startend, data->all[number]->depth, data->all[number]->x, data->all[number]->y);
		ft_printf("it has %d links\n",data->all[number]->lindexes[0]);
		n2 = data->all[number]->lindexes[0];
		while (n2 != 0)
		{
			ft_printf("%s\n", data->all[data->all[number]->lindexes[n2]]->name);
			n2--;
		}
		ft_putchar('\n');
		number++;
	}*/
	data->frst = data->rooms;
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	return (0);
}
