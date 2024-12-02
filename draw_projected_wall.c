/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_projected_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:41:14 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:45:16 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

unsigned int	get_pixel_color(t_texture_put *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	get_offset_x_y(t_map *map, int texture_width)
{
	if (map->horiz.horiz_distance < map->vert.vert_distance \
	&& map->horiz.is_hit_horiz)
		map->texture_offset_x = fmod(map->horiz.hx, BLOCK_SIZE) \
		* ((double)texture_width / BLOCK_SIZE);
	if (map->horiz.horiz_distance > map->vert.vert_distance \
	&& map->vert.is_hit_vert)
		map->texture_offset_x = fmod(map->vert.vy, BLOCK_SIZE) \
		* ((double)texture_width / BLOCK_SIZE);
}

void	wall_top_bottom(t_map *map, double *wall_top, double *wall_bottom)
{
	if (map->z_pixel < -HEIGHT / 2)
		map->z_pixel = -HEIGHT / 2;
	if (map->z_pixel > HEIGHT / 2)
		map->z_pixel = HEIGHT / 2;
	*wall_top = (HEIGHT) / 2 - (map->wall_height / 2) + map->z_pixel;
	if (*wall_top < 0)
		*wall_top = 0;
	*wall_bottom = (HEIGHT) / 2 + (map->wall_height / 2) + map->z_pixel;
	if (*wall_bottom > HEIGHT)
		*wall_bottom = HEIGHT;
}

void	draw_projected_wall(t_map *map, int nb_ray, t_texture_put texture)
{
	int		texcolor;
	int		texture_width;
	double	wall_top;
	double	wall_bottom;

	texture_width = texture.y;
	wall_top_bottom(map, &wall_top, &wall_bottom);
	get_offset_x_y(map, texture_width);
	cilling_floor(map, nb_ray, wall_top, wall_bottom);
	while (wall_top < wall_bottom)
	{	
		map->texture_offset_y = wall_top - map->z_pixel + \
		(map->wall_height / 2) - (HEIGHT / 2);
		map->texture_offset_y = map->texture_offset_y * \
		texture_width / map->wall_height;
		texcolor = get_pixel_color(&texture, map->texture_offset_x, \
		map->texture_offset_y);
		my_mlx_pixel_put(&map->mlx_img, nb_ray, wall_top, texcolor);
		wall_top++;
	}
}
