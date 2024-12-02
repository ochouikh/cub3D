/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:32 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	allocate_map2(t_map *map, char *line, int fd, int nb_lines)
{
	int		i;

	i = 0;
	while (line && i < nb_lines)
	{
		map->map[i] = ft_strdupn(line);
		if (!map->map[i])
			return (ft_free(map->map), free(line), 0);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (1);
}

int	allocate_map(t_map *map, char *file_name, char *str, int nb_lines)
{
	int		fd;
	char	*tmp;
	char	*line;

	map->map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!map->map)
		return (0);
	map->map[nb_lines] = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	tmp = ft_strjoin(str, "\n", 0, 0);
	if (!tmp)
		return (free(line), 0);
	while (line)
	{
		if (ft_strcmp(line, tmp) == 0)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	if (!allocate_map2(map, line, fd, nb_lines))
		return (free(tmp), 0);
	return (free(tmp), 1);
}

int	fill_array(char **new_map, t_map *map, int line_len)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		new_map[i] = malloc(sizeof(char) * (line_len + 1));
		if (!new_map[i])
			return (ft_free(new_map), 0);
		j = 0;
		while (j < line_len)
		{
			if (j < ft_strlen(map->map[i]))
				new_map[i][j] = map->map[i][j];
			else
				new_map[i][j] = ' ';
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	return (1);
}

int	realloc_map(t_map *map)
{
	int		i;
	int		line_len;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (map->line_count + 1));
	if (!new_map)
		return (0);
	new_map[map->line_count] = NULL;
	i = 1;
	line_len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) > line_len)
			line_len = ft_strlen(map->map[i]);
		i++;
	}
	if (!fill_array(new_map, map, line_len))
		return (0);
	ft_free(map->map);
	map->map = new_map;
	return (1);
}
