/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/16 21:40:37 by guiricha         ###   ########.fr       */
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
	t_l_error	*error;
	t_l_rooms	*room;

	error = init_l_error();
	data = init_l_data(error);
	if (argc > 1)
		parse_arguments(data, argc, argv);
	//print_arguments(data);
	if (data->err->errno != 0 && !data->ignoreerr)
		return(ft_printf("ERROR : %d, %s\n", data->err->errno, data->err->errstr));
	if (read(data->fd, NULL, 0) < 0)
		return (ft_printf("ERROR : Tried to read a directory / Other read error"));
	ft_putstr("bloop");
	add_room(data, "thisisaroom");
	add_room(data, "thisaswell");
	add_room(data, "thisisthe3d");
	add_room(data, "fourthiests");
	add_room(data, "fifthinarow");
	room = (*data->rooms);
	ft_putstr(room->name);
	parse_fd(data);
	add_ants(data);
	print_arguments(data);
	return (0);
}
