/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:25:12 by hel-mamo          #+#    #+#             */
/*   Updated: 2022/10/22 10:31:09 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_setcheck(char ch, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*result;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_setcheck(s1[start], set))
		start++;
	while (start < end && ft_setcheck(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i++] = s1[start++];
	}
	result[i] = '\0';
	return (result);
}
