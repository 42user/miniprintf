/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:03:26 by user              #+#    #+#             */
/*   Updated: 2020/12/31 21:03:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_hex(void)
{
	unsigned int	x;
	char			*fmt;

	x = va_arg(list->ar, unsigned int);
	if (x == 0 && list->dot == 1 && list->precisn == 0)
		fmt = ft_memset(malloc(1), '\0', 1);
	else
		fmt = check_hex(x);
	fmt = nbr_precison(fmt);
	fmt = widthfiller(fmt);
	putfmt(fmt);
	free(fmt);
}

void		print_eof(char *fmt)
{
	if (list->minus == 0)
		putfmt(fmt);
	write(1, "\0", 1);
	if (list->minus == 1)
		putfmt(fmt);
	list->len++;
	free(fmt);
}

void    putfmt(char *fmt)
{
    int i;

    i = 0;
    while (fmt[i] != '\0')
    {
        write(1, &fmt[i], 1);
        i++;
    }
    list->len += i;
}

int     getlen_unsigned(unsigned n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    if (n < 0)
        len++;
    while (n)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char    *unsigned_itoa(unsigned n)
{
    unsigned int    copy;
    int             len;
    char            *res;

    copy = (n > 0) ? n : -n;
    len = getlen_unsigned(n);
    if (!(res = malloc(sizeof(char) * len + 1)))
        return (NULL);
    *(res + len--) = '\0';
    while (copy > 0)
    {
        *(res + len--) = copy % 10 + '0';
        copy /= 10;
    }
    if (n == 0)
        *res = '0';
    return (res);
}
