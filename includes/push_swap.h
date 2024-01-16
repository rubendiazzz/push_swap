/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2024/01/15 12:43:22 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/15 12:52:30 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

=======
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
>>>>>>> dev
# include <stdlib.h>
# include <unistd.h>

// Stack structure definition
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// Function prototypes
t_stack				*parse(int ac, char **av);
void				error_message(char *msg);
void				sort_stack(t_stack *a);
void				free_stack(t_stack *a);

<<<<<<< HEAD
// Operations of stack
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
=======
/**
 * @struct s_node
 * @brief Structure representing a node in the stack.
 */
typedef struct s_node
{
	int value;           /**< The value stored in the node. */
	struct s_node *next; /**< Pointer to the next node in the stack. */
}		t_node;

/**
 * @struct s_stack
 * @brief Structure representing a stack.
 */
typedef struct s_stack
{
	int	*array;
	int	top;
}		t_stack;

// Function prototypes
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	push_swap(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	ra(t_stack *a);
void	sa(t_stack *a);
>>>>>>> dev

#endif