/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/20 13:43:07 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int	main_cntd(t_l_data *data)
{
	test_strt_end(data->rooms, data->err);
	ft_print_members(data->lines);
	make_ants(data);
	data->frst = data->rooms;
	remove_noconnects(data->frst, data);
	data->frst = data->rooms;
	init_room_tab(data, data->frst);
	set_lindexes_for_room(data->all, data);
	set_depth(data->all, data);
	p_a_st(data->ants, data->all, data->allindex);
	megatest(data);
	while (data->frst->startend != 1)
		data->frst = data->frst->next;
	data->i2 = 0;
	resolve(data->frst, data);
	data->i2 = 0;
	make_ants_go(data, data->paths, data->ants);
	return (1);
}

int			main(int argc, char **argv)
{
	t_l_data	*data;
	t_l_error	*err;

	err = init_l_error();
	data = init_l_data(err);
	parse_arguments(data, argc, argv);
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	if (read(data->fd, NULL, 0) < 0)
		return (ft_printf("ERROR : Read a directory / Other read error"));
	ft_printf("seg after argparse?\n");
	parse_line(data);
	if (data->repairorder)
		test_order(data);
	init_all(data);
	data->nrooms = count_rooms(data->rooms);
	data->frst = data->rooms;
	main_cntd(data);
	if (data->nants == -1 || data->nants == 0 || data->nants < 0)
		data->err->errno = 132;
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	return (0);
}
