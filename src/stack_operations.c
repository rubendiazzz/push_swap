/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:00:46 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2023/12/21 21:11:49 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL)
	{
		ft_putnbr_fd(current->value, 1);
		ft_putchar_fd(' ', 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}

void	swap(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top->next;
	stack->top->next = temp->next;
	temp->next = stack->top;
	stack->top = temp;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		popped_value;

	if (stack->top == NULL)
		return (-1);
	temp = stack->top;
	popped_value = temp->value;
	stack->top = temp->next;
	free(temp);
	return (popped_value);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
}

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*last;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top;
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	stack->top = stack->top->next;
	last->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*second_to_last;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	last = stack->top;
	second_to_last = NULL;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
