/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 13:13:57 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/26 15:47:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ordered_flags(t_s_list *travel, t_l_data *d)
{
	int			flag;
	t_s_list	*first;

	flag = 2;
	first = travel;
	while (first)
	{
		if (flag == 3 && first->flag == 2)
			return (d->err->errno = 13);
		if (first->flag == 3)
			flag = 3;
		first = first->next;
	}
	return (0);
}

void	test_order(t_l_data *d)
{
	t_s_list	*travel;
	t_s_list	*last;
	t_s_list	*lastbck;

	travel = d->lines;
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
		if (ordered_flags(d->lines, d))
		{
			ft_swap_members(&travel, &last);
			last = lastbck;
			travel = d->lines;
		}
		else
			break ;
	}
}
