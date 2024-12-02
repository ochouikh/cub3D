/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_visible_ennemi.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:00:45 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/24 14:13:22 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	sort_visible_ennemi(t_sprite *visible_ennemi, int lenght)
{
	t_sprite	tmp;
	int			i;
	int			j;

	i = 0;
	while (i < lenght - 1)
	{
		j = i + 1;
		while (j < lenght)
		{
			if (visible_ennemi[i].distance < visible_ennemi[j].distance)
			{
				tmp = visible_ennemi[i];
				visible_ennemi[i] = visible_ennemi[j];
				visible_ennemi[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	search_and_count(t_map *map, t_sprite *ennemi)
{
	int	i;

	map->visible_ennemis = 0;
	i = 0;
	while (i < map->ennemi_count)
	{
		map->ennemi[i].angle = map->rotation_angle - \
		atan2(ennemi[i].centre_position.y - map->player.y, \
		ennemi[i].centre_position.x - map->player.x);
		if (map->ennemi[i].angle > M_PI)
			map->ennemi[i].angle -= 2 * M_PI;
		if (map->ennemi[i].angle < M_PI * -1)
			map->ennemi[i].angle += 2 * M_PI;
		map->ennemi[i].angle = fabs(map->ennemi[i].angle);
		map->ennemi[i].distance = two_points_dis(map->player.x, map->player.y, \
		ennemi[i].centre_position.x, ennemi[i].centre_position.y);
		if (map->ennemi[i].angle < (map->fov / 2) + EPSILON)
			map->visible_ennemis++;
		i++;
	}
}

t_sprite	*search_visible_ennemi(t_map *map, t_sprite *ennemi)
{
	t_sprite	*visible_ennemi;
	int			i;
	int			j;

	search_and_count(map, ennemi);
	visible_ennemi = malloc(map->visible_ennemis * sizeof(t_sprite));
	if (!visible_ennemi)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < map->ennemi_count)
		if ((map->ennemi[i].angle < (map->fov / 2) + EPSILON))
			visible_ennemi[++j] = ennemi[i];
	sort_visible_ennemi(visible_ennemi, map->visible_ennemis);
	return (visible_ennemi);
}
