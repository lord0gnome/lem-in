/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:05:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/16 15:47:06 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	is_comment(char *str)
{
	if (*str && *str == '#' && *(str + 1) && *(str + 1) != '#')
		return (1);
	return (0);
}

int	is_output_line(t_l_data *d)
{
	d->i = 0;
	if (is_comment(d->l) && d->nocomment)
		return (0);
	return (1);
}

int	parse_fd(t_l_data *d)
{
	while (get_next_line(d->fd, &d->l) > 0)
	{
		if (is_output_line(d))
		{
			if (d->newl == NULL)
				d->newl = ft_strdup(d->l);
			else
				d->newl = ft_strjoin_lemin(d->newl, d->l);
		}
	}
	//if (d->newl)
	//ft_putstr(d->newl);
	while (parse_line(d))
		d->newl = go_to_next_line(d->newl);
	return (1);
}

int	parse_arguments(t_l_data *d, int argc, char **argv)
{
	while (++d->i < argc)
	{
		d->i2 = 0;
		if (argv[d->i][d->i2] && argv[d->i][d->i2] != '-')
			return (d->err->errno = 240); // no - for args
		else
			d->i2++;
		while (argv[d->i][d->i2])
		{
			if (argv[d->i][d->i2 + 1] && (!ft_strncmp(argv[d->i] + d->i2, "f_", 2)))
			{
				if (argv[d->i][d->i2 + 2])
					d->fd = open(argv[d->i] + d->i2 + 2, O_RDONLY);
				else
					return (d->err->errno = 241); //no file to open
				if (d->fd < 0)
					return (d->err->errno = 242); //open error
				d->i2 += ft_strlen(argv[d->i] + d->i2 + 1);
			}
			else if (argv[d->i][d->i2] == 'h' && d->help == 0)
				d->help = 1;
			else if (argv[d->i][d->i2] == 'v' && d->visual == 0)
				d->visual = 1;
			else if (argv[d->i][d->i2] == 'c' && d->nocomment == 0)
				d->nocomment = 1;
			else if (argv[d->i][d->i2] == 'l')
				d->order = -1;

			else
				return (d->err->errno = 243); // not a valid arg
			d->i2++;
		}
	}

	d->i = 0;
	return (d->err->errno = 0);
}
