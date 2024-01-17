#ifndef STACK_H
# define STACK_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

void				push(t_stack *stack, int value);
int					pop(t_stack *stack, bool *error);
void				display(t_stack *stack);
bool				is_empty(t_stack *stack);

#endif
