/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grow_from_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 17:22:17 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/07 17:57:14 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	set_depth(t_l_data *d, t_l_rooms *end)
{
	int		*t;
	int		lalen;
	int		depth;
	size_t	index;
	

	index = 0;
	depth = 0;
	t = (int *)malloc(sizeof(int) * (d->nrooms + 1));
	t[d->nrooms] = -2; //end of array
	while (index < d->nrooms)
	{
		t[index] = -1;
		index++;
	}
	index = 0;
	while (index < d->nrooms)
	{
	lalen = end->larray_len;
	while (lalen--)
	{
		end->larray[lalen]->rptr->depth = end->larray[lalen]->rptr->depth == -1 ? depth : end->larray[lalen]->rptr->depth;
	}
	}

}
