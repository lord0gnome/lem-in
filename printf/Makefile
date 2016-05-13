# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/04/12 16:38:13 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_length_funcs.c ft_parse_and_store.c \
		   ft_printf.c utilities.c print_nocon.c decide_force.c \
		   ft_small_functions.c ft_very_small_functions.c ft_det_zeroes.c \
		   ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c print_char.c \
		   ft_strcpy.c ft_strncpy.c ft_strlen.c itoabase.c ft_memset.c \
		   ft_putwidechar.c print_str.c print_wstr.c print_long.c \
		   handle_int.c handle_oct.c handle_hex.c handle_nsg.c print_unsigned.c
NAME = libftprintf.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ_NAME)
	@ar cr $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
