/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:26 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/24 12:31:54 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	face_directions(t_map *map, double ray_angle)
{
	map->facing.facing_down = 0;
	map->facing.facing_up = 0;
	map->facing.facing_right = 0;
	map->facing.facing_left = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		map->facing.facing_down = 1;
	if (!map->facing.facing_down)
		map->facing.facing_up = 1;
	if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
		map->facing.facing_right = 1;
	if (!map->facing.facing_right)
		map->facing.facing_left = 1;
}

void	find_wall_height(t_map *map, double ray_angle, double ray_dis)
{
	double	corr_distance;

	corr_distance = ray_dis * cos(ray_angle - map->rotation_angle);
	map->wall_height = (BLOCK_SIZE / corr_distance) * map->dist_proj_plane;
}

void	draw_horiz_tex(t_map *map, double ray_angle, int nb_ray)
{
	int	i;

	map->ray[nb_ray].distance = map->horiz.horiz_distance;
	find_wall_height(map, ray_angle, map->ray[nb_ray].distance);
	if (map->facing.facing_down
		&& is_wall(map, map->horiz.x_check, map->horiz.y_check) != 5)
		draw_projected_wall(map, nb_ray, map->texture_south);
	else if (is_wall(map, map->horiz.x_check, map->horiz.y_check) != 5)
		draw_projected_wall(map, nb_ray, map->texture_north);
	i = -1;
	while (++i < map->doors_count)
	{
		if (is_wall(map, map->horiz.x_check, map->horiz.y_check) == 4
			&& (int)floor(map->horiz.x_check / BLOCK_SIZE) == \
			map->doors[i].posit_x
			&& (int)floor(map->horiz.y_check / BLOCK_SIZE) == \
			map->doors[i].posit_y)
		{
			map->doors[i].visible = 1;
			draw_projected_wall(map, nb_ray, map->door_tex_1);
		}
		else
			map->doors[i].visible = 0;
	}
}

void	draw_vert_tex(t_map *map, double ray_angle, int nb_ray)
{
	int	i;

	map->ray[nb_ray].distance = map->vert.vert_distance;
	find_wall_height(map, ray_angle, map->ray[nb_ray].distance);
	if (map->facing.facing_right
		&& is_wall(map, map->vert.x_check, map->vert.y_check) != 5)
		draw_projected_wall(map, nb_ray, map->texture_east);
	else if (is_wall(map, map->vert.x_check, map->vert.y_check) != 5)
		draw_projected_wall(map, nb_ray, map->texture_west);
	i = -1;
	while (++i < map->doors_count)
	{
		if (is_wall(map, map->vert.x_check, map->vert.y_check) == 4
			&& (int)floor(map->vert.x_check / BLOCK_SIZE) == \
			map->doors[i].posit_x
			&& (int)floor(map->vert.y_check / BLOCK_SIZE) == \
			map->doors[i].posit_y)
		{
			map->doors[i].visible = 1;
			draw_projected_wall(map, nb_ray, map->door_tex_1);
		}
		else
			map->doors[i].visible = 0;
	}
}

void	render_walls(t_map *map, double ray_angle, int nb_ray)
{
	face_directions(map, ray_angle);
	horiz_intersec(map, ray_angle);
	vert_intersec(map, ray_angle);
	if (map->horiz.is_hit_horiz)
		map->horiz.horiz_distance = two_points_dis(map->player.x, \
		map->player.y, map->horiz.x_horiz, map->horiz.y_horiz);
	else
		map->horiz.horiz_distance = INT_MAX;
	if (map->vert.is_hit_vert)
		map->vert.vert_distance = two_points_dis(map->player.x, \
		map->player.y, map->vert.x_vert, map->vert.y_vert);
	else
		map->vert.vert_distance = INT_MAX;
	if (map->horiz.horiz_distance < map->vert.vert_distance)
		draw_horiz_tex(map, ray_angle, nb_ray);
	else
		draw_vert_tex(map, ray_angle, nb_ray);
}
