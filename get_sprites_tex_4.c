/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_tex_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:41:15 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_sprites_tex(t_map *map)
{
	if (!get_moon_tex(map) || !get_monster_tex(map)
		|| !get_dragon_tex(map) || !get_insect_tex(map)
		|| !get_door_tex(map))
		return (0);
	return (1);
}
