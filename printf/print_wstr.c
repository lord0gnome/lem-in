/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:19:49 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/14 16:35:43 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_norm(t_form *info, wchar_t *str, int *newret, int count)
{
	if (info->left == 0)
	{
		while (info->width - count > 0)
		{
			if (info->zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*newret += 1;
			info->width--;
		}
		ft_putwidestr(str, info);
	}
}

static void	do_left(t_form *info, wchar_t *str, int *newret, int ret)
{
	if (info->left == 1)
	{
		ft_putwidestr(str, info);
		while (info->width - ret > 0)
		{
			ft_putchar(' ');
			info->width--;
			*newret += 1;
		}
	}
}

int			print_wstr(t_form *info, int ret, wchar_t *str)
{
	int newret;
	int count;

	newret = 0;
	if (info->prec != -1 && info->prec < ret)
		ret = info->prec;
	count = info->prec;
	if (count == -1 || count > ret)
		count = ret;
	do_norm(info, str, &newret, count);
	do_left(info, str, &newret, ret);
	return (ret + newret);
}
