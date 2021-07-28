#include "libft.h"

int		ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign -= 2;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	while (*str <= '9' && *str >= '0')
		result = (result * 10) + (*str++ - 48);
	return (result * sign);
}
