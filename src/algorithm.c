/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:51:56 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/21 21:10:43 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

// Implement your push_swap algorithm here
void	push_swap(t_stack *a, t_stack *b)
{
	while (a->top != NULL)
	{
		push(b, pop(a));
		print_stack(a);
		print_stack(b);
	}
	while (b->top != NULL)
	{
		push(a, pop(b));
		print_stack(a);
		print_stack(b);
	}
}
