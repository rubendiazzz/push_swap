#include "../includes/push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (stack_size(a) < 2)
		return ;
	tmp = a->array[a->top];
	a->array[a->top] = a->array[a->top - 1];
	a->array[a->top - 1] = tmp;
	ft_putstr("sa\n");
}

void	ra(t_stack *a)
{
	int	tmp;
	int	i;

	if (stack_size(a) < 2)
		return ;
	tmp = a->array[a->top];
	for (i = a->top; i > 0; i--)
		a->array[i] = a->array[i - 1];
	a->array[0] = tmp;
	ft_putstr("ra\n");
}

void	rra(t_stack *a)
{
	int	tmp;
	int	i;

	if (stack_size(a) < 2)
		return ;
	tmp = a->array[0];
	for (i = 0; i < a->top; i++)
		a->array[i] = a->array[i + 1];
	a->array[a->top] = tmp;
	ft_putstr("rra\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (stack_size(a) < 1)
		return ;
	push(b, pop(a));
	ft_putstr("pb\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (stack_size(b) < 1)
		return ;
	push(a, pop(b));
	ft_putstr("pa\n");
}

void	rrb(t_stack *b)
{
	int	tmp;
	int	i;

	if (stack_size(b) < 2)
		return ;
	tmp = b->array[0];
	for (i = 0; i < b->top; i++)
		b->array[i] = b->array[i + 1];
	b->array[b->top] = tmp;
	ft_putstr("rrb\n");
}

void	rb(t_stack *b)
{
	int	tmp;
	int	i;

	if (stack_size(b) < 2)
		return ;
	tmp = b->array[b->top];
	for (i = b->top; i > 0; i--)
		b->array[i] = b->array[i - 1];
	b->array[0] = tmp;
	ft_putstr("rb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putstr("ss\n");
}

void	sb(t_stack *b)
{
	int	tmp;

	if (stack_size(b) < 2)
		return ;
	tmp = b->array[b->top];
	b->array[b->top] = b->array[b->top - 1];
	b->array[b->top - 1] = tmp;
	ft_putstr("sb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_putstr("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_putstr("rrr\n");
}
