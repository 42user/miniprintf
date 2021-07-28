/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:39:55 by user              #+#    #+#             */
/*   Updated: 2020/11/23 21:41:32 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*cut;
	size_t	len;

	if (s1 != NULL && set != NULL)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		len = ft_strlen(s1);
		while (len && ft_strchr(set, s1[len]))
			len--;
		len++;
		cut = ft_substr((char*)s1, 0, len);
		return (cut);
	}
	return (NULL);
}
