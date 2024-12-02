/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_vert_intersec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:12:58 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	find_first_intersec_and_steps(t_map *map, double ray_angle)
{
	map->vert.xintersec = floor(map->player.x / BLOCK_SIZE) * BLOCK_SIZE;
	if (map->facing.facing_right)
		map->vert.xintersec += BLOCK_SIZE;
	map->vert.yintersec = map->player.y + \
	((map->vert.xintersec - map->player.x) * tan(ray_angle));
	map->vert.xsteps = BLOCK_SIZE;
	if (map->facing.facing_left)
		map->vert.xsteps *= -1;
	map->vert.ysteps = BLOCK_SIZE * tan(ray_angle);
	if (map->facing.facing_up && map->vert.ysteps > 0)
		map->vert.ysteps *= -1;
	if (map->facing.facing_down && map->vert.ysteps < 0)
		map->vert.ysteps *= -1;
	map->vert.xintersec_next = map->vert.xintersec;
	map->vert.yintersec_next = map->vert.yintersec;
}

static void	increment_steps(t_map *map)
{
	map->vert.xintersec_next += map->vert.xsteps;
	map->vert.yintersec_next += map->vert.ysteps;
}

static void	get_wall_intersec(t_map *map)
{
	map->vert.is_hit_vert = 1;
	map->vert.x_vert = map->vert.xintersec_next;
	map->vert.y_vert = map->vert.yintersec_next;
	map->vert.vx = map->vert.x_check;
	map->vert.vy = map->vert.y_check;
}

void	vert_intersec(t_map *map, double ray_angle)
{
	find_first_intersec_and_steps(map, ray_angle);
	map->vert.is_hit_vert = 0;
	while ((map->vert.xintersec_next >= 0) \
	&& (map->vert.xintersec_next < ft_strlen(map->map[0]) * BLOCK_SIZE) \
	&& (map->vert.yintersec_next >= 0) && \
	(map->vert.yintersec_next < map->line_count * BLOCK_SIZE))
	{
		map->vert.x_check = map->vert.xintersec_next;
		map->vert.y_check = map->vert.yintersec_next;
		if (map->facing.facing_left)
			map->vert.x_check--;
		if (is_wall(map, map->vert.x_check, map->vert.y_check) == 1 \
		|| is_wall(map, map->vert.x_check, map->vert.y_check) == 2 \
		|| is_wall(map, map->vert.x_check, map->vert.y_check) == 4)
		{
			get_wall_intersec(map);
			break ;
		}
		else
			increment_steps(map);
	}
}
