/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:05:08 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 18:51:57 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	door_key(t_map *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->doors_count)
	{
		if (mlx->map[mlx->doors[i].posit_y] \
		[mlx->doors[i].posit_x] == 'D' && \
		mlx->doors[i].min_distance < BLOCK_SIZE + 10 && \
		mlx->doors[i].visible)
		{
			mlx->map[mlx->doors[i].posit_y] \
			[mlx->doors[i].posit_x] = 'A';
		}
		i++;
	}
}

void	walk_keys(int key, t_map *mlx)
{
	if (key == 13)
		mlx->walk = UP;
	if (key == 1)
		mlx->walk = DOWN;
	if (key == 0)
	{
		mlx->move = RIGHT;
		mlx->walk = UP;
	}
	if (key == 2)
	{
		mlx->move = LEFT;
		mlx->walk = UP;
	}
}

int	key_hook(int key, void *mlx)
{
	if (key == 53)
		ft_close((t_map *)mlx);
	if (key == 46)
		((t_map *)mlx)->show_minimap = !((t_map *)mlx)->show_minimap;
	if (key == 124)
		((t_map *)mlx)->turn = LEFT;
	if (key == 123)
		((t_map *)mlx)->turn = RIGHT;
	if (key == 126)
		((t_map *)mlx)->z_pixel += 20;
	if (key == 125)
		((t_map *)mlx)->z_pixel -= 20;
	walk_keys(key, (t_map *)mlx);
	if (key == 49)
		door_key((t_map *)mlx);
	return (0);
}

int	keyup_hook(int key, void *mlx)
{
	if (key == 124 || key == 123)
		((t_map *)mlx)->turn = 0;
	else if (key == 13 || key == 1)
		((t_map *)mlx)->walk = 0;
	else if (key == 0 || key == 2)
	{
		((t_map *)mlx)->move = 0;
		((t_map *)mlx)->walk = 0;
	}
	return (0);
}

int	mouse_hook(int x, int y, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		if (x > WIDTH / 3 * 2)
			map->rotation_angle = fix_angle(map->rotation_angle + \
			map->rotation_speed);
		else if (x < WIDTH / 3)
			map->rotation_angle = fix_angle(map->rotation_angle - \
			map->rotation_speed);
		if (y > HEIGHT / 3 * 2)
			map->z_pixel -= 10;
		else if (y < HEIGHT / 3)
			map->z_pixel += 10;
	}
	return (1);
}
