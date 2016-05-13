/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:17:00 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 11:59:33 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 9

int					get_next_line(int fd, char **line);
typedef struct		s_stock
{
	int				i;
	int				s;
	char			*buff;
	int				fd;
	struct s_stock	*next;

}					t_stock;

typedef struct		s_ints
{
	int				i;
	int				ret;
	int				size;
}					t_ints;

#endif
