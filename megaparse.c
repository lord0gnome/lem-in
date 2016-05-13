/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:14:36 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 15:43:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_data(t_par *global)
{
	while ((get_next_line(0, &(global->l))) > 0)
	{
		if (global->l)
			if (!(ft_strcmp(global->l, "")))
				break ;
		global->l_len = ft_strlen(global->l);
		do_room(global);
		global->command = NULL;
		if (global->l && global->l[0] == '#')
			if (global->l_len > 2)
			{
				if (global->l[1] == '#')
					global->command = is_command(global->l + 2);
				else
					continue ;
				if (!global->command)
					continue ;
			}
	}
}
