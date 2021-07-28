/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:07:49 by user              #+#    #+#             */
/*   Updated: 2020/11/25 21:27:45 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] && dstlen < dstsize)
		dstlen++;
	while ((src[srclen]) && ((dstlen + srclen + 1) < dstsize))
	{
		dst[dstlen + srclen] = src[srclen];
		srclen++;
	}
	if (dstlen != dstsize)
		dst[dstlen + srclen] = '\0';
	return (dstlen + ft_strlen(src));
}
