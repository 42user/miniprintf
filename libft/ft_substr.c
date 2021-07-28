/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:40:53 by user              #+#    #+#             */
/*   Updated: 2020/11/23 21:38:52 by fharissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if ((s == NULL) || len <= 0 || ft_strlen(s) <= start)
		return (ft_strdup("\0"));
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	while (len--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
