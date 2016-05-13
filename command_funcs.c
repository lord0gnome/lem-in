/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:12:36 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 15:44:13 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	do_room(t_par *global)
{
	t_room *new;

	new = (t_room *)malloc(sizeof(t_room));
	if (global->command)
	{
		if ((!ft_strcmp(global->command, "start")))
		{
			new->start_end = 1;
			global->start = new;
		}
		else if (!(ft_strcmp(global->command, "end")))
		{
			new->start_end = -1;
			global->end = new;
		}
	}
	else
		new->start_end = 0;
}

char	*is_command(char *str)
{
	if (!(ft_strcmp(str, "start")) || !(ft_strcmp(str, "end")))
		return (str);
	return (NULL);
}
