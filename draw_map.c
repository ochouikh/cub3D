/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:03:52 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/22 14:32:22 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	draw_map_utils(t_map *map)
{
	double	ray_angle;
	int		i;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = map->rotation_angle + \
		atan((i - (NUM_RAYS / 2)) / map->dist_proj_plane);
		ray_angle = fix_angle(ray_angle);
		render_walls(map, ray_angle, i);
		i++;
	}
	i = 0;
	while (i < map->doors_count)
	{
		map->doors[i].min_distance = two_points_dis(map->player.x, \
		map->player.y, map->doors[i].centre_x, map->doors[i].centre_y);
		if (map->doors[i].min_distance > BLOCK_SIZE * 2)
			map->map[map->doors[i].posit_y][map->doors[i].posit_x] = 'D';
		i++;
	}
}

void	draw_map(t_map *map)
{
	double	steps;
	double	new_px;
	double	new_py;

	mlx_draw_minimap(map);
	steps = map->walk * map->walk_speed;
	new_px = map->player.x + (cos(map->rotation_angle + \
	(M_PI_2 * map->move)) * steps);
	new_py = map->player.y + (sin(map->rotation_angle + \
	(M_PI_2 * map->move)) * steps);
	if (wall_colision(map, new_px, new_py))
	{
		map->player.x = new_px;
		map->player.y = new_py;
	}
	map->rotation_angle += map->turn * map->rotation_speed;
	map->rotation_angle = fix_angle(map->rotation_angle);
	draw_map_utils(map);
}
