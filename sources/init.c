/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 17:06:52 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/28 16:56:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_l_data	*init_l_data(t_l_error *error)
{
	t_l_data *d;

	if ((d = (t_l_data *)malloc(sizeof(t_l_data))) == NULL)
		return (NULL);
	d->l = NULL;
	d->newl = NULL;
	d->i = 0;
	d->i2 = 0;
	d->fd = 0;
	d->help = 0;
	d->visual = 0;
	d->nocomment = 0;
	d->ignoreerr = 0;
	d->err = error;
	d->ants = NULL;
	d->rooms = NULL;

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
