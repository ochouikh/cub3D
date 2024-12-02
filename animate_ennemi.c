/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_ennemi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 10:50:44 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/22 16:46:27 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	animation(t_map *map, t_sprite visible_ennemi)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = (INSECT_FRAMES / 11);
	b = (DRAGON_FRAMES / 6);
	c = (MONSTER_FRAMES / 10);
	d = (MOON_FRAMES / 11);
	if (visible_ennemi.type == INSECT)
		animate_insect(map, visible_ennemi, a);
	else if (visible_ennemi.type == DRAGON)
		animate_dragon(map, visible_ennemi, b);
	else if (visible_ennemi.type == MONSTER)
		animate_monster(map, visible_ennemi, c);
	else if (visible_ennemi.type == MOON)
		animate_moon(map, visible_ennemi, d);
}

int	animate_ennemi(t_map *map)
{
	t_sprite	*visible_ennemi;
	int			i;

	visible_ennemi = search_visible_ennemi(map, map->ennemi);
	if (!visible_ennemi)
		return (0);
	i = -1;
	while (++i < map->visible_ennemis)
		animation(map, visible_ennemi[i]);
	if (map->insect_frame >= INSECT_FRAMES)
		map->insect_frame = 0;
	if (map->dragon_frame >= DRAGON_FRAMES)
		map->dragon_frame = 0;
	if (map->monster_frame >= MONSTER_FRAMES)
		map->monster_frame = 0;
	if (map->moon_frame >= MOON_FRAMES)
		map->moon_frame = 0;
	free(visible_ennemi);
	return (1);
}
