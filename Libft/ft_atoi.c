/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:35:22 by hel-mamo          #+#    #+#             */
/*   Updated: 2022/10/22 10:43:37 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whsp(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	sign = 1;
	number = 0;
	i = skip_whsp(str);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return ((int)(number * sign));
}
