# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 17:00:01 by rdiaz-fr          #+#    #+#              #
#    Updated: 2024/02/03 14:32:02 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

# Specify the directory of your ft_printf project
FT_PRINTF_DIR = ./printf/

# Include directory for your project
INCLUDES = -I $(INC_DIR)

# List of source files for your project
SRCS = $(SRC_DIR)main.c $(SRC_DIR)stack_operations.c $(SRC_DIR)sort_three.c \
       $(SRC_DIR)sort_five.c $(SRC_DIR)sort_large.c $(SRC_DIR)linked_list_utils.c \
       $(SRC_DIR)parse_input.c $(SRC_DIR)utility_functions.c

# Create a list of object files in the OBJ_DIR based on source files
OBJS = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build the push_swap program by linking with ft_printf library
$(NAME): $(OBJS) $(FT_PRINTF_DIR)libftprintf.a
	$(CC) $(OBJS) -o $(NAME) -L$(FT_PRINTF_DIR) -lftprintf

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF_DIR)libftprintf.a:
	@make -C $(FT_PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(FT_PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
