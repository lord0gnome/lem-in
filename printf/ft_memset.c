/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:34 by guiricha          #+#    #+#             */
/*   Updated: 2016/02/24 10:55:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)b;
	while (n)
	{
		*t = (unsigned char)c;
		t++;
		n--;
	}
	return (b);
}
