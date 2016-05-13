/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 13:38:55 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 14:49:33 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_makestr(char *str)
{
	int		len;
	char	*ret;

	len = ft_strlen(str);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	ret[len] = '\0';
	ft_strncpy(ret, str, len);
	return (ret);
}
