# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 15:43:44 by rdiaz-fr          #+#    #+#              #
#    Updated: 2023/12/21 16:11:44 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
LIBFT_LIB = libft.a
PUSH_SWAP = push_swap
SRC = src/main.c src/stack_operations.c src/algorithm.c
OBJ = $(SRC:.c=.o)

all: $(LIBFT_LIB) $(PUSH_SWAP)

$(LIBFT_LIB):
	make -C $(LIBFT)

$(PUSH_SWAP): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(PUSH_SWAP)

re: fclean all

.PHONY: all clean fclean re