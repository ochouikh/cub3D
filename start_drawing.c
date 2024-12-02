/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:04 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/25 09:16:10 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	destroy_textures(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->texture_north.img);
	mlx_destroy_image(map->mlx_ptr, map->texture_south.img);
	mlx_destroy_image(map->mlx_ptr, map->texture_west.img);
	mlx_destroy_image(map->mlx_ptr, map->texture_east.img);
	mlx_destroy_image(map->mlx_ptr, map->door_tex_1.img);
}

int	render(t_map *map)
{
	mlx_clear_window(map->mlx_ptr, map->mlx_win);
	draw_map(map);
	if (!animate_ennemi(map))
		return (0);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img.img, 0, 0);
	if (map->show_minimap)
		mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, \
		map->mlx_minimap.img, 5, 5);
	return (1);
}

int	launch_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		return (0);
	map->mlx_win = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "cube3D!");
	if (!map->mlx_win)
		return (0);
	return (1);
}

int	create_images(t_map *map)
{
	map->mlx_img.img = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	if (!map->mlx_img.img)
		return (0);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img, \
	&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length, \
	&map->mlx_img.endian);
	if (!map->mlx_img.addr)
		return (0);
	map->mlx_minimap.img = mlx_new_image(map->mlx_ptr, MINIMAP_WIDTH, \
	MINIMAP_HEIGHT);
	if (!map->mlx_minimap.img)
		return (0);
	map->mlx_minimap.addr = mlx_get_data_addr(map->mlx_minimap.img, \
	&map->mlx_minimap.bits_per_pixel, &map->mlx_minimap.line_length, \
	&map->mlx_minimap.endian);
	if (!map->mlx_minimap.addr)
		return (0);
	return (1);
}

int	start_drawing(t_map *map)
{
	if (!launch_window(map))
		return (0);
	if (!create_images(map))
		return (0);
	if (!get_sprites_tex(map) || !get_textures(map))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Couldn't load textures\n", 2);
		return (0);
	}
	mlx_hook(map->mlx_win, 2, 0, &key_hook, map);
	mlx_hook(map->mlx_win, 3, 0, &keyup_hook, map);
	mlx_hook(map->mlx_win, 17, 0, &ft_close, map);
	mlx_hook(map->mlx_win, 6, 0, &mouse_hook, map);
	mlx_loop_hook(map->mlx_ptr, &render, map);
	mlx_loop(map->mlx_ptr);
	return (1);
}
