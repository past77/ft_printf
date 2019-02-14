# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 20:41:17 by ppolozhe          #+#    #+#              #
#    Updated: 2019/01/22 14:18:41 by ppolozhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc
HEADER = -I ft_printf

SRC = 	ft_printf.c  pt_digit.c pt_string.c lib_fn1.c lib_fn2.c lib_fn3.c perc_and_char.c \
 annonce_flags.c choose_type.c ft_write_pt1.c ft_write_pt2.c ft_write_pt3.c write_press.c \
 write_main_press.c ft_rapist.c fills.c ft_uns_digits.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
		$(CC) $(FLAGS) $(HEADER) -c  $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
