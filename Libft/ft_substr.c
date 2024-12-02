/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:50:21 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:45 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		start++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		j;
	int		n;
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = (char *)ft_calloc(sizeof(char), 1);
		if (!dest)
			return (NULL);
		return (dest);
	}
	n = lenght(s, start, len);
	dest = (char *)ft_calloc(sizeof(char), (n + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (s[start + j] && j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	return (dest);
}
