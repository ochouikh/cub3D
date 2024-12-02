/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouikh <ochouikh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:51:10 by hel-mamo          #+#    #+#             */
/*   Updated: 2023/07/21 15:38:25 by ochouikh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_str_chr(char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_save_line(char *stash)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	temp = (char *)malloc(len + 2 * sizeof(char));
	if (!temp)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		temp[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_save_rest(char *stash)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (!stash[len])
	{
		free(stash);
		return (NULL);
	}
	temp = (char *)malloc(ft_strlen(stash) - len + 1 * sizeof(char));
	if (!temp)
	{
		free(stash);
		return (NULL);
	}
	len++;
	i = 0;
	while (stash[len])
		temp[i++] = stash[len++];
	temp[i] = '\0';
	free(stash);
	return (temp);
}

char	*read_from_buffer(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		ncr;

	ncr = BUFFER_SIZE;
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	while (ncr != 0 && !ft_str_chr(stash, '\n'))
	{
		ncr = read(fd, buffer, BUFFER_SIZE);
		if (ncr == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[ncr] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buffer, 0, 0);
		free(temp);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd == -1 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_from_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_save_line(stash);
	stash = ft_save_rest(stash);
	return (line);
}
