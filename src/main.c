#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = stack_init(argc - 1);
	b = stack_init(argc - 1);
	if (!parse_args_to_stack(a, argc, argv))
	{
		ft_putstr("Error\n");
		stack_free(a);
		stack_free(b);
		return (1);
	}
	push_swap(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
