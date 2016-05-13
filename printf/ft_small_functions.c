/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:03:28 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/15 12:47:06 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	do_else(char *r, int i, t_data *d)
{
	if (r)
		ft_putstr(r);
	free(r);
	d->retplusreal += i;
}

int			read_until(const char *restrict f, char *r, t_data *d)
{
	char	*bck;
	int		i;

	i = 0;
	bck = r;
	while (f[i] && f[i] != '%')
		i++;
	if (bck)
	{
		if (!(r = (char *)malloc(sizeof(char) * (i + 1) + ft_strlen(bck))))
			return (-1);
		ft_strcpy(r, bck);
		ft_strncpy(r + ft_strlen(bck), f, i);
		r[ft_strlen(bck) + i] = '\0';
	}
	else
	{
		if (!(r = (char *)malloc(sizeof(char) * (i + 1))))
			return (-1);
		ft_strncpy(r, f, i);
		r[i] = '\0';
	}
	do_else(r, i, d);
	return (i);
}

int			reinit_form(t_form **form)
{
	if (!(*form = (t_form *)malloc(sizeof(t_form))))
		return (-1);
	(*form)->prec = -1;
	(*form)->width = -1;
	(*form)->left = 0;
	(*form)->zero = 0;
	(*form)->space = 0;
	(*form)->plus = 0;
	(*form)->force = 0;
	(*form)->percent = -1;
	(*form)->type = 0;
	(*form)->bigsmall = 0;
	(*form)->nega = 0;
	return (1);
}

int			init_data(t_data **d)
{
	if (!(*d = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	(*d)->i = 0;
	(*d)->ib = 42;
	(*d)->retplusreal = 0;
	(*d)->nargs = 0;
	(*d)->string = NULL;
	(*d)->type = 0;
	(*d)->ospace = ' ';
	(*d)->bck = -1;
	(*d)->neg = 0;
	(*d)->tmp = 0;
	return (1);
}
