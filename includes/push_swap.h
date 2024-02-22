#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
}		t_stack;

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap_both(t_stack *a, t_stack *b);
void	push_both(t_stack *from, t_stack *to);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
void	print_both(t_stack *a, t_stack *b);
void	init_stack(t_stack *stack, int size);
void	free_stack(t_stack *stack);
void	sort(t_stack *a, t_stack *b);

#endif