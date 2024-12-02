/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:13:58 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/06/02 15:47:12 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*strr;

	i = 0;
	str = (char *)src;
	strr = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (src == dest)
		return (dest);
	while ((i < n))
	{
		strr[i] = str[i];
		i++;
	}
	return (dest);
}
