/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:58:33 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:56 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static size_t	ft_count_wds(const char *str, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_create_wd(const char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*tmp;

	i = 0;
	len = 0;
	while (str[len] && str[len] != c)
		len++;
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	**split_process(char **result, char const *s, char c, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[j] && i < len)
	{
		if (s[j] != c)
		{
			result[i] = ft_create_wd(&s[j], c);
			if (!result[i])
				return (ft_free(result));
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	char	**result;

	if (!s)
		return (NULL);
	len = ft_count_wds(s, c);
	result = (char **)malloc(sizeof(char *) * (len + 1));
	if (!result)
		return (NULL);
	result = split_process(result, s, c, len);
	return (result);
}
