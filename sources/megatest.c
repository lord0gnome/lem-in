/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megatest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 13:32:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/11 19:46:30 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	megatest(t_l_data *d)
{
	int			*nrooms;
	int			tmpli;
	int			li;
	t_l_rooms	**a;

	a = d->all;
	tmpli = d->nrooms;
	nrooms = d->allindex;

	while (*nrooms != -2)
	{
		ft_printf("index [%s%4d%s] %s%5s%s, startend[%d], depth[%s%3d%s], x[%03d], y[%03d], lindexes[0]==[%d]\n",
				MAGENTA, *nrooms, RESET,
				GREEN,a[*nrooms]->name, RESET,
				a[*nrooms]->startend,
				CYAN, a[*nrooms]->depth, RESET,
				a[*nrooms]->x,
				a[*nrooms]->y,
				a[*nrooms]->lindexes[0]);
		if (a[*nrooms]->lindexes[0] != 0)
		{
			ft_printf("its links are below\n");
			li = 0;
			while (li++ < a[*nrooms]->lindexes[0])
			{
				ft_printf("%s%5s%s               startend[%d], depth[%s%3d%s], x[%03d], y[%03d], lindexes[0]==[%d]\n", RED,
						a[a[*nrooms]->lindexes[li]]->name, RESET, 
						a[a[*nrooms]->lindexes[li]]->startend, CYAN,
						a[a[*nrooms]->lindexes[li]]->depth, RESET,
						a[a[*nrooms]->lindexes[li]]->x,
						a[a[*nrooms]->lindexes[li]]->y,
						a[a[*nrooms]->lindexes[li]]->lindexes[0]);
			}
		}
		ft_putchar('\n');
		nrooms++;
	}
	ft_printf("bleh\n");
}
