/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:41:18 by guiricha          #+#    #+#             */
/*   Updated: 2016/03/15 12:31:40 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putcharstr(char c, char **into, t_form *info)
{
	int		len;
	int		ret;
	int		zeroes;
	char	*str;

	len = 1;
	zeroes = ft_det_zeroes(len, info, 2);
	if (!(str = (char *)malloc(sizeof(char) * (len + zeroes + 1))))
		return (-1);
	str[len + zeroes] = '\0';
	ret = zeroes;
	while (zeroes--)
		str[zeroes] = '0';
	str[ret] = c;
	*into = str;
	return (ret + len);
}

char	*ft_putstrstr(char *input, t_form *info)
{
	int		len;
	int		ret;
	int		n;
	char	*str;
	char	*str2;

	n = 0;
	len = 0;
	str = NULL;
	if (input)
		len = ft_strlen(input);
	else
	{
		str2 = "(null)\0";
		len = 6;
	}
	if (info->prec != -1)
		len = (info->prec < len ? info->prec : len);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	ret = len;
	while (len--)
		str[n++] = input ? input[n] : str2[n];
	return (str);
}
