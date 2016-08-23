/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/23 17:21:46 by guiricha         ###   ########.fr       */
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
	return (0);
}

int	is_command(char *str, t_l_data *d)
{
	int	i;

	i = 0;
	if (str[i] == '#' && str[i + 1] && str[i + 1] && str[i + 1] == '#')
	{
		if (!ft_strcmp("start", str + 2))
			return (d->command = START);
		else if (!ft_strcmp("end", str + 2))
			return (d->command = END);
		else
			return (0);
	}
	return (0);
}

int	is_link(char *link, t_l_data *d)
{
	t_l_rooms	*trav;

	d->r1 = NULL;
	d->r2 = NULL;
	if ((d->i = ft_findfirstlastdelim(link, '-', 0)) == -1)
		return (d->err->errno = 110);
	trav = d->rooms;
	while (trav && !d->r1)
	{
		d->r1 = d->i >= 0 && !ft_strncmp(link, trav->name, d->i) ? trav : NULL;
		trav = d->r1 ? trav : trav->next;
	}
	trav = d->rooms;
	while (trav && !d->r2)
	{
		d->r2 = !ft_strcmp(link + d->i + 1, trav->name) ? trav : NULL;
		trav = d->r2 ? trav : trav->next;
	}
	if (d->r1 && d->r2)
		return (0);
	return (d->err->errno = 112);
}

int	test_order(t_l_data *d)
{
	t_s_list	*travel;
	t_s_list	*incept;
	t_s_list	*first;
	int			order;


	order = -1;
	travel = d->lines;
	first = d->lines;
	if (!d->ignoreerr)
	{
		while (travel->next)
			{
				order = travel->flag == 3 ? 3 : order;
				if (order == 3 && travel && travel->next->flag == 2)
				{
					incept = travel->next;
					while (incept && incept->next && incept->next->flag != 3)
						incept = incept->next;
					ft_swap_next_members(&incept, &travel);
					travel = first;
					order = -1;
					continue;
				}
		ft_putnbr(travel->flag);
		ft_putchar('-');
		ft_putchar('-');
		ft_putchar('-');
		ft_putstr(travel->str);
		ft_putchar('\n');
		travel = travel->next;
			}
	}
	return (0);
}

int	parse_line(t_l_data *d)
{
	t_s_list	*travel;
	int			tmp;

	travel = d->lines;
	while (travel)
	{
		tmp = 0;
		if (travel->flag && d->nants == -1 && is_ants(travel->str))
		{
			//d->nants = ft_atoi(travel->str);
			travel->flag = 1;
		}
		else if (travel->flag && (tmp = is_command(travel->str, d)))
		{
		//	d->command = tmp;
			travel->flag = 4;
		}
		else if (travel->flag && (!is_link(travel->str, d) ||
				(ft_findfirstlastdelim(travel->str, '-', 0)) != -1))
		{
		//	add_link(d->r1, d->r2);
			travel->flag = 3;
		}
		else if (travel->flag && !is_room(travel->str, d))
		{
			travel->flag = 2;
		/*	if (!(add_room(d, ft_strgrab(travel->str, ' '))))
			return (d->err->errno = 103);*/
		}
		travel = travel->next;
	}
	return (1);
}
