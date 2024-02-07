/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:31:35 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/02/07 12:31:36 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string.
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
t_stack	*ft_parse(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		ft_error();
	else if (argc == 2)
		stack_a = ft_parse_args_quoted(argv);
	else
	{
		list_args(argv, &stack_a);
	}
	return (stack_a);
}
