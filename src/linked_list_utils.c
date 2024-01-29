/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:09:43 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 16:27:53 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linked_list_utils.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * Creates a new node with the given value.
 *
 * @param value The value to be stored in the node.
 * @return A pointer to the newly created node,
	or NULL if memory allocation fails.
 */
t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = 0;
	new_node->prev = 0;
	return (new_node);
}

/**
 * Appends a new node with the given value to the end of the linked list.
 *
 * @param head - A pointer to the head of the linked list.
 * @param value - The value to be stored in the new node.
 */

void	append_node(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(value);
	if (!(*head))
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

/**
 * @brief Frees the memory allocated for a linked list.
 *
 * This function iterates through the linked list starting from the head node,
 * frees each node, and updates the head pointer to NULL.
 *
 * @param head A pointer to the head node of the linked list.
 */
void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = 0;
}

/**
 * Calculates the size of the stack.
 *
 * @param stack A pointer to the top of the stack.
 * @return The size of the stack as an integer.
 */
int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
