/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:44:41 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/02/03 14:48:16 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_input.h"
#include "../printf/ft_printf.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static bool	is_integer(const char *str)
{
	int	i;

	if (str[0] == '-')
		str++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_duplicates(t_node *stack, int value)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static int	parse_integer(const char *arg)
{
	int		val;
	bool	negative;

	val = 0;
	negative = false;
	if (*arg == '-')
	{
		negative = true;
		arg++;
	}
	while (*arg != '\0')
	{
		val = val * 10 + (*arg - '0');
		arg++;
	}
	if (negative)
		val = -val;
	return (val);
}

t_node	*parse_input(int argc, char **argv)
{
	t_node		*stack;
	int			i;
	const char	*arg;
	int			val;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		if (!is_integer(arg))
		{
			write(2, "Error: Argument is not a valid integer.\n", 40);
			exit(1);
		}
		val = parse_integer(arg);
		ft_printf("Parsed value: %d\n", val);
		if (val < INT_MIN || val > INT_MAX || !check_duplicates(stack, val))
		{
			write(2, "Error: Invalid integer value or duplicate detected.\n",
				54);
			exit(1);
		}
		append_node(&stack, val);
		i++;
	}
	return (stack);
}
