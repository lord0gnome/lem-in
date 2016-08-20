/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:12:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/20 16:09:16 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_arguments(t_l_data *d)
{
	ft_printf("The *l value is \"%s\"\n
		The *newl value is \"%s\"\n
		The nants value is \"%d\"\n
		The i value is \"%d\"\n
		The i2 value is \"%d\"\n
		The fd value is \"%d\"\n
		The cx value is \"%d\"\n
		The cy value is \"%d\"\n
		The help value is \"%d\"\n
		The visual value is \"%d\"\n
		The nocomment value is \"%d\"\n
		The ignoreerr value is \"%d\"\n
		The order value is \"%d\"\n
		The command value is \"%d\"\n", d->l, d->newl, d->nants, d->i, d->i2
		, d->fd
		, d->cx, d->cy, d->help, d->visual, d->nocomment
		, d->ignoreerr, d->order, d->command);
}
