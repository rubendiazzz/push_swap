/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:47:27 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/21 21:11:11 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

/**
 * @file main.c
 * @brief Implementation of the main function and sorting algorithm.
 */

// Implement your main function and sorting algorithm here
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->top = NULL;
	b->top = NULL;
	i = 1;
	while (i < argc)
	{
		push(a, ft_atoi(argv[i]));
		i++;
	}
	print_stack(a);
	print_stack(b);
	push_swap(a, b);
	print_stack(a);
	print_stack(b);
	free(a);
	free(b);
	return (0);
}
