/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:19:39 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/02/27 11:23:48 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node, bool reverse)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
	{
		if (reverse)
			rrr(a, b, false);
		else
			rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	move(t_stack_node **a, t_stack_node **b, char direction)
{
	t_stack_node	*cheapest_node;

	if (direction == 'a')
	{
		cheapest_node = get_cheapest(*a);
		if (cheapest_node->above_median
			&& cheapest_node->target_node->above_median)
			rotate(a, b, cheapest_node, false);
		else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			rotate(a, b, cheapest_node, true);
		prep_for_push(a, cheapest_node, 'a');
		prep_for_push(b, cheapest_node->target_node, 'b');
		pb(b, a, false);
	}
	else if (direction == 'b')
	{
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b, false);
	}
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move(a, b, 'a');
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move(a, b, 'b');
	}
	current_index(*a);
	min_on_top(a);
}
