/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:34:26 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 15:00:39 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_par	*init_par(void)
{
	t_par	*data;

	if (!(data = (t_par *)malloc(sizeof(t_par))))
		return (NULL);
	data->l = NULL;
	data->l_len = -1;
	data->error = NULL;
	data->command = NULL;
	data->num_ants = -1;
	data->start = NULL;
	data->end = NULL;
	return (data);
}
