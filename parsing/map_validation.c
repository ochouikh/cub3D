/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:39:44 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	valid_characters(char **map)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	check = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'E' || map[i][j] == 'W')
				check++;
			if (!ft_str_chr("01NSEW DXTRF", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (check != 1)
		return (1);
	return (0);
}

int	valid_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid_door(char **map, int i, int j)
{
	if (map[i][0] == 'D' || map[i][ft_strlen(map[i]) - 1] == 'D')
		return (0);
	if ((map[i][j - 1] == '1' && map[i][j + 1] == '1')
	&& (map[i - 1][j] == '1' || map[i + 1][j] == '1'))
		return (0);
	if ((map[i][j - 1] == '1' || map[i][j + 1] == '1')
	&& (map[i - 1][j] == '1' && map[i + 1][j] == '1'))
		return (0);
	if ((map[i][j - 1] != '1' || map[i][j + 1] != '1')
	&& (map[i - 1][j] != '1' || map[i + 1][j] != '1'))
		return (0);
	return (1);
}

int	check_valid_door(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
			{
				if (!valid_door(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_sprite(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] == 'X' || map[i][ft_strlen(map[i]) - 1] == 'X'
		|| map[i][0] == 'T' || map[i][ft_strlen(map[i]) - 1] == 'T'
		|| map[i][0] == 'R' || map[i][ft_strlen(map[i]) - 1] == 'R'
		|| map[i][0] == 'F' || map[i][ft_strlen(map[i]) - 1] == 'F')
			return (0);
		i++;
	}
	return (1);
}
