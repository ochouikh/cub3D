/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:36:29 by hel-mamo          #+#    #+#             */
/*   Updated: 2022/10/19 17:31:56 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getlength(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_itoa_pos(char *ptr, long n, int len)
{
	char	tmp;

	ptr[len] = '\0';
	while (n)
	{
		tmp = (n % 10) + 48;
		ptr[--len] = tmp;
		n = n / 10;
	}
	return (ptr);
}

static char	*ft_itoa_ne(char *ptr, long n, int len)
{
	int	tmp;

	ptr[len] = '\0';
	n = (-1) * n;
	ptr[0] = '-';
	while (n)
	{
		tmp = (n % 10) + 48;
		ptr[--len] = tmp;
		n = n / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	num;
	char	*ptr;

	num = n;
	if (num == 0)
		return (ft_strdup("0"));
	len = getlength(num);
	sign = 1;
	if (num < 0)
		sign = 2;
	ptr = (char *) malloc(sizeof(char) * len + sign);
	if (!ptr)
		return (NULL);
	if (num < 0)
		return (ft_itoa_ne(ptr, num, len + 1));
	return (ft_itoa_pos(ptr, num, len));
}
