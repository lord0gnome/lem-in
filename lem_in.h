/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:40:42 by guiricha          #+#    #+#             */
/*   Updated: 2016/05/13 15:04:45 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "printf/ft_printf.h"
#include "libft/libft.h"
#include "get_next_line.h"

typedef struct	s_par
{
	char		*l;
	int			l_len;
	char		*error;
	char		*command;
	int			num_ants;
	struct s_room	*start;
	struct s_room	*end;
}				t_par;

typedef struct	s_ants
{
				
	char			wait;
	struct s_room	*room;
}				t_ants;

typedef struct	s_room
{
	char			*name;
	char			start_end;
	struct s_ants	*ants;
	struct s_link	*links;
	int				x;
	int				y;
}				t_room;

typedef struct	s_link
{
	struct s_room	*conroom;
	struct s_link	*nlink;
}				t_link;

t_par	*init_par(void);
void	set_data(t_par *global);
void	do_room(t_par *global);
char	*is_command(char *str);

# endif
