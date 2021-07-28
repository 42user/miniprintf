#include "printf.h"

void	putchar_str(char *dst, int n, char c)
{
	dst[n] = c;
}

int		hex_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char	check_char(char *base, int n)
{
	if (list->spec == 'x' && n >= 10)
		return (base[n] + 32);
	if (list->spec == 'p' && n >= 10)
		return (base[n] + 32);
	return (base[n]);
}

void	rebase(unsigned long nb, char *dst, int i)
{
	if (nb >= 16)
	{
		rebase(nb / 16, dst, i - 1);
		rebase(nb % 16, dst, i);
	}
	else
		putchar_str(dst, i, check_char("0123456789ABCDEF", nb));
}

char	*check_hex(unsigned long nb)
{
	int		len;
	char	*str;

	len = hex_len(nb);
	str = malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	rebase(nb, str, len - 1);
	return (str);
}
