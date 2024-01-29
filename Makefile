# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 16:53:54 by rdiaz-fr          #+#    #+#              #
#    Updated: 2024/01/29 16:54:53 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

FT_PRINTF_SRC_DIR = ./printf/
FT_PRINTF_OBJ_DIR = ./printf/

LDFLAGS = -L$(FT_PRINTF_OBJ_DIR) -lftprintf

SRCS = $(SRC_DIR)main.c $(SRC_DIR)stack_operations.c $(SRC_DIR)sort_three.c \
       $(SRC_DIR)sort_five.c $(SRC_DIR)sort_large.c $(SRC_DIR)linked_list_utils.c \
       $(SRC_DIR)parse_input.c $(SRC_DIR)utility_functions.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

INCLUDES = -I $(INC_DIR) -I $(FT_PRINTF_SRC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF_OBJ_DIR)libftprintf.a:
	@make -C $(FT_PRINTF_SRC_DIR)

$(NAME): $(FT_PRINTF_OBJ_DIR)libftprintf.a $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
