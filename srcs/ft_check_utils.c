/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:30:54 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/02/07 12:40:40 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// chec if the chracter is negative
int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

// check if the character is digit
int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

// check if character is space character
int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

// function to check if given arguments is valid
int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (false);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
