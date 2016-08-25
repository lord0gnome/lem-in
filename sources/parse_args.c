/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:05:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/25 17:47:11 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	is_output_line(char *str, t_l_data *d)
{
	if ((*str && *str == '#' && *(str + 1) && *(str + 1) != '#') ||
			(!is_command(str, d) && *str == '#'))
		return (0);
	return (1);
}

int	parse_fd(t_l_data *d)
{
	while (get_next_line(d->fd, &d->l) > 0)
		d->lines = ft_add_s_list(d->l, is_output_line(d->l, d), d->lines);
	return (1);
}

int	parse_args_cnt(t_l_data *d, char **argv)
{
	while (argv[d->i][d->i2])
	{
		if (argv[d->i][d->i2 + 1] && (!ft_strncmp(argv[d->i] + d->i2, "f_", 2)))
		{
			if (argv[d->i][d->i2 + 2])
				d->fd = open(argv[d->i] + d->i2 + 2, O_RDONLY);
			else
				return (d->err->errno = 241);
			if (d->fd < 0)
				return (d->err->errno = 242);
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
		else if (argv[d->i][d->i2] == 'e')
			d->ignoreerr = 1;
		else if (argv[d->i][d->i2] == 'o')
			d->repairorder = 1;
		else
			return (d->err->errno = 243);
		d->i2++;
	}
	return (d->err->errno);
}

int	parse_arguments(t_l_data *d, int argc, char **argv)
{
	d->i = 0;
	while (++d->i < argc)
	{
		d->i2 = 0;
		if (argv[d->i][d->i2] && argv[d->i][d->i2] != '-')
			return (d->err->errno = 240);
		else
			d->i2++;
		if (parse_args_cnt(d, argv))
			return (d->err->errno);
	}
	d->i = 0;
	parse_fd(d);
	return (d->err->errno = 0);
}
