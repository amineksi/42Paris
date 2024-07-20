/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:47:23 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/16 20:47:23 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

int	get_params(char *line, t_map *map)
{
	int	i;

	i = 0;
	map->rows = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		map->rows = map->rows * 10 + (line[i] - '0');
		i++;
	}
	if (line[i] == '\0' || line[i + 1] == '\0' || line[i + 2] == '\0')
		return (0);
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	return (1);
}

int	check_maps(int fd, t_map *map)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		line_length;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (0);
	buffer[bytes_read] = '\0';
	if (!parse_map_details(buffer, map))
		return (0);
	line_length = get_length(buffer);
	if (line_length == 0)
		return (0);
	map->cols = line_length;
	map->data = allocate_map_data(map->rows, map->cols);
	if (!map->data)
		return (0);
	if (!create_map(buffer, map))
		return (0);
	return (1);
}

int	parse_map_details(char *buffer, t_map *map)
{
	char	*line;
	char	*line_end;

	line = buffer;
	line_end = line;
	while (*line_end != '\n' && *line_end != '\0')
		line_end++;
	if (*line_end == '\0' || !get_params(line, map))
		return (0);
	return (1);
}

int	create_map(char *buffer, t_map *map)
{
	char	*line;
	char	*line_end;
	int		line_count;

	line = buffer;
	line_count = 0;
	while (*line != '\n' && *line != '\0')
		line++;
	line++;
	while (line_count < map->rows && *line != '\0')
	{
		line_end = line + map->cols;
		if (*line_end != '\n' && *line_end != '\0')
		{
			free_map(map);
			return (0);
		}
		if (!check_line(line, map, line_count))
			return (0);
		line_count++;
		line = line_end + 1;
	}
	return (check_free(map, line_count));
}

int	check_line(char *line, t_map *map, int line_count)
{
	int	i;

	i = 0;
	while (i < map->cols)
	{
		if (line[i] != map->empty && line[i] != map->obstacle)
		{
			free_map(map);
			return (0);
		}
		map->data[line_count][i] = line[i];
		i++;
	}
	map->data[line_count][map->cols] = '\0';
	return (1);
}
