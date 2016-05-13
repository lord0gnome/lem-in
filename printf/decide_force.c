/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_force.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:16:58 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 17:54:27 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decide_force_left(t_form *info, t_data *d)
{
	if (info->force && info->left)
	{
		if (d->type == 'p' && info->prec)
		{
			ft_putchar(d->string[info->nega++]);
			ft_putchar(d->string[info->nega++]);
		}
		else if (d->type == 'o' || d->type == 'O')
		{
			ft_putchar(d->string[info->nega++]);
		}
		else if (d->type == 'x' || d->type == 'X')
		{
			ft_putchar(d->string[info->nega++]);
			ft_putchar(d->string[info->nega++]);
		}
	}
}

void	decide_force(t_form *info, t_data *d)
{
	if (d->tmp != -92)
	{
		if (!info->left && info->force)
		{
			if (d->type == 'o' || d->type == 'O')
			{
				ft_putchar(d->string[info->nega++]);
			}
			else if (d->type == 'x' || d->type == 'X')
			{
				ft_putchar(d->string[info->nega++]);
				ft_putchar(d->string[info->nega++]);
			}
			else if (d->type == 'p')
			{
				ft_putchar(d->string[info->nega++]);
				ft_putchar(d->string[info->nega++]);
			}
		}
		decide_force_left(info, d);
		d->tmp = -92;
	}
}
