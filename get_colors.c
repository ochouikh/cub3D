/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:57:32 by ochouikh          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_rgb(t_map *map, char *identifier)
{
	t_color	*color;

	color = map->color;
	while (color)
	{
		if (ft_strcmp(color->identifier, identifier) == 0)
			return (color->r << 16 | color->g << 8 | color->b);
		color = color->next;
	}
	return (-1);
}
