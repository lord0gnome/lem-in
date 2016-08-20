/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/20 16:37:45 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_ants(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		i++;
		if (!str[i])
			return (1);
	}
	return (0);
}

int	is_room(char *str, t_l_data *d)
{
	d->i2 = 0;
	while (str[d->i2] && str[d->i2] != ' ')
	{
		if (!str[d->i2])
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
	return (0);
}

int	is_command(char *str, t_l_data *d)
{
	int	i;

	i = 0;
	if (str[i] == '#' && str[i + 1] && str[i + 1] == '#')
	{
		if (!ft_strcmp("start", str + 2))
			if (d)
				return (d->command = START ? 0 : 40);
		if (!ft_strcmp("end", str + 2))
			if (d)
				return (d->command = END ? 0 : 41);
	}
	return (0);
}

int	is_link(char *link, t_l_data *d)
{
	t_l_rooms	*travel;
	t_l_rooms	*r1;
	t_l_rooms	*r2;

	r1 = NULL;
	r2 = NULL;
	if ((d->i = ft_findfirstlastdelim(link, '-', 0)) == -1)
		return (d->err->errno = 110);
	travel = d->rooms;
	while (travel && !r1)
	{
		r1 = d->i >= 0 && !ft_strncmp(link, travel->name, d->i) ? travel : NULL;
		travel = r1 ? travel : travel->next;
	}
	travel = d->rooms;
	while (travel)
	{
		r2 = !ft_strcmp(link + d->i + 1, travel->name) ? travel : NULL;
		travel = r2 ? travel : travel->next;
	}
	if (r1 && r2)
		return (add_link(r1, r2));
	return (d->err->errno = 112);
}

int	parse_line(t_l_data *d)
{
	t_s_list	*travel;

	travel = d->lines;
	while (travel)
	{
		if (travel->flag && d->nants == -1 && is_ants(travel->str))
			d->nants = ft_atoi(travel->str);
		else if (travel->flag && !is_command(travel->str, d))
			d->i2 = d->i2;
		else if (travel->flag && !is_link(travel->str, d))
			d->i2 = d->i2;
		else if (travel->flag && !is_room(travel->str, d))
			d->i2 = d->i2;
		travel = travel->next;
	}
	return (1);
}
