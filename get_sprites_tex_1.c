/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_tex_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:35:45 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_image_insect_1(t_map *map)
{
	map->insect_tex_1.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e1.xpm", &map->insect_tex_1.x, \
	&map->insect_tex_1.y);
	map->insect_tex_2.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e2.xpm", &map->insect_tex_2.x, \
	&map->insect_tex_2.y);
	map->insect_tex_3.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e3.xpm", &map->insect_tex_3.x, \
	&map->insect_tex_3.y);
	map->insect_tex_4.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e4.xpm", &map->insect_tex_4.x, \
	&map->insect_tex_4.y);
	map->insect_tex_5.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e5.xpm", &map->insect_tex_5.x, \
	&map->insect_tex_5.y);
	map->insect_tex_6.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e6.xpm", &map->insect_tex_6.x, \
	&map->insect_tex_6.y);
	if (!map->insect_tex_1.img || !map->insect_tex_2.img
		|| !map->insect_tex_3.img || !map->insect_tex_4.img
		|| !map->insect_tex_5.img || !map->insect_tex_6.img)
		return (0);
	return (1);
}

int	get_image_insect_2(t_map *map)
{
	if (!get_image_insect_1(map))
		return (0);
	map->insect_tex_7.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e7.xpm", &map->insect_tex_7.x, \
	&map->insect_tex_7.y);
	map->insect_tex_8.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e8.xpm", &map->insect_tex_8.x, \
	&map->insect_tex_8.y);
	map->insect_tex_9.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e9.xpm", &map->insect_tex_9.x, \
	&map->insect_tex_9.y);
	map->insect_tex_10.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e10.xpm", &map->insect_tex_10.x, \
	&map->insect_tex_10.y);
	map->insect_tex_11.img = mlx_xpm_file_to_image(map->mlx_ptr, \
	"./sprites_textures/insect/e11.xpm", &map->insect_tex_11.x, \
	&map->insect_tex_11.y);
	if (!map->insect_tex_7.img || !map->insect_tex_8.img
		|| !map->insect_tex_9.img || !map->insect_tex_10.img
		|| !map->insect_tex_11.img)
		return (0);
	return (1);
}

int	get_insect_tex_addr_1(t_map *map)
{
	map->insect_tex_1.addr = mlx_get_data_addr(map->insect_tex_1.img, \
	&map->insect_tex_1.bits_per_pixel, &map->insect_tex_1.line_length, \
	&map->insect_tex_1.endian);
	map->insect_tex_2.addr = mlx_get_data_addr(map->insect_tex_2.img, \
	&map->insect_tex_2.bits_per_pixel, &map->insect_tex_2.line_length, \
	&map->insect_tex_2.endian);
	map->insect_tex_3.addr = mlx_get_data_addr(map->insect_tex_3.img, \
	&map->insect_tex_3.bits_per_pixel, &map->insect_tex_3.line_length, \
	&map->insect_tex_3.endian);
	map->insect_tex_4.addr = mlx_get_data_addr(map->insect_tex_4.img, \
	&map->insect_tex_4.bits_per_pixel, &map->insect_tex_4.line_length, \
	&map->insect_tex_4.endian);
	map->insect_tex_5.addr = mlx_get_data_addr(map->insect_tex_5.img, \
	&map->insect_tex_5.bits_per_pixel, &map->insect_tex_5.line_length, \
	&map->insect_tex_5.endian);
	if (!map->insect_tex_1.addr || !map->insect_tex_2.addr
		|| !map->insect_tex_3.addr || !map->insect_tex_4.addr
		|| !map->insect_tex_5.addr)
		return (0);
	return (1);
}

int	get_insect_tex_addr(t_map *map)
{
	if (!get_insect_tex_addr_1(map))
		return (0);
	map->insect_tex_6.addr = mlx_get_data_addr(map->insect_tex_6.img, \
	&map->insect_tex_6.bits_per_pixel, &map->insect_tex_6.line_length, \
	&map->insect_tex_6.endian);
	map->insect_tex_7.addr = mlx_get_data_addr(map->insect_tex_7.img, \
	&map->insect_tex_7.bits_per_pixel, &map->insect_tex_7.line_length, \
	&map->insect_tex_7.endian);
	map->insect_tex_8.addr = mlx_get_data_addr(map->insect_tex_8.img, \
	&map->insect_tex_8.bits_per_pixel, &map->insect_tex_8.line_length, \
	&map->insect_tex_8.endian);
	map->insect_tex_9.addr = mlx_get_data_addr(map->insect_tex_9.img, \
	&map->insect_tex_9.bits_per_pixel, &map->insect_tex_9.line_length, \
	&map->insect_tex_9.endian);
	map->insect_tex_10.addr = mlx_get_data_addr(map->insect_tex_10.img, \
	&map->insect_tex_10.bits_per_pixel, &map->insect_tex_10.line_length, \
	&map->insect_tex_10.endian);
	map->insect_tex_11.addr = mlx_get_data_addr(map->insect_tex_11.img, \
	&map->insect_tex_11.bits_per_pixel, &map->insect_tex_11.line_length, \
	&map->insect_tex_11.endian);
	if (!map->insect_tex_6.addr || !map->insect_tex_7.addr
		|| !map->insect_tex_8.addr || !map->insect_tex_9.addr
		|| !map->insect_tex_10.addr || !map->insect_tex_11.addr)
		return (0);
	return (1);
}

int	get_insect_tex(t_map *map)
{
	if (!get_image_insect_2(map))
		return (0);
	if (!get_insect_tex_addr(map))
		return (0);
	return (1);
}
