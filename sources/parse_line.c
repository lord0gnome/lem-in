/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/07/04 17:14:28 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*go_to_next_line(char *str)
{
	while (*str)
	{
		str++;
		if (*str && *str == '\n')
			return (str);
	}
	return (str);
}

int	is_ants(char *str)
{
	while (*str && isdigit(*str))
	{
		str++;
		if (*str == '\n')
			return (1);
	}
	return (0);
}

int	is_room(char *str, t_l_data *d)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] && str[i] == ' ')
	{
		if (str[i] && isdigit(str[i]))
			d->cx = ft_atoi(str + i);
		else
			return (-1);
		while (str[i] && !isdigit(str[i]))
			i++;
	}
	if (str[i] && isdigit(str[i]))
		d->cy = ft_atoi(str + i);
	else
		return (-1);
	add_room(d, ft_strgrab(str, ' '));
	return (1);
}

int	is_command(char *str, t_l_data *d)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '#' && str[i + 1] && str[i + 1] == '#')
		{
			if (!ft_strcmp("start\n", str + 2))
				d->command = START;
			else if (!ft_strcmp("end", str + 2))
				d->command = END;
			else
				d->command = NOCOMMAND;
		}
		i++;
	}
	return (1);
}


int	parse_line(t_l_data *d)
{
	if (is_ants(d->newl))
		d->nants = ft_atoi(d->newl);
	else if (is_command(d->newl, d))
		d->i2++;
	else if (is_room(d->newl, d))
		ft_putnbr(1);
	if (!(*d->newl))
		return (0);
	return (1);
}
