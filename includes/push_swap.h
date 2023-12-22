/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:03:15 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/21 21:09:01 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Header file for the push_swap program.
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

/**
 * @struct s_node
 * @brief Structure representing a node in the stack.
 */
typedef struct s_node
{
	int				value; /**< The value stored in the node. */
	struct s_node	*next; /**< Pointer to the next node in the stack. */
}					t_node;

/**
 * @struct s_stack
 * @brief Structure representing a stack.
 */
typedef struct s_stack
{
	t_node			*top; /**< Pointer to the top node of the stack. */
}					t_stack;

// Function prototypes
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				reverse_rotate(t_stack *stack);
void				push_swap(t_stack *a, t_stack *b);
void				print_stack(t_stack *stack);

#endif