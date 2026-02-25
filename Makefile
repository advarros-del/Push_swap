# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrvarga <adrvarga@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/17 15:46:01 by adrvarga          #+#    #+#              #
#    Updated: 2026/02/25 20:02:19 by adrvarga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name of the file that the makfile it's going to create.
NAME = push_swap

#compiler that you will going to use
CC = cc 

#Flags that the compiler have to be use.
FLAGS = -Wextra -Werror -Wall -g 

SRC_DIR = src
OBJ_DIR = obj

#All files .c that you need
SRC = ft_atol.c\
	check_args.c\
	prepare_a.c\
	is_dg_or_sp.c\
	lst_function.c\
	main.c\
	push_swap.c\
	rules1.c\
	rules2.c\
	specific_rules.c\
	utils.c\
	ft_split.c\
	find_and_set_b.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))
	
#Transform all the .c to .o
OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

RESET = \033[0m
BOLD = \033[1m
RED = \033[31;2m
GREEN = \033[32m
YELLOW = \033[33m

TOTAL_SRCS := $(words $(SRCS))
SRC_NUM = 0
all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(BOLD)$(YELLOW)\n$(NAME) successfully compiled. $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@ 
	@$(eval SRC_NUM := $(shell expr $(SRC_NUM) + 1))
	@$(eval PERCENT := $(shell printf "%.0f" $(shell echo "scale=4; $(SRC_NUM) / $(TOTAL_SRCS) * 100" | bc)))
	@printf "$(BOLD)\rCompiling $(NAME): ["
	@$(eval PROGRESS := $(shell expr $(PERCENT) / 5))
	@printf "$(GREEN)%0.s#$(RESET)$(BOLD)" $(shell seq 1 $(PROGRESS))
	@if [ $(PERCENT) -lt 100 ]; then printf "%0.s-" $(shell seq 1 $(shell expr 20 - $(PROGRESS))); fi
	@printf "] "
	@if [ $(PERCENT) -eq 100 ]; then printf "$(GREEN)"; fi
	@printf "%d%% $(RESET)" $(PERCENT)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
