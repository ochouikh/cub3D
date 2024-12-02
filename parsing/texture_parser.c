/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:38:03 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/24 21:53:33 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_double_texture(t_map *map)
{
	t_texture	*temp;
	t_texture	*temp2;

	temp = map->texture;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (!ft_strcmp(temp->direction, temp2->direction))
				return (ft_putstr_fd("Error\nOption duplicated\n", 2), 0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

void	clear_textures(t_map *map)
{
	t_texture	*temp;

	while (map->texture)
	{
		temp = map->texture;
		map->texture = map->texture->next;
		free(temp->direction);
		free(temp->path);
		free(temp);
	}
}

t_texture	*ft_newtexture(char *direction, char *path)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->direction = ft_strdup(direction);
	if (!texture->direction)
		return (free(texture), NULL);
	texture->path = ft_strdup(path);
	if (!texture->path)
		return (free(texture->direction), free(texture), NULL);
	texture->next = NULL;
	return (texture);
}

int	ft_lstadd_texture(t_texture **texture, t_texture *newt)
{
	t_texture	*temp;

	if (!newt)
		return (0);
	if (!*texture)
	{
		*texture = newt;
		return (1);
	}
	temp = *texture;
	while (temp->next)
		temp = temp->next;
	temp->next = newt;
	return (1);
}

// void	print_textures(t_map map)
// {
// 	int j = 0;
// 	while (map.texture)
// 	{
// 		printf("texture (path:%s): %s\n", map.texture->path,
// 	 	map.texture->direction);
// 		j++;
// 		map.texture = map.texture->next;
// 	}
// }
