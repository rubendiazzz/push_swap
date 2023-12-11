/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:45:13 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/11 11:45:27 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to parse arguments and create stack
int parse_args(int argc, char **argv, t_stack **a)
{
    // Parsing logic here
    return 1; // Return 1 if successful, 0 if there is an error
}

// Function to display error message and exit
void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

// Function to free stacks
void free_stacks(t_stack **a, t_stack **b)
{
    // Logic to free both stacks
}
