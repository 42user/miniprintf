/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:20:26 by user              #+#    #+#             */
/*   Updated: 2020/11/23 21:36:04 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	i = -1;
	if (s != NULL && f != NULL)
	{
		if (!(dst = malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		while (s[++i])
			dst[i] = f(i, s[i]);
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
