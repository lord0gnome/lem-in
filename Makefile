# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/05/13 14:45:17 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c get_next_line.c megaparse.c init_data.c command_funcs.c
NAME = lem-in
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJ_NAME = $(SRC_NAME:.c=.o)
	FRAMEWORKS = -framework OpenGL -framework AppKit
	STCS = libftprintf.a libft.a

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@rm -f libft.a
	@echo "Making";
	@echo "    __    ________  ____________";
	@echo "   / /   /  _/ __ )/ ____/_  __/";
	@echo "  / /    / // __  / /_    / /   ";
	@echo " / /____/ // /_/ / __/   / /    ";
	@echo "/_____/___/_____/_/     /_/     ";
	@echo "                                \n";
	@echo "                _       __  ____";
	@echo "    ____  _____(_)___  / /_/ __/";
	@echo "   / __ \/ ___/ / __ \/ __/ /_  ";
	@echo "  / /_/ / /  / / / / / /_/ __/  ";
	@echo " / .___/_/  /_/_/ /_/\__/_/     ";
	@echo "/_/                             \n";
	@echo "  \       /"
	@echo "   \     /  ";
	@echo "    \.-./ ";
	@echo "   (o\^/o)  _   _   _     __";
	@echo "    ./ \.\ ( )-( )-( ) .-'  '-.";
	@echo "     {-} \(//  ||   \\/ (   )) '-.";
	@echo "          //-__||__.-\\.       .-'";
	@echo "         (/    ()     \)'-._.-'";
	@echo "         ||    ||      \\";
	@echo "         ('    ('       ')";
	@make re -C libft && cp -f libft/libft.a ./
	@make re -C printf && cp -f printf/libftprintf.a ./
	@echo "Making final $(NAME) executable"
	@$(CC) -o $(NAME) $(OBJ_NAME) $(STCS)

$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	@rm -f *.o
	@rm -f *.a
	@make fclean -C libft
	@make clean -C printf

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
