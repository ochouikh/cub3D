/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:58:07 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/25 09:24:12 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (0);
	}
	ft_memset(&map, 0, sizeof(t_map));
	if (!file_parsing(av, &map))
		return (0);
	if (!ft_initialize(&map))
	{	
		clear_colors(&map);
		clear_textures(&map);
		ft_free(map.map);
		return (0);
	}
	if (!start_drawing(&map))
	{
		clear_colors(&map);
		clear_textures(&map);
		ft_free(map.map);
		return (0);
	}
	return (0);
}
