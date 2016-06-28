/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:16:32 by guiricha          #+#    #+#             */
/*   Updated: 2016/06/28 16:56:22 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"


typedef struct		s_l_ants
{
	int				id;
	void			*room;
	struct s_l_ants	*next;
}					t_l_ants;

typedef struct		s_l_rooms
{
	char			*name;
	struct s_l_ants	*ant;
}					t_l_rooms;

typedef struct		s_l_error
{
	int			errno;
	char			*errstr;
	char			errchar;

}					t_l_error;

typedef struct		s_l_data
{
	char			*l;
	char			*newl;
	int				nants;
	int				i;
	int				i2;
	int				fd;
	char			help;
	char			visual;
	char			nocomment;
	char			ignoreerr;
	t_l_error		*err;
	t_l_ants		*ants;
	t_l_rooms		*rooms;
}					t_l_data;

int	parse_fd(t_l_data *d);
int	parse_arguments(t_l_data *d, int argc, char **argv);
t_l_data	*init_l_data(t_l_error *error);
t_l_error	*init_l_error(void);

#endif
