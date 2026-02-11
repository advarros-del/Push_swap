# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:46:01 by adrvarga          #+#    #+#              #
#    Updated: 2026/02/11 19:15:57 by adrvarga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the file that the makfile it's going to create.
NAME = push_swap

#compiler that you will going to use
CC = cc 

#Flags that the compiler have to be use.
FLAGS = -Wextra -Werror -Wall

 

#All files .c that you need
SRC = ft_atoi.c\
	check_args.c\
	ft_lstclear.c\
	funcion_rara.c\
	is_dg_or_sp.c\
	lst_function.c\
	main.c\
	push_swap.c\
	rules.c\
	utils.c\
	ft_split.c\
	
#Transform all the .c to .o
OBJ := $(SRC:%.c=%.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
