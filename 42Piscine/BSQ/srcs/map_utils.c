/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:15:15 by akassous          #+#    #+#             */
/*   Updated: 2024/07/17 16:24:56 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (i < map->rows)
		free(map->data[i++]);
	free(map->data);
	free(map);
	return (1);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->data[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}

char	**allocate_map_data(int rows, int cols)
{
	char	**data;
	int		i;
	int		j;

	i = 0;
	data = (char **)malloc(sizeof(char *) * rows);
	if (!data)
		return (NULL);
	while (i < rows)
	{
		data[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (!data[i])
		{
			j = 0;
			while (j < i)
				free(data[j++]);
			free(data);
			return (NULL);
		}
		i++;
	}
	return (data);
}

int	get_length(char *buffer)
{
	char	*line;
	char	*line_end;
	int		line_length;

	line = buffer;
	line_end = line;
	line_length = 0;
	while (*line_end != '\n' && *line_end != '\0')
		line_end++;
	line = line_end + 1;
	while (line[line_length] != '\n' && line[line_length] != '\0')
		line_length++;
	if (line[line_length] == '\0')
		return (0);
	return (line_length);
}

int	check_free(t_map *map, int line_count)
{
	if (line_count != map->rows)
	{
		free_map(map);
		return (0);
	}
	return (1);
}
