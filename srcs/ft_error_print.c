/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:31:05 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/02/07 12:31:06 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Here an error message is being printed out
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
