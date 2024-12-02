/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_tex_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:14:51 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_img_monster(t_map *map)
{
	map->monster_tex_1.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e1.xpm", &map->monster_tex_1.x, \
	&map->monster_tex_1.y);
	map->monster_tex_2.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e2.xpm", &map->monster_tex_2.x, \
	&map->monster_tex_2.y);
	map->monster_tex_3.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e3.xpm", &map->monster_tex_3.x, \
	&map->monster_tex_3.y);
	map->monster_tex_4.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e4.xpm", &map->monster_tex_4.x, \
	&map->monster_tex_4.y);
	map->monster_tex_5.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e5.xpm", &map->monster_tex_5.x, \
	&map->monster_tex_5.y);
	map->monster_tex_6.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/monster/e6.xpm", &map->monster_tex_6.x, \
	&map->monster_tex_6.y);
	if (!map->monster_tex_1.img || !map->monster_tex_2.img
		|| !map->monster_tex_3.img || !map->monster_tex_4.img
		|| !map->monster_tex_5.img || !map->monster_tex_6.img)
		return (0);
	return (1);
}

int	get_monster_tex(t_map *map)
{
	if (!get_img_monster(map))
		return (0);
	map->monster_tex_1.addr = mlx_get_data_addr(map->monster_tex_1.img, \
	&map->monster_tex_1.bits_per_pixel, &map->monster_tex_1.line_length, \
	&map->monster_tex_1.endian);
	map->monster_tex_2.addr = mlx_get_data_addr(map->monster_tex_2.img, \
	&map->monster_tex_2.bits_per_pixel, &map->monster_tex_2.line_length, \
	&map->monster_tex_2.endian);
	map->monster_tex_3.addr = mlx_get_data_addr(map->monster_tex_3.img, \
	&map->monster_tex_3.bits_per_pixel, &map->monster_tex_3.line_length, \
	&map->monster_tex_3.endian);
	map->monster_tex_4.addr = mlx_get_data_addr(map->monster_tex_4.img, \
	&map->monster_tex_4.bits_per_pixel, &map->monster_tex_4.line_length, \
	&map->monster_tex_4.endian);
	map->monster_tex_5.addr = mlx_get_data_addr(map->monster_tex_5.img, \
	&map->monster_tex_5.bits_per_pixel, &map->monster_tex_5.line_length, \
	&map->monster_tex_5.endian);
	map->monster_tex_6.addr = mlx_get_data_addr(map->monster_tex_6.img, \
	&map->monster_tex_6.bits_per_pixel, &map->monster_tex_6.line_length, \
	&map->monster_tex_6.endian);
	if (!map->monster_tex_1.addr || !map->monster_tex_2.addr
		|| !map->monster_tex_3.addr || !map->monster_tex_4.addr
		|| !map->monster_tex_5.addr || !map->monster_tex_6.addr)
		return (0);
	return (1);
}

int	get_imag_dragon(t_map *map)
{
	map->dragon_tex_1.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e1.xpm", &map->dragon_tex_1.x, \
	&map->dragon_tex_1.y);
	map->dragon_tex_2.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e2.xpm", &map->dragon_tex_2.x, \
	&map->dragon_tex_2.y);
	map->dragon_tex_3.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e3.xpm", &map->dragon_tex_3.x, \
	&map->dragon_tex_3.y);
	map->dragon_tex_4.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e4.xpm", &map->dragon_tex_4.x, \
	&map->dragon_tex_4.y);
	map->dragon_tex_5.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e5.xpm", &map->dragon_tex_5.x, \
	&map->dragon_tex_5.y);
	map->dragon_tex_6.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/dragon/e6.xpm", &map->dragon_tex_6.x, \
	&map->dragon_tex_6.y);
	if (!map->dragon_tex_1.img || !map->dragon_tex_2.img
		|| !map->dragon_tex_3.img || !map->dragon_tex_4.img
		|| !map->dragon_tex_5.img || !map->dragon_tex_6.img)
		return (0);
	return (1);
}

int	get_dragon_tex(t_map *map)
{
	if (!get_imag_dragon(map))
		return (0);
	map->dragon_tex_1.addr = mlx_get_data_addr(map->dragon_tex_1.img, \
	&map->dragon_tex_1.bits_per_pixel, &map->dragon_tex_1.line_length, \
	&map->dragon_tex_1.endian);
	map->dragon_tex_2.addr = mlx_get_data_addr(map->dragon_tex_2.img, \
	&map->dragon_tex_2.bits_per_pixel, &map->dragon_tex_2.line_length, \
	&map->dragon_tex_2.endian);
	map->dragon_tex_3.addr = mlx_get_data_addr(map->dragon_tex_3.img, \
	&map->dragon_tex_3.bits_per_pixel, &map->dragon_tex_3.line_length, \
	&map->dragon_tex_3.endian);
	map->dragon_tex_4.addr = mlx_get_data_addr(map->dragon_tex_4.img, \
	&map->dragon_tex_4.bits_per_pixel, &map->dragon_tex_4.line_length, \
	&map->dragon_tex_4.endian);
	map->dragon_tex_5.addr = mlx_get_data_addr(map->dragon_tex_5.img, \
	&map->dragon_tex_5.bits_per_pixel, &map->dragon_tex_5.line_length, \
	&map->dragon_tex_5.endian);
	map->dragon_tex_6.addr = mlx_get_data_addr(map->dragon_tex_6.img, \
	&map->dragon_tex_6.bits_per_pixel, &map->dragon_tex_6.line_length, \
	&map->dragon_tex_6.endian);
	if (!map->dragon_tex_1.addr || !map->dragon_tex_2.addr
		|| !map->dragon_tex_3.addr || !map->dragon_tex_4.addr
		|| !map->dragon_tex_5.addr || !map->dragon_tex_6.addr)
		return (0);
	return (1);
}

int	get_door_tex(t_map *map)
{
	map->door_tex_1.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./textures/door1.xpm", &map->door_tex_1.x, &map->door_tex_1.y);
	if (!map->door_tex_1.img)
		return (0);
	map->door_tex_1.addr = mlx_get_data_addr(map->door_tex_1.img, \
	&map->door_tex_1.bits_per_pixel, \
	&map->door_tex_1.line_length, &map->door_tex_1.endian);
	if (!map->door_tex_1.addr)
		return (0);
	return (1);
}
