/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:44:39 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/11 12:10:13 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc > 1)
    {
        if (!parse_args(argc, argv, &stack_a))
            error_exit();
        
        // Algorithm to sort the stack would be called here.
        // sort_stack(&stack_a, &stack_b);
    }
    // Free resources and exit
    free_stacks(&stack_a, &stack_b);
    return 0;
}
