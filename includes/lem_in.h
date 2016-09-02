/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:16:32 by guiricha          #+#    #+#             */
/*   Updated: 2016/09/02 15:01:18 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../gnl/get_next_line.h"
#define START 1
#define END 2
#define NOCOMMAND 0

typedef struct s_l_rooms t_l_rooms;
typedef struct			s_l_ants
{
	int					id;
	struct s_l_rooms	*room;
	struct s_l_ants		*next;
}						t_l_ants;

typedef struct		s_l_links
{
	struct s_l_rooms		*roomptr;
	struct s_l_links		*next;
}					t_l_links;
/*
typedef struct		s_l_solu
{

	struct s_l_solu	*next;
}					t_l_solu;
*/
typedef struct		s_l_rooms
{
	char				*name;
	char				startend;
	char				used;
	int					depth;
	int					x;
	int					y;
	struct s_l_ants		*ant;
	struct s_l_rooms	*next;
	struct s_l_links	*links;
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
	int				cx;
	int				cy;
	char			help;
	char			visual;
	char			nocomment;
	char			ignoreerr;
	char			order;
	char			command;
	char			repairorder;
	t_l_error		*err;
	t_l_ants		*ants;
	t_l_rooms		*rooms;
	t_l_rooms		*frst;
	t_l_rooms		*r1;
	t_l_rooms		*r2;
	t_s_list		*lines;
}					t_l_data;

void	rec_set_depths(t_l_rooms *start, int depth);
int		test_ants_first(t_s_list *antsline, t_l_error *err);
int		test_strt_end(t_l_rooms *start, t_l_error *err);
void	print_arguments(t_l_data *d);
int		ordered_flags(t_s_list *travel, t_l_data *d);
void	test_order(t_l_data *d);
int	is_command(char *str, t_l_data *d);
int	parse_fd(t_l_data *d);
int	parse_arguments(t_l_data *d, int argc, char **argv);
int			init_link(t_l_rooms *init, t_l_rooms *link);
int			new_link(t_l_rooms *r1, t_l_rooms *r2);
int			add_link(t_l_rooms *r1, t_l_rooms *r2, t_l_data *d);
t_l_data	*init_l_data(t_l_error *error);
t_l_error	*init_l_error(void);
t_l_ants	*add_ants(t_l_data *d);
int			add_room(t_l_data *d, char *name);
int			parse_line(t_l_data *d);
int			init_all(t_l_data *d);
char		*go_to_next_line(char *str);

#endif
