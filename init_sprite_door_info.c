/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_door_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:45:02 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:46:21 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	sprite_infos(t_map *map, int i, int j, int c)
{
	map->ennemi[c].centre_position.x = (j * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	map->ennemi[c].centre_position.y = (i * BLOCK_SIZE) + (BLOCK_SIZE / 2);
	map->ennemi[c].position.x = j * BLOCK_SIZE + BLOCK_SIZE / 2;
	map->ennemi[c].position.y = i * BLOCK_SIZE + BLOCK_SIZE / 2;
	if (map->map[i][j] == 'X')
		map->ennemi[c].type = INSECT;
	else if (map->map[i][j] == 'R')
		map->ennemi[c].type = DRAGON;
	else if (map->map[i][j] == 'T')
		map->ennemi[c].type = MONSTER;
	else if (map->map[i][j] == 'F')
		map->ennemi[c].type = MOON;
}

void	door_infos(t_map *map, int i, int j, int d)
{
	map->doors[d].is_door = CLOSE;
	map->doors[d].is_open_door = CLOSE;
	map->doors[d].min_distance = ULONG_MAX;
	map->doors[d].posit_x = j;
	map->doors[d].posit_y = i;
	map->doors[d].centre_x = j * BLOCK_SIZE + BLOCK_SIZE / 2;
	map->doors[d].centre_y = i * BLOCK_SIZE + BLOCK_SIZE / 2;
	map->doors[d].visible = 0;
}

int	is_sprite(char c)
{
	if (c == 'X' || c == 'R' || c == 'T' || c == 'F')
		return (1);
	return (0);
}

void	init_sprite_door_info(t_map *map)
{
	int	i;
	int	j;
	int	c;
	int	d;

	c = 0;
	d = 0;
	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if (is_sprite(map->map[i][j]))
			{
				sprite_infos(map, i, j, c);
				c++;
			}
			else if (map->map[i][j] == 'D')
			{
				door_infos(map, i, j, d);
				d++;
			}
		}
	}
}
