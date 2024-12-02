/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:03:56 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/25 10:02:26 by hel-mamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_color_texture_list(char **temp, t_map *map)
{
	int	fd;

	if (!ft_strcmp(temp[0], "F") || !ft_strcmp(temp[0], "C"))
	{
		if (!get_color(temp[1]))
			return (0);
		if (!ft_lstadd_color(&map->color, ft_newcolor(temp[1], temp[0])))
			return (0);
	}
	else if (!ft_strcmp(temp[0], "NO") || !ft_strcmp(temp[0], "SO")
		|| !ft_strcmp(temp[0], "WE") || !ft_strcmp(temp[0], "EA"))
	{
		fd = open(temp[1], O_RDONLY);
		if (fd == -1)
			return (ft_putstr_fd("Error\nPath error:", 2), 0);
		close(fd);
		if (!ft_lstadd_texture(&map->texture, ft_newtexture(temp[0], temp[1])))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	valid_input(char *input, t_map *map)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(input, ' ');
	while (temp[i])
		i++;
	if (i != 2)
		return (ft_free(temp), 0);
	if (!create_color_texture_list(temp, map))
		return (ft_free(temp), 0);
	ft_free(temp);
	return (1);
}

int	split_file_content(t_tools *tools)
{
	tools->temp = NULL;
	tools->input = 0;
	tools->input = ft_split(tools->str, '\n');
	if (!tools->input)
		return (0);
	free(tools->str);
	return (1);
}

char	**read_file(char **argv)
{
	t_tools	tools;

	tools.fd = open(argv[1], O_RDONLY);
	if (tools.fd == -1)
		return (0);
	tools.temp = malloc(sizeof(char) * 1025);
	if (!tools.temp)
		return (0);
	tools.str = ft_strdup("");
	tools.i = 1025;
	while (tools.i != 0)
	{
		tools.i = read(tools.fd, tools.temp, 1024);
		if (tools.i == -1)
			return (free(tools.str), free(tools.temp), close(tools.fd), NULL);
		tools.temp[tools.i] = '\0';
		tools.str = ft_strjoin(tools.str, tools.temp, 1, 0);
		if (!tools.str)
			return (free(tools.temp), close(tools.fd), NULL);
	}
	free(tools.temp);
	close(tools.fd);
	if (split_file_content(&tools) == 0)
		return (free(tools.str), NULL);
	return (tools.input);
}
