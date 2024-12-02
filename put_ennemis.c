/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ennemis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 09:35:42 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/24 14:40:08 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	find_ennemi_tex_values(t_map *map, t_sprite visible_ennemi, \
t_sprite_utils *utils)
{
	utils->ennemi_height = (BLOCK_SIZE / visible_ennemi.distance) * \
	map->dist_proj_plane;
	utils->ennemi_width = utils->ennemi_height;
	utils->y_top_ennemi = (HEIGHT / 2) - (utils->ennemi_height / 2) + \
	map->z_pixel;
	if (utils->y_top_ennemi < 0)
		utils->y_top_ennemi = 0;
	utils->y_bottom_ennemi = (HEIGHT / 2) + (utils->ennemi_height / 2) + \
	map->z_pixel;
	if (utils->y_bottom_ennemi > HEIGHT)
		utils->y_bottom_ennemi = HEIGHT;
	utils->ennemi_angle = atan2(visible_ennemi.centre_position.y - \
	map->player.y, visible_ennemi.centre_position.x - map->player.x) - \
	map->rotation_angle;
	utils->x_ennemi = tan(utils->ennemi_angle) * map->dist_proj_plane;
	utils->x_left_ennemi = (WIDTH / 2) + utils->x_ennemi - \
	(utils->ennemi_width / 2);
	utils->x_right_ennemi = utils->x_left_ennemi + utils->ennemi_width;
}

void	put_pixel_texture(t_map *map, t_sprite visible_ennemi, \
t_sprite_utils utils, t_texture_put ennemi_tex)
{
	char	*dst;

	if (utils.x > 0 && utils.x < WIDTH && utils.y > 0 && utils.y < HEIGHT)
	{
		utils.distance_from_top_y = utils.y + (utils.ennemi_height / 2) - \
		(HEIGHT / 2) - map->z_pixel;
		utils.y_offset = utils.distance_from_top_y * \
		((double)ennemi_tex.y / utils.ennemi_height);
		dst = ennemi_tex.addr + (utils.y_offset * ennemi_tex.line_length + \
		utils.x_offset * (ennemi_tex.bits_per_pixel / 8));
		if ((visible_ennemi.distance < map->ray[utils.x].distance)
			&& *(unsigned int*)dst != 0x00FF00FF
			&& *(unsigned int*)dst != 0x0000FF00)
			my_mlx_pixel_put(&map->mlx_img, utils.x, utils.y, \
			*(unsigned int *)dst);
	}
}

void	put_ennemi(t_map *map, t_texture_put ennemi_tex, \
t_sprite visible_ennemi)
{
	t_sprite_utils	utils;

	find_ennemi_tex_values(map, visible_ennemi, &utils);
	utils.x = utils.x_left_ennemi;
	while (utils.x < utils.x_right_ennemi)
	{
		utils.pixel_width = (ennemi_tex.x / utils.ennemi_width);
		utils.x_offset = (utils.x - utils.x_left_ennemi) * utils.pixel_width;
		utils.y = utils.y_top_ennemi;
		while (utils.y < utils.y_bottom_ennemi)
		{
			put_pixel_texture(map, visible_ennemi, utils, ennemi_tex);
			utils.y++;
		}
		utils.x++;
	}
}
