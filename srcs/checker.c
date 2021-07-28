/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 21:02:09 by user              #+#    #+#             */
/*   Updated: 2020/12/31 21:11:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*prefiller(char *fmt, char c, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(fmt);
	if (len >= n)
		return (fmt);
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		list->error = -1;
		return ((char *)0);
	}
	res = ft_memset(res, c, n - len);
	res[n - len] = '\0';
	ft_strlcat(res, fmt, n + 1);
	free(fmt);
	return (res);
}

char	*addfiller(char *fmt, char c, size_t n)
{
	char	*res;
	size_t	len;

	len = ft_strlen(fmt);
	if (len >= n)
		return (fmt);
	res = malloc(sizeof(char) * n + 1);
	if (res == NULL)
	{
		list->error = -1;
		return ((char *)0);
	}
	res = ft_memset(res, c, n);
	res[n] = '\0';
	ft_memcpy(res, fmt, len);
	free(fmt);
	return (res);
}

char	*widthfiller(char *fmt)
{
	if (list->precisn > 0 && ft_strchr("diuxX", list->spec))
		fmt = prefiller(fmt, '0', list->precisn);
	if (list->dot != 0 && list->spec == 's')
		fmt[list->precisn] = '\0';
	if (list->zero == 1 && list->minus == 0)
		fmt = prefiller(fmt, '0', list->width);
	if (list->minus == 1)
		fmt = addfiller(fmt, ' ', list->width);
	if ((list->zero == 0) ||
	(list->zero == 1 && list->minus == 0
	&& list->precisn != 0 &&
	!ft_strrchr("dixXo", list->spec)))
		fmt = prefiller(fmt, ' ', list->width);
	return (fmt);
}

char	*nbr_precison(char *fmt)
{
	unsigned int	len;
	int				neg;

	if (compatible())
		return (fmt);
	neg = 0;
	if ((len = ft_strlen(fmt)) > 0 && fmt[0] == '-')
		neg = 1;
	if (list->dot == 1 && neg)
		list->precisn++;
	if ((unsigned int)list->precisn > len)
	{
		if (neg)
			fmt[0] = '0';
		fmt = ft_memcpy(malloc(1 * len + 2), fmt, ft_strlen(fmt) + 1);
		if (fmt == NULL)
			list->error = -1;
		fmt = prefiller(fmt, '0', list->precisn);
		if (neg == 1)
			fmt[0] = '-';
	}
	return (fmt);
}

int         compatible(void)
{
    if (list->zero == 1 && list->minus == 1)
        list->zero = 0;
    if (list->zero == 1 && list->dot == 0)
        list->precisn = list->width;
    if (list->zero == 1 && list->dot == 1)
        list->zero = 0;
    if (list->precisn == 0)
        return (1);
    return (0);
}
