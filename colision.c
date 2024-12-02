/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:17:01 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	is_wall(t_map *map, double x, double y)
{
	int	xx;
	int	yy;

	xx = floor(x / BLOCK_SIZE);
	yy = floor(y / BLOCK_SIZE);
	if (xx < 0 || xx >= ft_strlen(map->map[0]) || yy < 0
		|| yy >= map->line_count)
		return (2);
	if (map->map[yy][xx] == '1' || map->map[yy][xx] == ' ')
		return (1);
	if (map->map[yy][xx] == 'X' || map->map[yy][xx] == 'R'
		|| map->map[yy][xx] == 'T' || map->map[yy][xx] == 'F')
		return (3);
	if (map->map[yy][xx] == 'D')
		return (4);
	if (map->map[yy][xx] == 'A')
		return (5);
	return (0);
}

int	on_hited_door(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = floor(y / BLOCK_SIZE);
	j = floor(x / BLOCK_SIZE);
	if (i < 0 || i >= map->line_count || j < 0
		|| j >= ft_strlen(map->map[0]))
		return (2);
	if (map->map[i][j] == 'D')
		return (1);
	return (0);
}

int	wall_colision(t_map *map, double x, double y)
{
	if ((is_wall(map, x, y) == 0 || is_wall(map, x, y) == 3 \
	|| is_wall(map, x, y) == 5) && (is_wall(map, x, y + 3) == 0 \
	|| is_wall(map, x, y + 3) == 3 || is_wall(map, x, y + 3) == 5) \
	&& (is_wall(map, x + 3, y) == 0 || is_wall(map, x + 3, y) == 3 \
	|| is_wall(map, x + 3, y) == 5) && (is_wall(map, x + 3, y + 3) == 0 \
	|| is_wall(map, x + 3, y + 3) == 3 || is_wall(map, x + 3, y + 3) == 5) \
	&& (is_wall(map, x, y - 3) == 0 || is_wall(map, x, y - 3) == 3 \
	|| is_wall(map, x, y - 3) == 5) && (is_wall(map, x - 3, y) == 0 \
	|| is_wall(map, x - 3, y) == 3 || is_wall(map, x - 3, y) == 5) \
	&& (is_wall(map, x - 3, y - 3) == 0 || is_wall(map, x - 3, y - 3) == 3 \
	|| is_wall(map, x - 3, y - 3) == 5) && (is_wall(map, x + 3, y - 3) == 0 \
	|| is_wall(map, x + 3, y - 3) == 3 || is_wall(map, x + 3, y - 3) == 5) \
	&& (is_wall(map, x - 3, y + 3) == 0 || is_wall(map, x - 3, y + 3) == 3 \
	|| is_wall(map, x - 3, y + 3) == 5))
		return (1);
	return (0);
}
