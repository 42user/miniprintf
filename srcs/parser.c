#include "printf.h"

int	set_flag(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] == '-' || fmt[i] == '0')
	{
		if (fmt[i] == '-')
			list->minus = 1;
		else
			list->zero = 1;
		i++;
	}
	return (i);
}

int	set_width(char *fmt)
{
	int i;

	i = 0;
	if (fmt[i] == '*')
	{
		if ((list->width = va_arg(list->ar, int)) < 0)
		{
			list->width = -list->width;
			list->minus = 1;
			list->zero = 0;
		}
		return (1);
	}
	while (ft_isdigit(fmt[i]))
		i++;
	if (i > 0)
		list->width = ft_atoi(fmt);
	if (list->width < 0)
	{
		list->width = -list->width;
		list->minus = 1;
		list->zero = 0;
	}
	return (i);
}

int	set_prec(char *fmt)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (fmt[i] != '.')
		return (0);
	list->dot = 1;
	i++;
	if (fmt[i] == '*')
	{
		if ((k = va_arg(list->ar, int)) < 0)
		{
			k = 0;
			list->dot = 0;
		}
		list->precisn = k;
		return (i + 1);
	}
	list->precisn = ft_atoi(fmt + i);
	if (list->precisn < 0)
		list->dot = 0;
	while (ft_isdigit(fmt[i]))
		i++;
	return (i);
}

int	set_spec(char *fmt)
{
	if (ft_strchr(list->specs, *fmt))
		list->spec = *fmt;
	else
		list->spec = '\0';
	return (1);
}
