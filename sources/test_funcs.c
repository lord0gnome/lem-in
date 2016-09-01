/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 13:47:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/01 15:37:57 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	test_ants_first(t_s_list *antsline, t_l_error *err)
{
		antsline = antsline->prev;
	while(antsline)
	{
		if (antsline->flag != 0)
			return (err->errno = 138);
		antsline = antsline->prev;
	}
	return (0);
}

int	test_strt_end(t_l_rooms *travel, t_l_error *err)
{
	char	start;
	char	end;

	start = 0;
	end = 0;
	while (travel)
	{
		if (travel->startend == 1)
			start = 1;
		if (travel->startend == 2)
			end = 1;
		travel = travel->next;
	}
	if (!start && !end)
		return (err->errno = 134);
	if (start && !end)
		return (err->errno = 135);
	if (end && !start)
		return (err->errno = 136);
	return (0);

}
