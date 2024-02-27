# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 10:50:42 by rdiaz-fr          #+#    #+#              #
#    Updated: 2024/02/27 11:34:54 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

COMMANDS_DIR		=	$(SRC_DIR)/push.c \
						$(SRC_DIR)/rev_rotate.c \
						$(SRC_DIR)/rotate.c \
						$(SRC_DIR)/sort_stacks.c \
						$(SRC_DIR)/sort_three.c \
						$(SRC_DIR)/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)/handle_errors.c \
						$(SRC_DIR)/init_a_to_b.c \
						$(SRC_DIR)/init_b_to_a.c \
						$(SRC_DIR)/push_swap.c \
						$(SRC_DIR)/ft_split.c \
						$(SRC_DIR)/stack_init.c \
						$(SRC_DIR)/stack_utils.c

SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)


$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re