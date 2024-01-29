/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:46:20 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 15:55:07 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse_input.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef bool
# define BOOL int
# define TRUE 1
# define FALSE 0
#endif

static BOOL	is_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static BOOL	check_duplicates(t_node *stack, int value)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

t_node	*parse_input(int argc, char **argv)
{
	t_node	*stack;
	long	val;
	int		i;

	stack = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]))
			exit(1);
		val = strtol(argv[i], 0, 10);
		if (val < INT_MIN || val > INT_MAX || check_duplicates(stack, val))
			exit(1);
		append_node(&stack, (int)val);
		i++;
	}
	return (stack);
}
