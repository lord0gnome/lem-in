/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megatest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 13:32:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/10 18:42:51 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	megatest(t_l_data *d)
{
	int			nrooms;
	int			tmpli;
	int			li;
	t_l_rooms	**a;

	a = d->all;
	tmpli = d->nrooms;
	nrooms = 0;
	while (nrooms < tmpli)
	{
		ft_printf("%4d ind is %5s, startend[%d], depth[%3d], x[%03d], y[%03d], lindexes[0]==[%d]\n",
				nrooms,
				a[nrooms]->name,
				a[nrooms]->startend,
				a[nrooms]->depth,
				a[nrooms]->x,
				a[nrooms]->y,
				a[nrooms]->lindexes[0]);
		if (a[nrooms]->lindexes[0] != 0)
		{
			ft_printf("its links are below\n");
			li = 0;
			while (li++ < a[nrooms]->lindexes[0])
			{
				ft_printf("link name is %5s, startend[%d], depth[%3d], x[%03d], y[%03d], lindexes[0]==[%d]\n",
						a[a[nrooms]->lindexes[li]]->name,
						a[a[nrooms]->lindexes[li]]->startend,
						a[a[nrooms]->lindexes[li]]->depth,
						a[a[nrooms]->lindexes[li]]->x,
						a[a[nrooms]->lindexes[li]]->y,
						a[a[nrooms]->lindexes[li]]->lindexes[0]);
			}
		}
		ft_putchar('\n');
		nrooms++;
	}
	ft_printf("bleh\n");
}
