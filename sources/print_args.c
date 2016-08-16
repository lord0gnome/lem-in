/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:12:22 by guiricha          #+#    #+#             */
/*   Updated: 2016/08/16 15:27:10 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_arguments(t_l_data *d)
{
ft_printf("The *l value is \"%s\"\nThe *newl value is \"%s\"\nThe nants value is \"%d\"\nThe i value is \"%d\"\nThe i2 value is \"%d\"\nThe fd value is \"%d\"\nThe cx value is \"%d\"\nThe cy value is \"%d\"\nThe help value is \"%d\"\nThe visual value is \"%d\"\nThe nocomment value is \"%d\"\nThe ignoreerr value is \"%d\"\nThe order value is \"%d\"\nThe command value is \"%d\"\n",d->l,d->newl,d->nants,d->i,d->i2,d->fd,d->cx,d->cy,d->help,d->visual,d->nocomment,d->ignoreerr,d->order,d->command);
}
