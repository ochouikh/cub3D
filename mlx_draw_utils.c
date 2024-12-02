/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:14:30 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/22 13:28:58 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	mlx_draw_line(double px, double py, t_map *map)
{
	int	len;

	len = 10;
	while (len > 0)
	{
		my_mlx_pixel_put(&map->mlx_minimap, px + (cos(map->rotation_angle) \
		* len), py + (sin(map->rotation_angle) * len), 0x00FF0000);
		len--;
	}
}

void	mlx_draw_circle(int px, int py, int color, t_map *map)
{
	double	angle;
	int		i;

	angle = 0;
	while (angle < 2 * M_PI)
	{
		i = 0;
		while (i < 3)
		{
			my_mlx_pixel_put(&map->mlx_minimap, px + (cos(angle) * i), \
			py + (sin(angle) * i), color);
			i++;
		}
		angle += 0.001;
	}
}

void	cilling_floor(t_map *map, int nb_ray, double wall_top, \
double wall_bottom)
{
	int		i;

	i = 0;
	while (i < wall_top)
	{
		my_mlx_pixel_put(&map->mlx_img, nb_ray, i, get_rgb(map, "C"));
		i++;
	}
	i = wall_bottom;
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(&map->mlx_img, nb_ray, i, get_rgb(map, "F"));
		i++;
	}
}
