/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:18:49 by hel-mamo          #+#    #+#             */
/*   Updated: 2022/10/19 17:36:19 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*ptr;

	str = (char *)src;
	ptr = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	if (ptr > str)
	{
		while (i < n)
		{
			i++;
			ptr[n - i] = str[n - i];
		}
	}
	while ((i < n))
	{
		ptr[i] = str[i];
		i++;
	}
	return (dest);
}
