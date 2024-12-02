/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:34 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/24 11:58:51 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	player_infos(t_map *map, int i, int j)
{
	map->player.x = (j * BLOCK_SIZE) + BLOCK_SIZE / 2;
	map->player.y = (i * BLOCK_SIZE) + BLOCK_SIZE / 2;
	if (map->map[i][j] == 'N')
		map->rotation_angle = 3 * M_PI_2;
	else if (map->map[i][j] == 'S')
		map->rotation_angle = M_PI_2;
	else if (map->map[i][j] == 'E')
		map->rotation_angle = 0;
	else if (map->map[i][j] == 'W')
		map->rotation_angle = M_PI;
}

void	count_some_infos(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				player_infos(map, i, j);
			else if (map->map[i][j] == 'X' || map->map[i][j] == 'R'
				|| map->map[i][j] == 'T' || map->map[i][j] == 'F')
				map->ennemi_count++;
			else if (map->map[i][j] == 'D')
				map->doors_count++;
			j++;
		}
		i++;
	}
	map->line_count = i;
}

int	ft_initialize(t_map *map)
{
	map->fov = 60 * (M_PI / 180);
	map->dist_proj_plane = (WIDTH / 2) / tan(map->fov / 2);
	map->rotation_speed = 2 * (M_PI / 180);
	map->walk_speed = BLOCK_SIZE / 10.0;
	map->ray = (t_rays *)malloc(NUM_RAYS * sizeof(t_rays));
	if (!map->ray)
		return (0);
	count_some_infos(map);
	map->ennemi = (t_sprite *)malloc(map->ennemi_count * sizeof(t_sprite));
	if (!map->ennemi)
		return (free(map->ray), 0);
	map->doors = (t_door *)malloc(map->doors_count * sizeof(t_door));
	if (!map->doors)
		return (free(map->ennemi), free(map->ray), 0);
	init_sprite_door_info(map);
	return (1);
}
