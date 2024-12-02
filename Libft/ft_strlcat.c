/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:41:42 by hel-mamo          #+#    #+#             */
/*   Updated: 2022/10/24 12:43:02 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ds;
	size_t	sc;

	i = 0;
	sc = ft_strlen(src);
	if (!dest && dstsize == 0)
		return (sc);
	ds = ft_strlen(dest);
	if (dstsize <= ds)
		return (dstsize + sc);
	j = dstsize - ds - 1;
	while (src[i] && i < j)
	{
		dest[i + ds] = src[i];
		i++;
	}
	dest[i + ds] = '\0';
	return (ds + sc);
}
