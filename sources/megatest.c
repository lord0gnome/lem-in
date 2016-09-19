/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megatest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 13:32:03 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/19 11:29:08 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	megatest_extended(t_l_rooms *room)
{
	ft_printf("%s%5s%s               startend[%d], depth[%s%3d%s]", RED,
	room->name, RESET,
	room->startend, CYAN,
	room->depth, RESET);
	ft_printf(", x[%03d], y[%03d], LINKTOTAL[%s%d%s]\n",
	room->x,
	room->y,
	YELLOW, room->lindexes[0], RESET);
}

void		megatest(t_l_data *d)
{
	int			*nrooms;
	int			li;
	t_l_rooms	**a;

	a = d->all;
	nrooms = d->allindex;
	while (*nrooms != -2 && *nrooms != -1)
	{
		ft_printf("index [%s%4d%s] %s%5s%s, startend[%d], depth[%s%3d%s],",
		MAGENTA, *nrooms, RESET, GREEN, a[*nrooms]->name,
		RESET, a[*nrooms]->startend, CYAN, a[*nrooms]->depth, RESET);
		ft_printf(" x[%03d], y[%03d], LINKTOTAL[%s%d%s]\n",
		a[*nrooms]->x, a[*nrooms]->y, YELLOW, a[*nrooms]->lindexes[0], RESET);
		if (a[*nrooms]->lindexes[0] != 0)
		{
			ft_printf("its links are below\n");
			li = 0;
			while (li++ < a[*nrooms]->lindexes[0])
				megatest_extended(a[a[*nrooms]->lindexes[li]]);
		}
		ft_putchar('\n');
		nrooms++;
	}
	ft_printf("%sEND OF MEGATEST%s\n", BLUE, RESET);
}
