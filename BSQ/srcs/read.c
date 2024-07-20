/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:05:05 by marvin            #+#    #+#             */
/*   Updated: 2024/07/17 01:05:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

t_map	*read_map(int fd)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	if (!check_maps(fd, map))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}

t_map	*read_map_from_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	return (read_map(fd));
}

t_map	*read_map_from_stdin(void)
{
	return (read_map(0));
}
