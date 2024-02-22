/* Main function handling argument parsing, error checking,
	stack initialization, sorting algorithm implementation,
	and instruction output. */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_a stack_a;
	t_stack_a stack_b;
	int *arr;
	int i;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (argc < 2)
		return (0);
	if (!arr)
		return (0);
	i = 0;
	while (++i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		if (arr[i - 1] == 0 && ft_strcmp(argv[i], "0"))
		{
			free(arr);
			return (0);
		}
	}
	stack_a.arr = arr;
	stack_a.size = argc - 1;
	stack_b.arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!stack_b.arr)
	{
		free(arr);
		return (0);
	}
	stack_b.size = 0;
	if (is_sorted(stack_a))
	{
		free(arr);
		free(stack_b.arr);
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	free(arr);
	free(stack_b.arr);
	return (0);
}