/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:16:16 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 16:28:06 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linked_list_utils.h"
#include "../includes/parse_input.h"
#include "../includes/sort_five.h"
#include "../includes/sort_large.h"
#include "../includes/sort_three.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		stack_size;
	t_node	*stack_b;
	int		size;

	if (argc < 2)
		return (1);
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	size = stack_size(stack_a);
	if (size == 3)
		sort_three(&stack_a);
	else if (size == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_large(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
