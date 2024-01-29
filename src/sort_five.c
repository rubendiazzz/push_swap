/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiaz-fr <rdiaz-fr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:57:58 by rdiaz-fr          #+#    #+#             */
/*   Updated: 2024/01/29 16:06:11 by rdiaz-fr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sort_five.h"

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	sort_three(stack_a);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
}
