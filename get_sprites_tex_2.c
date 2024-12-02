/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_tex_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 08:14:22 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_moon_tex_1_8(t_map *map)
{
	map->moon_tex_1.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e1.xpm", &map->moon_tex_1.x, &map->moon_tex_1.y);
	map->moon_tex_2.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e2.xpm", &map->moon_tex_2.x, &map->moon_tex_2.y);
	map->moon_tex_3.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e3.xpm", &map->moon_tex_3.x, &map->moon_tex_3.y);
	map->moon_tex_4.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e4.xpm", &map->moon_tex_4.x, &map->moon_tex_4.y);
	map->moon_tex_5.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e5.xpm", &map->moon_tex_5.x, &map->moon_tex_5.y);
	map->moon_tex_6.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e6.xpm", &map->moon_tex_6.x, &map->moon_tex_6.y);
	map->moon_tex_7.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e7.xpm", &map->moon_tex_7.x, &map->moon_tex_7.y);
	map->moon_tex_8.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e8.xpm", &map->moon_tex_8.x, &map->moon_tex_8.y);
	if (!map->moon_tex_1.img || !map->moon_tex_2.img || !map->moon_tex_3.img
		|| !map->moon_tex_4.img || !map->moon_tex_5.img
		|| !map->moon_tex_6.img || !map->moon_tex_7.img
		|| !map->moon_tex_8.img)
		return (0);
	return (1);
}

int	get_moon_tex_9_11(t_map *map)
{
	map->moon_tex_9.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e9.xpm", &map->moon_tex_9.x, &map->moon_tex_9.y);
	map->moon_tex_10.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e10.xpm", \
	&map->moon_tex_10.x, &map->moon_tex_10.y);
	map->moon_tex_11.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/moon/e11.xpm", \
	&map->moon_tex_11.x, &map->moon_tex_11.y);
	if (!map->moon_tex_9.img || !map->moon_tex_10.img
		|| !map->moon_tex_11.img)
		return (0);
	return (1);
}

int	get_moon_tex_addr_1(t_map *map)
{
	map->moon_tex_1.addr = mlx_get_data_addr(map->moon_tex_1.img, \
	&map->moon_tex_1.bits_per_pixel, &map->moon_tex_1.line_length, \
	&map->moon_tex_1.endian);
	map->moon_tex_2.addr = mlx_get_data_addr(map->moon_tex_2.img, \
	&map->moon_tex_2.bits_per_pixel, &map->moon_tex_2.line_length, \
	&map->moon_tex_2.endian);
	map->moon_tex_3.addr = mlx_get_data_addr(map->moon_tex_3.img, \
	&map->moon_tex_3.bits_per_pixel, &map->moon_tex_3.line_length, \
	&map->moon_tex_3.endian);
	map->moon_tex_4.addr = mlx_get_data_addr(map->moon_tex_4.img, \
	&map->moon_tex_4.bits_per_pixel, &map->moon_tex_4.line_length, \
	&map->moon_tex_4.endian);
	map->moon_tex_5.addr = mlx_get_data_addr(map->moon_tex_5.img, \
	&map->moon_tex_5.bits_per_pixel, &map->moon_tex_5.line_length, \
	&map->moon_tex_5.endian);
	map->moon_tex_6.addr = mlx_get_data_addr(map->moon_tex_6.img, \
	&map->moon_tex_6.bits_per_pixel, &map->moon_tex_6.line_length, \
	&map->moon_tex_6.endian);
	if (!map->moon_tex_1.addr || !map->moon_tex_2.addr
		|| !map->moon_tex_3.addr || !map->moon_tex_4.addr
		|| !map->moon_tex_5.addr || !map->moon_tex_6.addr)
		return (0);
	return (1);
}

int	get_moon_addr_2(t_map *map)
{
	map->moon_tex_7.addr = mlx_get_data_addr(map->moon_tex_7.img, \
	&map->moon_tex_7.bits_per_pixel, &map->moon_tex_7.line_length, \
	&map->moon_tex_7.endian);
	map->moon_tex_8.addr = mlx_get_data_addr(map->moon_tex_8.img, \
	&map->moon_tex_8.bits_per_pixel, &map->moon_tex_8.line_length, \
	&map->moon_tex_8.endian);
	map->moon_tex_9.addr = mlx_get_data_addr(map->moon_tex_9.img, \
	&map->moon_tex_9.bits_per_pixel, &map->moon_tex_9.line_length, \
	&map->moon_tex_9.endian);
	map->moon_tex_10.addr = mlx_get_data_addr(map->moon_tex_10.img, \
	&map->moon_tex_10.bits_per_pixel, &map->moon_tex_10.line_length, \
	&map->moon_tex_10.endian);
	map->moon_tex_11.addr = mlx_get_data_addr(map->moon_tex_11.img, \
	&map->moon_tex_11.bits_per_pixel, &map->moon_tex_11.line_length, \
	&map->moon_tex_11.endian);
	if (!map->moon_tex_7.addr || !map->moon_tex_8.addr
		|| !map->moon_tex_9.addr || !map->moon_tex_10.addr
		|| !map->moon_tex_11.addr)
		return (0);
	return (1);
}

int	get_moon_tex(t_map *map)
{
	if (!get_moon_tex_1_8(map))
		return (0);
	if (!get_moon_tex_9_11(map))
		return (0);
	if (!get_moon_tex_addr_1(map))
		return (0);
	if (!get_moon_addr_2(map))
		return (0);
	return (1);
}
