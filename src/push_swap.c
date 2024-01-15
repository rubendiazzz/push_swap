/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:32:16 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/15 13:01:27 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc == 1)
		return (0);
	a = parse_arguments(argc, argv);
	if (a == NULL)
	{
		error_message("Error\n");
		return (1);
	}
	sort_stack(a);
	free_stack(a);
	return (0);
}
