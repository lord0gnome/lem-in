/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 20:52:22 by guiricha         ###   ########.fr       */
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
	data->nrooms = count_rooms(data->rooms);
	ft_printf("number of rooms is [%d]\n", data->nrooms);
	if (data->err->errno != 0 && !data->ignoreerr)
		ft_printf("ERROR : %d, %s\n", err->errno, err->errstr);
	if (data->nants == -1)
		data->err->errno = 132;
	test_strt_end(data->rooms, err);
	data->ants = add_ants(data);
	data->frst = data->rooms;
	//ft_print_members(data->lines);
	while (data->frst)
	{
		/*while (data->frst->larray_len--)
		{
			ft_putstr(data->frst->larray[0]->rptr->name);
		}*/
		data->frst = data->frst->next;
	}
	data->frst = data->rooms;
	init_room_tab(data, data->frst);
	set_lindexes_for_room(data->all, data);
	number = 0;
	while (number < data->nrooms)
	{
			
	/*	while (data->frst->links)
		{
			ft_putendl(data->frst->links->roomptr->name);
			data->frst->links = data->frst->links->next;
		}
		ft_putchar('\n');*/
	}
	data->frst = data->rooms;
	if (data->err->errno != 0 && !data->ignoreerr)
		return (ft_printf("ERROR : %d, %s\n", err->errno, err->errstr));
	return (0);
}
