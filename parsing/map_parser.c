/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:40:22 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map(char *line, int fd, int nb_lines)
{
	int		count;

	count = 0;
	while (line)
	{
		if (ft_strcmp(line, "\n") == 0)
			break ;
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (count != nb_lines)
		return (0);
	return (1);
}

int	get_map(t_map *map, char *file_name, char *str, int nb_lines)
{
	int		fd;
	char	*tmp;
	char	*line;

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
	free(tmp);
	if (!is_map(line, fd, nb_lines))
		return (0);
	if (!allocate_map(map, file_name, str, nb_lines))
		return (0);
	return (1);
}

int	valid_player(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'S'
	|| map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'W')
		if (map[i][j + 1] == '\0' || map[i][j + 1] == ' '
		|| map[i][j - 1] == ' ' || map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
			return (0);
	return (1);
}

int	valid_map(int line_count, char **map, t_tools tools)
{
	tools.i = 0;
	if (!map || !map[0])
		return (0);
	if (valid_characters(map) || !valid_line(map[0]) \
	|| !valid_line(map[line_count - 1]))
		return (0);
	tools.i = 1;
	while (map[tools.i] && tools.i < line_count)
	{
		tools.j = 0;
		while (map[tools.i][tools.j] && map[tools.i][tools.j] == ' ')
			tools.j++;
		if (map[tools.i][tools.j] && map[tools.i][tools.j] != '1')
			return (0);
		while (map[tools.i][tools.j])
		{
			if (!valid_player(map, tools.i, tools.j))
				return (0);
			tools.j++;
		}
		tools.i++;
	}
	if (!check_valid_door(map) || !check_valid_sprite(map))
		return (0);
	return (1);
}

// void	print_map(t_map map)
// {
// 	int i = 0;
// 	if (!map.map)
// 		return ;
// 	while (map.map[i])
// 	{
// 		printf("%s\n", map.map[i]);
// 		i++;
// 	}
// }