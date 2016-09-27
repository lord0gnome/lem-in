/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:05:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/27 19:37:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int			is_output_line(char *str)
{
	if ((*str && *str == '#' && *(str + 1) && *(str + 1) != '#') ||
			(!is_command(str) && *str == '#'))
		return (0);
	return (1);
}

int			parse_fd(t_l_data *d)
{
	d->first = 0;
	while (get_next_line(d->fd, &d->l) > 0)
		if ((d->lines = ft_s_list(d->l, is_output_line(d->l), d)) == NULL)
			break;
	return (1);
}

static int	parse_arguments_more(t_l_data *d, char **argv)
{
	if (argv[d->i][d->i2] == 'h')
		d->help = 1;
	else if (argv[d->i][d->i2] == 'v')
		d->visual = 1;
	else if (argv[d->i][d->i2] == 'c')
		d->nocomment = 1;
	else if (argv[d->i][d->i2] == 'l')
		d->order = -1;
	else if (argv[d->i][d->i2] == 'e')
		d->ignoreerr = 1;
	else if (argv[d->i][d->i2] == 'o')
		d->repairorder = 1;
	else
		return (0);
	return (1);
}

static int	parse_arguments_more_more(t_l_data *d, char **argv)
{
	if (argv[d->i][d->i2 + 2])
		d->fd = open(argv[d->i] + d->i2 + 2, O_RDONLY);
	else
		return (d->err->errno = 3);
	if (d->fd < 0)
		return (d->err->errno = 4);
	return (0);
}

int			parse_arguments(t_l_data *d, int argc, char **av)
{
	d->i = 0;
	while (++d->i < argc)
	{
		d->i2 = 0;
		if (av[d->i][d->i2] && av[d->i][d->i2] != '-')
			return (d->err->errno = 5);
		else
			d->i2++;
		while (av[d->i][d->i2])
		{
			if (av[d->i][d->i2 + 1] && (!ft_strncmp(av[d->i] + d->i2, "f_", 2)))
			{
				if (!parse_arguments_more_more(d, av))
					break ;
			}
			else if (parse_arguments_more(d, av))
				;
			else
				return (d->err->errno = 6);
			d->i2++;
		}
	}
	parse_fd(d);
	return (0);
}
