/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:40:26 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/24 21:51:32 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	read_colors_textures(t_tools *tools, t_map *map)
{
	tools->i = 0;
	tools->j = 0;
	while (tools->input[tools->i] && tools->j < 6)
	{
		if (ft_isempty(tools->input[tools->i]))
			tools->i++;
		else
		{
			tools->j++;
			if (!valid_input(tools->input[tools->i], map))
				return (ft_putstr_fd("Error\ninvalide input\n", 2), \
				ft_free(tools->input), 0);
		}
		tools->i++;
	}
	while (tools->input[tools->i] && ft_isempty(tools->input[tools->i]))
		tools->i++;
	if (!tools->input[tools->i])
		return (ft_putstr_fd("Error\ninvalide input\n", 2), clear_colors(map), \
		clear_textures(map), ft_free(tools->input), 0);
	return (1);
}

int	valid_file_content(t_tools *tools, t_map *map, char **argv)
{
	if (!check_double_color(map) || !check_double_texture(map))
		return (clear_colors(map), clear_textures(map), \
		ft_free(tools->input), 0);
	if (!get_map(map, argv[1], tools->input[tools->j], tools->count))
		return (clear_colors(map), clear_textures(map), \
		ft_putstr_fd("Error\ninvalide map\n", 2), ft_free(tools->input), 0);
	map->line_count = tools->count;
	if (!valid_map(map->line_count, map->map, *tools))
		return (clear_colors(map), clear_textures(map), ft_free(map->map), \
		ft_putstr_fd("Error\ninvalide map\n", 2), ft_free(tools->input), 0);
	return (1);
}

static int	check_valid_path(char *argv)
{
	char	*path;
	int		l;

	path = ft_strrchr(argv, '.');
	l = ft_strlen(path);
	if (l == 4)
	{
		if (ft_strcmp(path, ".cub") != 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	file_parsing(char **argv, t_map	*map)
{
	t_tools	tools;

	if (!check_valid_path(argv[1]))
		return (ft_putstr_fd("Error\ninvalid path", 2), 0);
	tools.input = read_file(argv);
	if (!tools.input)
		return (0);
	if (!read_colors_textures(&tools, map))
		return (0);
	tools.j = tools.i;
	tools.count = 0;
	while (tools.input[tools.i])
	{
		if (ft_isempty(tools.input[tools.i]))
			return (clear_colors(map), clear_textures(map), \
			ft_putstr_fd("Error\ninvalide map\n", 2), ft_free(tools.input), 0);
		tools.count++;
		tools.i++;
	}
	if (!valid_file_content(&tools, map, argv))
		return (0);
	if (!realloc_map(map))
		return (ft_free(map->map), clear_colors(map), clear_textures(map), 0);
	return (ft_free(tools.input), 1);
}
