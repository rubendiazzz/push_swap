/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:43:09 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/11 11:46:32 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header guard to prevent double inclusion
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

// Define your stack structure
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Function prototypes for stack operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// Utility function prototypes
int		parse_args(int argc, char **argv, t_stack **a);
void	error_exit(void);
void	free_stacks(t_stack **a, t_stack **b);

#endif
