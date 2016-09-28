/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/28 14:47:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		init_l_data_more(t_l_data *d)
{
	d->i2 = 0;
	d->cx = -1;
	d->load = 0;
	d->cy = -1;
	d->fd = 0;
	d->help = 0;
	d->nants = -1;
	d->visual = 0;
	d->order = 0;
	d->showpaths = 0;
	d->nocomment = 0;
	d->slow = 0;
	d->scone = 0;
	d->first = 1;
	d->nantsb = -1;
	d->f = 0;
}

t_l_data	*init_l_data(t_l_error *error)
{
	t_l_data *d;

	if ((d = (t_l_data *)malloc(sizeof(t_l_data))) == NULL)
		return (NULL);
	d->l = NULL;
	d->newl = NULL;
	d->i = 0;
	d->debug = 0;
	init_l_data_more(d);
	d->err = error;
	d->ants = NULL;
	d->antn = NULL;
	d->plen = NULL;
	d->anti = NULL;
	d->rooms = NULL;
	d->lines = NULL;
	d->frst = NULL;
	return (d);
}

t_l_error	*init_l_error(void)
{
	t_l_error	*error;

	if ((error = (t_l_error *)malloc(sizeof(t_l_error))) == NULL)
		return (NULL);
	error->errno = 0;
	error->errstr = NULL;
	error->errchar = 0;
	return (error);
}

static int	init_all_cntd(t_l_data *d, t_s_list *travel, int tmp)
{
	if (travel->flag == 5)
	{
		if (!test_ants_first(travel, d->err))
			return (d->nants = ft_atoi(travel->str));
		else
			return (d->err->errno);
	}
	else if (travel->flag == 4 && (tmp = is_command(travel->str)))
		return (d->command = tmp);
	else if (travel->flag == 2 && !is_room(travel->str, d))
	{
		if (!(add_room(d, ft_strgrab(travel->str, ' '))))
			d->err->errno = 2;
		return (1);
	}
	else if (travel->flag == 0)
		return (1);
	else if (travel->flag == 3 && (!is_link(travel->str, d)))
	{
		if (add_link(d->r1, d->r2) != 0)
			return (travel->flag = -1);
		return (1);
	}
	travel->flag = -1;
	return (0);
}

int			init_all(t_l_data *d)
{
	t_s_list	*travel;
	t_s_list	*p;
	int			tmp;

	d->fd = 2;
	travel = d->lines;
	while (travel && (travel->flag != -1))
	{
		tmp = 0;
		if (travel->flag == 2 && d->fd == 3)
			travel->flag = -1;
		else if (init_all_cntd(d, travel, tmp))
			;
		else
			continue ;
		if (travel->flag == -1 || d->err->errno)
		{
			p->next = NULL;
			return (d->err->errno);
		}
		d->fd = travel->flag == 3 || d->fd == 3 ? 3 : 2;
		p = travel;
		travel = travel->next;
	}
	return (1);
}
