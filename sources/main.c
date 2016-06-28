/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/28 16:56:16 by guiricha         ###   ########.fr       */
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

	error = init_l_error();
	data = init_l_data(error);
	if (argc > 1)
		parse_arguments(data, argc, argv);
	if (data->err->errno != 0 && !data->ignoreerr)
		return(ft_printf("ERROR : %d, %s\n", data->err->errno, data->err->errstr));
	if (read(data->fd, NULL, 0) < 0)
		return (ft_printf("ERROR : Tried to read a directory / Other read error"));
	parse_fd(data);
	return (0);
}
