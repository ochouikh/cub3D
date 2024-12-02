/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_ennemi_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:23:13 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 18:57:54 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	animate_insect(t_map *map, t_sprite visible_ennemi, double a)
{
	if (map->insect_frame >= 0 && map->insect_frame < a)
		put_ennemi(map, map->insect_tex_1, visible_ennemi);
	else if (map->insect_frame >= a && map->insect_frame < a * 2)
		put_ennemi(map, map->insect_tex_2, visible_ennemi);
	else if (map->insect_frame >= a * 2 && map->insect_frame < a * 3)
		put_ennemi(map, map->insect_tex_3, visible_ennemi);
	else if (map->insect_frame >= a * 3 && map->insect_frame < a * 4)
		put_ennemi(map, map->insect_tex_4, visible_ennemi);
	else if (map->insect_frame >= a * 4 && map->insect_frame < a * 5)
		put_ennemi(map, map->insect_tex_5, visible_ennemi);
	else if (map->insect_frame >= a * 5 && map->insect_frame < a * 6)
		put_ennemi(map, map->insect_tex_6, visible_ennemi);
	else if (map->insect_frame >= a * 6 && map->insect_frame < a * 7)
		put_ennemi(map, map->insect_tex_7, visible_ennemi);
	else if (map->insect_frame >= a * 7 && map->insect_frame < a * 8)
		put_ennemi(map, map->insect_tex_8, visible_ennemi);
	else if (map->insect_frame >= a * 8 && map->insect_frame < a * 9)
		put_ennemi(map, map->insect_tex_9, visible_ennemi);
	else if (map->insect_frame >= a * 9 && map->insect_frame < a * 10)
		put_ennemi(map, map->insect_tex_10, visible_ennemi);
	else if (map->insect_frame >= a * 10 && map->insect_frame < a * 11)
		put_ennemi(map, map->insect_tex_11, visible_ennemi);
	map->insect_frame++;
}

void	animate_dragon(t_map *map, t_sprite visible_ennemi, double b)
{
	if (map->dragon_frame >= 0 && map->dragon_frame < b)
		put_ennemi(map, map->dragon_tex_1, visible_ennemi);
	else if (map->dragon_frame >= b && map->dragon_frame < b * 2)
		put_ennemi(map, map->dragon_tex_2, visible_ennemi);
	else if (map->dragon_frame >= b * 2 && map->dragon_frame < b * 3)
		put_ennemi(map, map->dragon_tex_3, visible_ennemi);
	else if (map->dragon_frame >= b * 3 && map->dragon_frame < b * 4)
		put_ennemi(map, map->dragon_tex_4, visible_ennemi);
	else if (map->dragon_frame >= b * 4 && map->dragon_frame < b * 5)
		put_ennemi(map, map->dragon_tex_5, visible_ennemi);
	else if (map->dragon_frame >= b * 5 && map->dragon_frame < b * 6)
		put_ennemi(map, map->dragon_tex_6, visible_ennemi);
	map->dragon_frame++;
}

void	animate_monster(t_map *map, t_sprite visible_ennemi, double c)
{
	if (map->monster_frame >= 0 && map->monster_frame < c)
		put_ennemi(map, map->monster_tex_1, visible_ennemi);
	else if (map->monster_frame >= c && map->monster_frame < c * 2)
		put_ennemi(map, map->monster_tex_2, visible_ennemi);
	else if (map->monster_frame >= c * 2 && map->monster_frame < c * 3)
		put_ennemi(map, map->monster_tex_3, visible_ennemi);
	else if (map->monster_frame >= c * 3 && map->monster_frame < c * 4)
		put_ennemi(map, map->monster_tex_4, visible_ennemi);
	else if (map->monster_frame >= c * 4 && map->monster_frame < c * 5)
		put_ennemi(map, map->monster_tex_5, visible_ennemi);
	else if (map->monster_frame >= c * 5 && map->monster_frame < c * 6)
		put_ennemi(map, map->monster_tex_6, visible_ennemi);
	else if (map->monster_frame >= c * 6 && map->monster_frame < c * 7)
		put_ennemi(map, map->monster_tex_5, visible_ennemi);
	else if (map->monster_frame >= c * 7 && map->monster_frame < c * 8)
		put_ennemi(map, map->monster_tex_4, visible_ennemi);
	else if (map->monster_frame >= c * 8 && map->monster_frame < c * 9)
		put_ennemi(map, map->monster_tex_3, visible_ennemi);
	else if (map->monster_frame >= c * 9 && map->monster_frame < c * 10)
		put_ennemi(map, map->monster_tex_2, visible_ennemi);
	map->monster_frame++;
}

void	animate_moon(t_map *map, t_sprite visible_ennemi, double d)
{
	if (map->moon_frame >= 0 && map->moon_frame < d)
		put_ennemi(map, map->moon_tex_1, visible_ennemi);
	else if (map->moon_frame >= d && map->moon_frame < d * 2)
		put_ennemi(map, map->moon_tex_2, visible_ennemi);
	else if (map->moon_frame >= d * 2 && map->moon_frame < d * 3)
		put_ennemi(map, map->moon_tex_3, visible_ennemi);
	else if (map->moon_frame >= d * 3 && map->moon_frame < d * 4)
		put_ennemi(map, map->moon_tex_4, visible_ennemi);
	else if (map->moon_frame >= d * 4 && map->moon_frame < d * 5)
		put_ennemi(map, map->moon_tex_5, visible_ennemi);
	else if (map->moon_frame >= d * 5 && map->moon_frame < d * 6)
		put_ennemi(map, map->moon_tex_6, visible_ennemi);
	else if (map->moon_frame >= d * 6 && map->moon_frame < d * 7)
		put_ennemi(map, map->moon_tex_7, visible_ennemi);
	else if (map->moon_frame >= d * 7 && map->moon_frame < d * 8)
		put_ennemi(map, map->moon_tex_8, visible_ennemi);
	else if (map->moon_frame >= d * 8 && map->moon_frame < d * 9)
		put_ennemi(map, map->moon_tex_9, visible_ennemi);
	else if (map->moon_frame >= d * 9 && map->moon_frame < d * 10)
		put_ennemi(map, map->moon_tex_10, visible_ennemi);
	else if (map->moon_frame >= d * 10 && map->moon_frame < d * 11)
		put_ennemi(map, map->moon_tex_11, visible_ennemi);
	map->moon_frame++;
}
