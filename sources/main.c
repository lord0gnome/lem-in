/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/17 20:32:53 by guiricha         ###   ########.fr       */
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
	init_all(data);
	data->nrooms = count_rooms(data->rooms);
	if (data->err->errno != 0 && !data->ignoreerr)
		ft_printf("ERROR : %d, %s\n", err->errno, err->errstr);
	if (data->nants == -1 || data->nants == 0 || data->nants < 0)
		data->err->errno = 132;
	test_strt_end(data->rooms, err);
	ft_print_members(data->lines);
	make_ants(data);
	data->frst = data->rooms;
	remove_noconnects(data->frst, data);
	init_room_tab(data, data->frst);
	set_lindexes_for_room(data->all, data);
	number = 0;
	set_depth(data->all, data);
	put_ants_start(data->ants, data->all, data->allindex);
	megatest(data);
	while (data->frst->startend != 1)
		data->frst = data->frst->next;
	resolve(data->frst,data);
	data->frst = data->rooms;
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	return (0);
}
