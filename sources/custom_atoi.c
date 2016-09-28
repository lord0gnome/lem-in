/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:45:05 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/28 14:50:42 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		is_room_cont(char *str, t_l_data *d)
{
	while (str[d->i2] && ft_isdigit(str[d->i2]))
		d->i2++;
	if (str[d->i2] != ' ')
		return (0);
	d->i2++;
	d->cy = lem_in_atoi(str + d->i2);
	if (str[d->i2] == '-')
		d->i2++;
	if (!ft_isdigit(str[d->i2]))
		return (0);
	while (str[d->i2] && ft_isdigit(str[d->i2]))
		d->i2++;
	if (str[d->i2])
		return (0);
	return (1);
}

int		lem_in_atoi(char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = *str == '-' ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= 9)
	{
		result = result * 10 + (*str + '0');
		str++;
	}
	return ((int)result * sign);
}
