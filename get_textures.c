/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:03:45 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_north_tex(t_map *map, t_texture *tmp)
{
	map->texture_north.img = mlx_xpm_file_to_image(map->mlx_ptr, tmp->path, \
	&map->texture_north.x, &map->texture_north.y);
	if (map->texture_north.img == NULL)
		return (0);
	map->texture_north.addr = mlx_get_data_addr(map->texture_north.img, \
	&map->texture_north.bits_per_pixel, &map->texture_north.line_length, \
	&map->texture_north.endian);
	if (map->texture_north.addr == NULL)
		return (0);
	return (1);
}

int	get_south_tex(t_map *map, t_texture *tmp)
{
	map->texture_south.img = mlx_xpm_file_to_image(map->mlx_ptr, tmp->path, \
	&map->texture_south.x, &map->texture_south.y);
	if (map->texture_south.img == NULL)
		return (0);
	map->texture_south.addr = mlx_get_data_addr(map->texture_south.img, \
	&map->texture_south.bits_per_pixel, &map->texture_south.line_length, \
	&map->texture_south.endian);
	if (map->texture_south.addr == NULL)
		return (0);
	return (1);
}

int	get_west_tex(t_map *map, t_texture *tmp)
{
	map->texture_west.img = mlx_xpm_file_to_image(map->mlx_ptr, tmp->path, \
	&map->texture_west.x, &map->texture_west.y);
	if (map->texture_west.img == NULL)
		return (0);
	map->texture_west.addr = mlx_get_data_addr(map->texture_west.img, \
	&map->texture_west.bits_per_pixel, &map->texture_west.line_length, \
	&map->texture_west.endian);
	if (map->texture_west.addr == NULL)
		return (0);
	return (1);
}

int	get_east_tex(t_map *map, t_texture *tmp)
{
	map->texture_east.img = mlx_xpm_file_to_image(map->mlx_ptr, tmp->path, \
	&map->texture_east.x, &map->texture_east.y);
	if (map->texture_east.img == NULL)
		return (0);
	map->texture_east.addr = mlx_get_data_addr(map->texture_east.img, \
	&map->texture_east.bits_per_pixel, &map->texture_east.line_length, \
	&map->texture_east.endian);
	if (map->texture_east.addr == NULL)
		return (0);
	return (1);
}

int	get_textures(t_map *map)
{
	t_texture	*tmp;

	tmp = map->texture;
	while (tmp)
	{
		if (ft_strncmp(tmp->direction, "NO", 2) == 0)
			if (!get_north_tex(map, tmp))
				return (0);
		if (ft_strncmp(tmp->direction, "SO", 2) == 0)
			if (!get_south_tex(map, tmp))
				return (0);
		if (ft_strncmp(tmp->direction, "WE", 2) == 0)
			if (!get_west_tex(map, tmp))
				return (0);
		if (ft_strncmp(tmp->direction, "EA", 2) == 0)
			if (!get_east_tex(map, tmp))
				return (0);
		tmp = tmp->next;
	}
	return (1);
}
