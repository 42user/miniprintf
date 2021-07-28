/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:03:12 by user              #+#    #+#             */
/*   Updated: 2020/12/31 21:03:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_char(void)
{
	char	*fmt;
	char	c;
	char	*res;

	if ((res = malloc(sizeof(char) * 2)) == NULL)
	{
		list->error = -1;
		return ;
	}
	if (list->spec == '%')
		c = '%';
	else
		c = (char)va_arg(list->ar, int);
	res[0] = c;
	res[1] = '\0';
	if (c == '\0' && list->width > 0)
		list->width--;
	fmt = widthfiller(res);
	if (c == '\0')
		return (print_eof(fmt));
	putfmt(fmt);
	free(fmt);
}

void		print_string(void)
{
	char	*fmt;
	size_t	len;

	fmt = va_arg(list->ar, char*);
	if (fmt == NULL)
		fmt = widthfiller(ft_memcpy(malloc(sizeof(char) * 8), "(null)", 8));
	else
	{
		len = ft_strlen(fmt);
		fmt = ft_memcpy(malloc(sizeof(char) * len + 1), fmt, len + 1);
		if (fmt == NULL)
		{
			list->error = -1;
			return ;
		}
		fmt = widthfiller(fmt);
	}
	putfmt(fmt);
	free(fmt);
}

void		print_pointer(void)
{
	char			*fmt;
	char			*cp;
	unsigned long	x;

	x = va_arg(list->ar, unsigned long);
	if (x == 0 && list->dot == 1 && list->precisn == 0)
		fmt = ft_memset(malloc(1), '\0', 1);
	else
		fmt = check_hex(x);
	if (fmt == NULL)
	{
		list->error = -1;
		return ;
	}
	fmt = nbr_precison(fmt);
	cp = fmt;
	fmt = ft_strjoin("0x", fmt);
	free(cp);
	fmt = widthfiller(fmt);
	putfmt(fmt);
	free(fmt);
}

void		print_nbr(void)
{
	char			*fmt;
	long int		x;

	x = va_arg(list->ar, int);
	if (x == 0 && list->dot == 1 && list->precisn == 0)
		fmt = ft_memset(malloc(1), '\0', 1);
	else
		fmt = ft_itoa(x);
	if (fmt == NULL)
	{
		list->error = -1;
		return ;
	}
	fmt = nbr_precison(fmt);
	fmt = widthfiller(fmt);
	putfmt(fmt);
	free(fmt);
}

void		print_unsigned(void)
{
	char		*fmt;
	unsigned	x;

	x = va_arg(list->ar, int);
	if (x == 0 && list->dot == 1 && list->precisn == 0)
		fmt = ft_memset(malloc(1), '\0', 1);
	else
		fmt = unsigned_itoa(x);
	if (fmt == NULL)
	{
		list->error = -1;
		return ;
	}
	fmt = nbr_precison(fmt);
	fmt = widthfiller(fmt);
	putfmt(fmt);
	free(fmt);
}
