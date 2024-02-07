# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 13:48:18 by yogun             #+#    #+#              #
#    Updated: 2024/02/07 12:33:53 by rdiaz-fr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/push_swap.c

SRC_2 =	srcs/algorithm.c \
		srcs/ft_add_back.c \
		srcs/ft_stack_new.c \
		srcs/ft_check_utils.c \
		srcs/ft_parse.c \
		srcs/solver_utils_ab.c \
		srcs/solver_utils_ba.c \
		srcs/ft_rotate_and_push.c \
		srcs/operations.c \
		srcs/operations_2.c \
		srcs/operations_3.c \
		srcs/ft_check_dup.c \
		srcs/ft_check_sorted.c \
		srcs/ft_error_print.c \
		srcs/ft_free.c \
		srcs/lst_utils.c \
		srcs/lst_utils_2.c \
		srcs/ft_parse_args_quoted.c \
		srcs/ft_list_args.c \
		srcs/ft_check_args.c \
		srcs/ft_sort_big.c \
		srcs/ft_sort_three.c \
		srcs/ft_rotate_type.c \

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re