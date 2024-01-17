/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:02:21 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/17 12:15:58 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "stack.h"

bool	is_duplicate(t_stack *stack, int value);
bool	is_valid_number(char *str, int *number);

// Function to print an error message
void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
}

// Function to free the stack
void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top != NULL)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
}

// Placeholder for the sorting function
void	sort_stack(t_stack *stack)
{
	// Sorting logic here
}

// Placeholder for the display operations function
void	display_operations(void)
{
	// Display logic here
}

int	main(int argc, char **argv)
{
	t_stack	stackA = {NULL, 0};;
	int		i;
	int		num;

	i = 1;
	while (i < argc)
	{
		if (is_valid_number(argv[i], &num) && !is_duplicate(&stackA, num))
			push(&stackA, num);
		else
		{
			print_error();
			free_stack(&stackA);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	sort_stack(&stackA);
	display_operations();
	free_stack(&stackA);
	return (0);
}

bool	is_duplicate(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	is_valid_number(char *str, int *number)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	*number = ft_atoi(str) * sign;
	return (true);
}