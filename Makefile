# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 20:41:17 by ppolozhe          #+#    #+#              #
#    Updated: 2018/11/09 15:42:07 by ppolozhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror 
CC = gcc

SRC = 	ft_printf.c ft_lllitoa.c pt_digit.c
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) :
	 		$(CC) $(FLAGS) -I ft_printf.h -c  $(SRC)
	 		ar rc $(NAME) $(OBJ)
clean:	
		
	rm -f $(OBJ)

fclean: clean

	rm -rf $(NAME)

re:fclean all

