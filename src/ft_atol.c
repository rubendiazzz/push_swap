#include "../inc/push_swap.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	int		i;

	sign = 1;
	result = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (sign * result);
}
