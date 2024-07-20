/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:53:54 by bdenfir           #+#    #+#             */
/*   Updated: 2024/07/16 20:53:54 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/map.h"
#include "../includes/point.h"

int	min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

void	get_biggest(t_map *map, t_point max_point, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->data[max_point.row - i][max_point.col - j] = map->full;
			j++;
		}
		i++;
	}
}

/* Trouve le plus grand carré vide dans la carte (map) et 
le marque en utilisant get_biggest. */
/* Allocation mémoire pour le tableau 2D  ayant les mêmes 
dimensions que la map. */

int	**__init__(t_map *map)
{
	int	**dp;
	int	i;

	i = 0;
	dp = (int **)malloc(sizeof(int *) * (map->rows));
	while (i < map->rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * (map->cols));
		if (!dp[i])
		{
			while (0 < i)
				free(dp[i--]);
			free(dp);
			return (NULL);
		}
		i++;
	}
	return (dp);
}

t_point	space_saver(t_map *map, t_point max_point, int *max_size, int **dp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->data[i][j] == map->empty)
			{
				assign_values(i, j, dp);
				if (dp[i][j] > *max_size)
				{
					*max_size = dp[i][j];
					max_point.row = i;
					max_point.col = j;
				}
			}
			else
				dp[i][j] = 0;
			j++;
		}
	}
	return (max_point);
}

void	find_biggest_square(t_map *map)
{
	t_point	max_point;
	int		max_size;
	int		i;
	int		**dp;

	dp = __init__(map);
	if (!dp)
		return ;
	max_point.col = 0;
	max_point.row = 0;
	max_size = 0;
	max_point = space_saver(map, max_point, &max_size, dp);
	get_biggest(map, max_point, max_size);
	i = 0;
	while (i < map->rows)
		free(dp[i++]);
	free(dp);
}
