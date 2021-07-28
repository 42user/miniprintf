#include "printf.h"

t_ptf *list;

void		putin_list(void)
{
	list->dot = 0;
	list->zero = 0;
	list->minus = 0;
	list->width = 0;
	list->precisn = 0;
}

void		printer(void)
{
	if (list->spec == 'c' || list->spec == '%')
		print_char();
	else if (list->spec == 's')
		print_string();
	else if (list->spec == 'p')
		print_pointer();
	else if (list->spec == 'd' || list->spec == 'i')
		print_nbr();
	else if (list->spec == 'u')
		print_unsigned();
	else if (list->spec == 'x' || list->spec == 'X')
		print_hex();
	else 
		return ;
}

static void	print_fmt(char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			putin_list();
			i += set_flag(fmt + i);
			i += set_width(fmt + i);
			i += set_prec(fmt + i);
			i += set_spec(fmt + i);
			printer();
		}
		if (fmt[i] != '\0' && fmt[i] != '%')
		{
			list->len++;
			write(1, &fmt[i], 1);
			i++;
		}
	}
	return ;
}

int			check_alloc(char *fmt)
{
	if (!(list = malloc(sizeof(t_ptf) + 1)))
		return (-1);
	if (!(list->specs = malloc(sizeof(char) * 10)))
		return (-1);
	if (!fmt)
		return (-1);
	list->specs = "cspdiuxX%";
	list->error = 1;
	list->len = 0;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	char	*fmt;

	fmt = (char *)format;
	if (check_alloc(fmt) < 0)
		return (-1);
	list->fmt = fmt;
	va_start(list->ar, format);
	print_fmt(list->fmt);
	va_end(list->ar);
	if (list->error == -1)
		return (-1);
	return (list->len);
}

int			main()
{
	        ft_printf("%s %d %s", "Just", 4, "laughs");
			write (1, "\n", 1);
		    return (0);
}
