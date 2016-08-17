/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/16 19:00:49 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*go_to_next_line(char *str)
{
	while (*str)
	{
		str++;
		if (*str && *str == '\n')
			return (str + 1);
	}
	return (NULL);
}

int	is_ants(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

int	is_room(char *str, t_l_data *d)
{
	d->i2 = 0;
	while (str[d->i2] && str[d->i2] != ' ')
	{
		if (str[d->i2] == '\n' )
			return (d->err->errno = 100);
		d->i2++;
	}
	if (str[d->i2] && str[d->i2] != ' ')
		return (d->err->errno = 101);
	d->i2++;
	d->i2 += ft_atoi_addlen(&(d->cx), str + d->i2);
	if (str[d->i2] && str[d->i2] != ' ')
		return (d->err->errno = 102);
	d->i2++;
	d->i2 += ft_atoi_addlen(&(d->cy), str + d->i2);
	if (!(add_room(d, ft_strgrab(str, ' '))))
		return (d->err->errno = 103);
	ft_printf("%s | is considered to be a room.\n", str);
	return (0);
}

int	is_command(char *str, t_l_data *d)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '#' && str[i + 1] && str[i + 1] == '#')
		{
			if (!ft_strcmp("start", str + 2))
				d->command = START;
			else if (!ft_strcmp("end", str + 2))
				d->command = END;
			else
				return (d->err->errno = 42);
		}
		else
			return (1);
		i++;
	}
	ft_printf("%s | is considered to be a command.\n", str);
	return (0);
}


int	parse_line(t_l_data *d)
{
	if (d->nants == -1 && is_ants(d->newl))
		d->nants = ft_atoi(d->newl);
	else if (!is_command(d->newl, d))
		d->i2 = d->i2;
	else if (is_room(d->newl, d))
		d->i2 = d->i2;
	return (1);
}
