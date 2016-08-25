/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:46:01 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/25 19:20:54 by guiricha         ###   ########.fr       */
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
	{
		ft_putstr("coudlnt't find what you were loking for in str - ");
		ft_putendl(link);
		return (1);
	}
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
	{
		ft_putstr("found links in the string that follows -");
		ft_putendl(link);
		return (0);
	}
	return (1);
}

int	ordered_flags(t_s_list *travel)
{
	int	flag;
	t_s_list *first;

	flag = 2;
	first = travel;
	while (first)
	{
		if (flag == 3 && first->flag == 2)
			return (0);
		if (first->flag == 3)
			flag = 3;

		first = first->next;
	}
	return (1);
}

int	test_order(t_l_data *d)
{
	t_s_list	*travel;
	t_s_list	*first;
	t_s_list	*last;
	t_s_list	*lastbck;
	int			order;


	order = -1;
	travel = d->lines;
	first = d->lines;
	last = d->lines;
	while (last && last->next)
		last = last->next;
	lastbck = last;
	while (42)
	{
		while (travel && travel->flag != 3)
			travel = travel->next;
		while (last && last->flag != 2)
			last = last->prev;
		if (!ordered_flags(first))
		{
			ft_swap_members(&travel, &last);
			last = lastbck;
			travel = first;
		}
		else
			break ;
	}
	return (0);
}

int	parse_line_test(t_l_data *d)
{
	t_s_list	*travel;
	int			tmp;

	travel = d->lines;
	while (travel)
	{
		tmp = 0;
		if (travel->flag == 1 && (d->ignoreerr || !travel->prev))
		{
			d->nants = ft_atoi(travel->str);
		}
		else if (travel->flag == 4 && (tmp = is_command(travel->str, d)))
		{
			d->command = tmp;
		}
		else if (travel->flag == 3 && (!is_link(travel->str, d) ||
					(ft_findfirstlastdelim(travel->str, '-', 0)) != -1))
		{
			add_link(d->r1, d->r2, d);
		}
		else if (travel->flag == 2)
		{
			if (!(add_room(d, ft_strgrab(travel->str, ' '))))
				return (d->err->errno = 103);
		}
		if (d->err->errno)
			ft_putstr(travel->str);
		travel = travel->next;
	}
	return (1);
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
