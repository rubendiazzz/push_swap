/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:25:23 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 15:26:01 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack_operations.h"

void	push(t_node **dest_stack, t_node **src_stack)
{
	t_node	*top_node;

	if (!src_stack || !(*src_stack))
		return ;
	top_node = *src_stack;
	*src_stack = (*src_stack)->next;
	if (*src_stack)
		(*src_stack)->prev = 0;
	top_node->next = *dest_stack;
	if (*dest_stack)
		(*dest_stack)->prev = top_node;
	*dest_stack = top_node;
}

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = 0;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = 0;
}

void	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = 0;
	last->prev = 0;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
