/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 03:50:57 by user              #+#    #+#             */
/*   Updated: 2020/11/23 21:32:13 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	const char	*endptr;

	endptr = s + ft_strlen(s);
	if (*endptr == (char)c)
		return ((char *)endptr);
	if (ft_strlen(s) != 0)
		while (endptr > s)
		{
			if (*endptr == (char)c)
				return ((char *)endptr);
			if (*--endptr == (char)c)
				return ((char *)endptr);
		}
	return (NULL);
}
