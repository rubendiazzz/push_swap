/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:56:17 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 15:57:02 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_three.h"

void	sort_three(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (top > middle && middle < bottom && bottom > top)
		swap(stack);
	else if (top > middle && middle > bottom && bottom < top)
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if (top > middle && middle < bottom && bottom < top)
		rotate(stack);
	else if (top < middle && middle > bottom && bottom > top)
	{
		swap(stack);
		rotate(stack);
	}
	else if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(stack);
}
