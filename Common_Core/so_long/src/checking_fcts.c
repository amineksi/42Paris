/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_fcts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 02:46:34 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 20:13:48 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_ber_extension(const char *filename)
{
	const char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext)
		return (0);
	return (ft_strncmp(ext, ".ber", 4) == 0);
}

int	surrounded_by_walls(int rows, int cols, char **map)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

char	**check_map_content(char **map)
{
	int	map_length;

	if (!map || !map[0])
		return (error_handling("Invalid map."));
	map_length = ft_doublestrlen(map);
	if (!surrounded_by_walls(map_length, ft_strlen(map[map_length - 1]), map))
		return (error_handling("Not surrounded by walls."));
	return (map);
}

char	**checking_args(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		return (error_handling("Wrong amount of arguments."));
	if (!has_ber_extension(argv[1]))
		return (error_handling("Wrong file extension."));
	map = read_map(argv[1]);
	if (!map)
		return (error_handling("Invalid map size."));
	if (!check_map_content(map))
	{
		free_map(map);
		return (0);
	}
	return (map);
}
