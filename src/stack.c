/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:26:14 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/17 11:26:49 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		perror("Failed while trying to allocate memory for new node.");
		exit(EXIT_FAILURE);
	}
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	pop(t_stack *stack, bool *error)
{
	t_node	*top_node;
	int		value;

	if (is_empty(stack))
	{
		*error = true;
		return (0);
	}
	top_node = stack->top;
	value = top_node->value;
	stack->top = top_node->next;
	free(top_node);
	stack->size--;
	*error = false;
	return (value);
}

void	display(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

bool	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}
