/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:18:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/28 14:44:17 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

static void	exitfunc(int e, t_l_data *d)
{
	if (d->debug)
		ft_print_members(d->lines, d);
	if (e == 1)
		ft_putstr("ERROR\n");
	else if (e == 18)
		ft_putstr("ERROR\n");
	else
		ft_putstr("ERROR\n");
	exit(-1);
}

static int	test_start(t_l_data *d)
{
	int	*nrooms;

	nrooms = d->allindex;
	while (*nrooms != -2 && *nrooms != -1)
	{
		if (d->all[*nrooms]->startend == 1)
			return (1);
		nrooms++;
	}
	return (0);
}

static int	main_cntd(t_l_data *data)
{
	if (test_strt_end(data->rooms, data->err))
		exitfunc(data->err->errno, data);
	make_ants(data);
	data->frst = data->rooms;
	init_room_tab(data, data->frst);
	remove_dup_paths(data->all, data->nrooms);
	set_lindexes_for_room(data->all, data);
	set_depth(data->all, data);
	if (!test_start(data))
		exitfunc(data->err->errno = 18, data);
	ft_print_members(data->lines, data);
	if (data->visual)
		megatest(data);
	while (data->frst && data->frst->startend != 1)
		data->frst = data->frst->next;
	data->i2 = -1;
	resolve(data->frst, data);
	data->paths[data->i2] = NULL;
	data->i2 = 0;
	ft_putchar('\n');
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
	if (data->err->errno != 0)
		return (ft_printf("ERROR\n"));
	if (read(data->fd, NULL, 0) < 0)
		return (ft_printf("ERROR\n"));
	parse_line(data);
	if (data->err->errno)
		return (write(2, "ERROR\n", 7));
	if (!init_all(data))
		exitfunc(data->err->errno, data);
	if (data->nants <= 0)
		return (write(2, "ERROR\n", 7));
	if ((data->nrooms = count_rooms(data->rooms)) == 0)
		return (write(2, "ERROR\n", 7));
	data->frst = data->rooms;
	main_cntd(data);
	return (0);
}
