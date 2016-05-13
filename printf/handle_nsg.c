/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 11:24:34 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/15 11:44:59 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					han_nsg2(va_list *now, t_data *d, t_type *v, t_form *i)
{
	if (i->type == 3)
	{
		v->lo = (long unsigned int)va_arg(*now, unsigned long int);
		d->string = itoabaseu((v->lo), 10, 0);
	}
	else if (i->type == 4)
	{
		v->llu = va_arg(*now, unsigned long long int);
		d->string = itoabaseu((v->llu), 10, 0);
	}
	else if (i->type == 5)
	{
		v->uim = va_arg(*now, uintmax_t);
		d->string = itoabaseu((v->uim), 10, 0);
	}
	else if (i->type == 6)
	{
		v->uim = va_arg(*now, uintmax_t);
		d->string = itoabaseu((v->uim), 10, 0);
	}
}

int						han_nsg(va_list *now, t_data *d, t_type *v, t_form *i)
{
	int	ret;

	ret = 0;
	if (d->type == 'U')
		i->type = 3;
	if (i->type == 0)
	{
		v->x = (unsigned int)va_arg(*now, unsigned int);
		d->string = itoabaseu((v->x), 10, 0);
	}
	else if (i->type == 2)
	{
		v->hh = (unsigned char)va_arg(*now, unsigned int);
		d->string = itoabaseu((v->hh), 10, 0);
	}
	else if (i->type == 1)
	{
		v->uh = (unsigned short)va_arg(*now, unsigned int);
		d->string = itoabaseu((v->uh), 10, 0);
	}
	han_nsg2(now, d, v, i);
	ret = ft_strlen(d->string);
	ret = print_unsigned(i, d, ret);
	free(d->string);
	return (ret);
}
