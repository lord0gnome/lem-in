/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/18 19:04:49 by guiricha         ###   ########.fr       */
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
			if (!ft_strncmp("start\n", str + 2, 6))
				d->command = START;
			else if (!ft_strncmp("end\n", str + 2, 4))
				d->command = END;
			else
				return (d->err->errno = 42);
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	is_link(char *linkname, t_l_data *d)
{
	int	index;
	t_l_rooms	*travel;
	t_l_rooms	*r1;
	t_l_rooms	*r2;

	r1 = NULL;
	r2 = NULL;
	if ((index = ft_findfirstlastdelim(linkname, '-', 0)) == -1)
		return (d->err->errno = 110);
	travel = d->rooms;
	while (travel)
	{
		if (!r1 && index >= 0 && !ft_strncmp(linkname, travel->name, index))
		{
			ft_strntilnl(linkname);
			ft_printf(" \\\\\\compared to %s is true for length %d\n", travel->name, index);
			r1 = travel;

		}
		/*ft_strntilnl(linkname + index + 1);
		ft_putchar('_');
		ft_strntilnl(travel->name);
		ft_putchar('\n');*/
		if (!r2 && !ft_strcmpdelim(linkname + index + 1, travel->name, '\n'))
		{
			ft_putnbr(ft_strcmpdelim(linkname + index + 1, travel->name, '\n'));
			ft_strntilnl(linkname + index + 1);
			ft_printf(" ///compared to %s is true for length %d\n", travel->name, index);
			r2 = travel;
		}
		travel = travel->next;
	}
	if (r1 && r2)
	{
		ft_putstr("works ");
		ft_printf("between %s and %s\n", r1->name, r2->name);
		return (0);
	}
	return (d->err->errno = 112);
}


int	parse_line(t_l_data *d)
{
	if (d->nants == -1 && is_ants(d->newl))
		d->nants = ft_atoi(d->newl);
	else if (!is_link(d->newl, d))
		d->i2 = d->i2;
	else if (!is_room(d->newl, d))
		d->i2 = d->i2;
	else if (!is_command(d->newl, d))
		d->i2 = d->i2;
	if ((d->newl = go_to_next_line(d->newl)) == NULL)
		return (0);
	return (1);
}
