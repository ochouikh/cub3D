/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:40:18 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/24 21:52:02 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_lstadd_color(t_color **color, t_color *newc)
{
	t_color	*temp;

	if (!newc)
		return (0);
	if (!*color)
	{
		*color = newc;
		return (1);
	}
	temp = *color;
	while (temp->next)
		temp = temp->next;
	temp->next = newc;
	return (1);
}

void	clear_colors(t_map *map)
{
	t_color	*temp;

	while (map->color)
	{
		temp = map->color;
		map->color = map->color->next;
		free(temp->identifier);
		free(temp);
	}
}

t_color	*ft_newcolor(char *str, char *identifier)
{
	t_color	*color;
	char	**colors;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->identifier = ft_strdup(identifier);
	if (!color->identifier)
		return (free(color), NULL);
	colors = ft_split(str, ',');
	if (!colors)
		return (free(color->identifier), free(color), NULL);
	color->r = ft_atoi(colors[0]);
	color->g = ft_atoi(colors[1]);
	color->b = ft_atoi(colors[2]);
	color->next = NULL;
	ft_free(colors);
	return (color);
}

int	get_color(char *str)
{
	char	**colors;
	int		i;

	if (number_of_commas(str) != 2)
		return (0);
	colors = ft_split(str, ',');
	if (!colors)
		return (0);
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (ft_free(colors), 0);
	i = 0;
	while (colors[i])
	{
		if (!ft_integer(colors[i]))
			return (ft_free(colors), 0);
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
			return (ft_free(colors), 0);
		i++;
	}
	return (ft_free(colors), 1);
}

int	check_double_color(t_map *map)
{
	t_color		*temp;
	t_color		*temp2;

	temp = map->color;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (!ft_strcmp(temp->identifier, temp2->identifier))
				return (ft_putstr_fd("Error\nOption duplicated\n", 2), 0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}
// void	print_colors(t_map map)
// {
// 	int j = 0;
// 	while (map.color)
// 	{
// 		printf("color (r:%d,g:%d,b:%d): %s\n", map.color->r,
// map.color->g, map.color->b, map.color->identifier);
// 		j++;
// 		map.color = map.color->next;
// 	}
// }