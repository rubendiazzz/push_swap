/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:07:44 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 16:15:08 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_large.h"

int	get_max_bits(t_node *stack)
{
	int		max_bits;
	int		max_num;
	t_node	*tmp;

	max_bits = 0;
	max_num = 0;
	tmp = stack;
	while (tmp != 0)
	{
		if (tmp->value > max_num)
		{
			max_num = tmp->value;
		}
		tmp = tmp->next;
	}
	while ((max_num >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void	distribute_elements(t_node **stack_a, t_node **stack_b, int size,
		int bit)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (((*stack_a)->value >> bit) & 1)
		{
			rotate(stack_a);
		}
		else
		{
			push(stack_b, stack_a);
		}
		j++;
	}
}

void	sort_large(t_node **stack_a, t_node **stack_b)
{
	int	max_bits;
	int	size;
	int	i;

	max_bits = get_max_bits(*stack_a);
	size = stack_size(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		distribute_elements(stack_a, stack_b, size, i);
		while (*stack_b != 0)
		{
			push(stack_a, stack_b);
		}
		i++;
	}
}
