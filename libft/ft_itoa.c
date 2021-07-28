/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:12:58 by user              #+#    #+#             */
/*   Updated: 2020/11/25 13:49:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nsize(int n, int sign)
{
	int		size;

	size = sign;
	if (!n)
		return (1);
	while (n && ++size)
		n = n / 10;
	return (size);
}

char		*ft_itoa(int n)
{
	int		sign;
	int		size;
	char	*dst;

	sign = 1;
	if (n >= 0)
		sign = 0;
	size = ft_nsize(n, sign);
	if (!(dst = malloc(sizeof(char) * size + 1)))
		return (NULL);
	dst[size--] = '\0';
	if (sign == 1)
		n = -n;
	while (size >= 0)
	{
		dst[size--] = (unsigned int)n % 10 + '0';
		n = (unsigned int)n / 10;
	}
	if (sign == 1)
		dst[0] = '-';
	return (dst);
}
