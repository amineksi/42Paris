/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:19:30 by akassous          #+#    #+#             */
/*   Updated: 2025/01/12 12:09:35 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_doublestrlen(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
		i++;
	return (i);
}

static char	**join_d_dim(char **s1, char *s2)
{
	char	**rslt;
	int		len;
	int		i;

	len = ft_doublestrlen(s1);
	i = 0;
	rslt = malloc((len + 2) * sizeof(char *));
	if (!rslt)
		return (NULL);
	while (i < len)
	{
		rslt[i] = ft_strdup(s1[i]);
		free(s1[i]);
		i++;
	}
	rslt[i++] = ft_strdup(s2);
	rslt[i] = NULL;
	free(s1);
	return (rslt);
}

char	**read_map(char *file_path)
{
	int		fd;
	char	**rslt;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	rslt = malloc(sizeof(char *));
	if (!rslt)
		return (NULL);
	rslt[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		rslt = join_d_dim(rslt, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (rslt);
}
