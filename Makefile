# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/09/15 16:30:34 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c parse_args.c init.c ants.c rooms.c parse_line.c \
		   links.c order_commands.c test_funcs.c convert_to_tab.c \
		   init_room_tab.c megatest.c depth.c resolve.c paths.c
NAME = lem-in
SRC_DIR = ./sources/
SRC_NDIR=$(addprefix $(SRC_DIR), $(SRC_NAME))
CC = gcc
CF = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
O_D = ./objects/
OBJ_NDIR=$(addprefix $(O_D), $(OBJ_NAME))
STCS = libftprintf.a libft.a

all: $(NAME)

$(NAME): $(OBJ_NDIR)
	@echo "Making";
	@make -s -C libft && cp -f libft/libft.a ./
	@make -s -C printf && cp -f printf/libftprintf.a ./
	@$(CC) $(CF) -Ilibft -o $(O_D)get_next_line.o -c gnl/get_next_line.c
	@$(CC) -o $(NAME) $(OBJ_NDIR) $(O_D)get_next_line.o $(STCS)
$(OBJ_NDIR):
	@mkdir -p $(O_D)
	@$(CC) $(CF) -c $(SRC_NDIR) -Iincludes -Ilibft -Iprintf -Ignl
	@mv $(OBJ_NAME) $(O_D)
clean:
	@rm -rf $(O_D)
	@make clean -s -C libft
fclean: clean
	@rm -f $(NAME)
	@rm -f *.a
	@make fclean -s -C libft
	@make clean -s -C printf 
re: fclean all

.PHONY: re fclean clean all
