/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:19:30 by akassous          #+#    #+#             */
/*   Updated: 2024/12/26 19:07:37 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_gnl(int fd, int *cols, int *rows, char **line)
{
	int	line_length;

	*line = get_next_line(fd, 0);
	if (!*line)
		return (0);
	line_length = ft_strlen(*line);
	if ((*line)[ft_strlen(*line) - 1] == '\n')
		line_length--;
	if (*cols == -1)
		*cols = line_length;
	else if (line_length != *cols)
	{
		free(*line);
		get_next_line(fd, 1);
		return (-1);
	}
	(*rows)++;
	free(*line);
	return (1);
}

int	count_and_validate_map(const char *file_path, int *rows, int *cols)
{
	int		fd;
	char	*line;
	int		rslt;

	*rows = 0;
	*cols = -1;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		rslt = loop_gnl(fd, cols, rows, &line);
		if (rslt == -1)
		{
			close(fd);
			return (-1);
		}
		if (rslt == 0)
			break ;
	}
	close(fd);
	return (0);
}

char	**allocate_map(int rows)
{
	char	**map;

	map = (char **) malloc((rows + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}

char	**fill_map(const char *file_path, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	i = 0;
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		map[i] = ft_strdup(line);
		if (!(map[i]))
		{
			free(line);
			close(fd);
			return (NULL);
		}
		free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**read_map(const char *file_path)
{
	int		rows;
	int		cols;
	char	**map;

	if (count_and_validate_map(file_path, &rows, &cols) < 0)
		return (NULL);
	map = allocate_map(rows);
	if (!map)
		return (NULL);
	map = fill_map(file_path, map);
	if (!map)
		return (NULL);
	return (map);
}
