/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:07:42 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/25 09:16:31 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	draw_inside_minimap(t_map *map, t_point first_pos, t_point index)
{
	if (is_wall(map, first_pos.x + index.x, first_pos.y + index.y) == 2)
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0x0000FF);
	else if (is_wall(map, first_pos.x + index.x, first_pos.y + index.y) == 1)
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0x000000);
	else if (is_wall(map, first_pos.x + index.x, first_pos.y + index.y) == 3)
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0x00FFFF);
	else if (is_wall(map, first_pos.x + index.x, first_pos.y + index.y) == 4)
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0xFF0000);
	else
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0xFFFFFF);
}

void	mlx_draw_minimap_utils(t_map *map, t_point first_pos, t_point index)
{
	if (two_points_dis((MINIMAP_WIDTH / 2), (MINIMAP_HEIGHT / 2), \
	index.x, index.y) < (MINIMAP_WIDTH / 2) - LIMIT)
		draw_inside_minimap(map, first_pos, index);
	else if (two_points_dis((MINIMAP_WIDTH / 2), \
	(MINIMAP_HEIGHT / 2), index.x, index.y) < (MINIMAP_WIDTH / 2))
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0xFF00FF);
	else
		my_mlx_pixel_put(&map->mlx_minimap, index.x, index.y, 0xFF000000);
}

void	mlx_draw_minimap(t_map *map)
{
	t_point	first_pos;
	t_point	index;

	first_pos.x = map->player.x - (MINIMAP_WIDTH / 2);
	first_pos.y = map->player.y - (MINIMAP_HEIGHT / 2);
	index.y = 0;
	while (index.y < MINIMAP_HEIGHT)
	{
		index.x = 0;
		while (index.x < MINIMAP_WIDTH)
		{
			mlx_draw_minimap_utils(map, first_pos, index);
			index.x += 0.6;
		}
		index.y += 0.6;
	}
	mlx_draw_circle(MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2, 0x00FF0000, map);
	mlx_draw_line(MINIMAP_WIDTH / 2, MINIMAP_HEIGHT / 2, map);
}

int	ft_close(t_map *map)
{
	ft_free(map->map);
	free(map->ray);
	free(map->ennemi);
	free(map->doors);
	clear_colors(map);
	clear_textures(map);
	mlx_destroy_image(map->mlx_ptr, map->mlx_img.img);
	mlx_destroy_image(map->mlx_ptr, map->mlx_minimap.img);
	mlx_destroy_window(map->mlx_ptr, map->mlx_win);
	exit(0);
}
