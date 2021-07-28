/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:25:35 by user              #+#    #+#             */
/*   Updated: 2020/11/26 16:07:56 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			l;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	l = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (i + l > len)
			return (NULL);
		if (ft_strncmp(haystack, needle, l) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
