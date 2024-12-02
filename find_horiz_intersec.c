/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horiz_intersec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:02:28 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	find_first_intersec_and_steps(t_map *map, double ray_angle)
{
	map->horiz.yintersec = floor(map->player.y / BLOCK_SIZE) * BLOCK_SIZE;
	if (map->facing.facing_down)
		map->horiz.yintersec += BLOCK_SIZE;
	map->horiz.xintersec = map->player.x + \
	((map->horiz.yintersec - map->player.y) / tan(ray_angle));
	map->horiz.ysteps = BLOCK_SIZE;
	if (map->facing.facing_up)
		map->horiz.ysteps *= -1;
	map->horiz.xsteps = BLOCK_SIZE / tan(ray_angle);
	if (map->facing.facing_left && map->horiz.xsteps > 0)
		map->horiz.xsteps *= -1;
	if (map->facing.facing_right && map->horiz.xsteps < 0)
		map->horiz.xsteps *= -1;
	map->horiz.xintersec_next = map->horiz.xintersec;
	map->horiz.yintersec_next = map->horiz.yintersec;
}

static void	increment_steps(t_map *map)
{
	map->horiz.xintersec_next += map->horiz.xsteps;
	map->horiz.yintersec_next += map->horiz.ysteps;
}

static void	get_wall_intersec(t_map *map)
{
	map->horiz.is_hit_horiz = 1;
	map->horiz.x_horiz = map->horiz.xintersec_next;
	map->horiz.y_horiz = map->horiz.yintersec_next;
	map->horiz.hx = map->horiz.x_check;
	map->horiz.hy = map->horiz.y_check;
}

void	horiz_intersec(t_map *map, double ray_angle)
{
	find_first_intersec_and_steps(map, ray_angle);
	map->horiz.is_hit_horiz = 0;
	while ((map->horiz.xintersec_next >= 0) \
	&& (map->horiz.xintersec_next < ft_strlen(map->map[0]) * BLOCK_SIZE) \
	&& (map->horiz.yintersec_next >= 0) \
	&& (map->horiz.yintersec_next < map->line_count * BLOCK_SIZE))
	{
		map->horiz.x_check = map->horiz.xintersec_next;
		map->horiz.y_check = map->horiz.yintersec_next;
		if (map->facing.facing_up)
			map->horiz.y_check--;
		if (is_wall(map, map->horiz.x_check, map->horiz.y_check) == 1 \
			|| is_wall(map, map->horiz.x_check, map->horiz.y_check) == 2 \
			|| is_wall(map, map->horiz.x_check, map->horiz.y_check) == 4)
		{
			get_wall_intersec(map);
			break ;
		}
		else
			increment_steps(map);
	}
}
