/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:05:46 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 17:13:20 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_norm2(t_form *info, t_data *d, int ret, int *newret)
{
	if (d->neg && !info->zero)
		ft_putchar(d->string[0]);
	if (d->string[0] != '-' && (info->plus || info->space))
	{
		ft_putchar(info->plus ? '+' : ' ');
		*newret += 1;
	}
	while (info->prec - (ret - d->neg) > 0)
	{
		*newret += 1;
		ft_putchar('0');
		info->prec--;
	}
	if (d->string[d->neg] == '0' && d->bck == 0)
		(info->width <= 0 ? *newret -= 1 : ft_putchar(' '));
	else
		ft_putstr(d->string + d->neg);
}

static void	do_norm(t_form *info, t_data *d, int ret, int *newret)
{
	if (info->left == 0)
	{
		if (d->string[0] != '-' && (info->plus || info->space) && info->zero)
		{
			ft_putchar(info->plus ? '+' : ' ');
			*newret += 1;
			info->width--;
			info->space = 0;
			info->plus = 0;
		}
		else if (d->string[0] != '-' && (info->plus || info->space))
			info->width--;
		if (d->neg && info->zero == 1)
			ft_putchar(d->string[0]);
		while (info->width - (info->prec - (ret - d->neg)) - ret > 0)
		{
			*newret += 1;
			ft_putchar(d->ospace);
			info->width--;
		}
		do_norm2(info, d, ret, newret);
	}
}

static void	do_left(t_form *info, t_data *d, int ret, int *newret)
{
	if (d->string[0] == '-' && info->zero == 1)
		ft_putchar(d->string[0]);
	else if (d->string[0] != '-' && (info->plus || info->space))
	{
		ft_putchar(info->plus ? '+' : ' ');
		*newret += 1;
		info->width--;
	}
	while (info->prec - (ret) > 0)
	{
		ft_putchar('0');
		if (info->width > 0)
			info->width--;
		if (info->prec > 0)
			info->prec--;
		*newret += 1;
	}
	if (d->string[d->neg] == '0' && d->bck == 0)
		*newret -= 1;
	else
		ft_putstr(d->string + d->neg);
}

int			print_long(t_form *info, t_data *d, int ret)
{
	int newret;

	d->bck = info->prec;
	d->neg = d->string[0] == '-' && (info->zero == 1 || info->prec > 0) ? 1 : 0;
	d->ospace = info->zero == 1 && info->prec < 0 ? '0' : ' ';
	newret = 0;
	if (info->prec == -1 || info->prec < ret - d->neg)
		info->prec = ret - d->neg;
	if (info->width == -1)
		info->width = 0;
	do_norm(info, d, ret, &newret);
	if (info->left)
	{
		do_left(info, d, ret, &newret);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			newret++;
		}
	}
	return (ret + newret);
}
