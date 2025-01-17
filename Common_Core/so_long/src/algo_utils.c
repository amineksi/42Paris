/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:08:40 by amine             #+#    #+#             */
/*   Updated: 2024/12/29 22:38:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_cell(char **map, int x, int y, int **visited)
{
	return (x >= 0 && y >= 0 && map[x][y] != '1' && !visited[x][y]
		&& map[x][y] != 'A' && x < ft_doublestrlen(map)
		&& y < (int) ft_strlen(map[0]));
}

int	e_before_end(int x, int y, t_vars *vars)
{
	return ((x == vars->x_end_pos && y == vars->y_end_pos)
		&& vars->count_c != 0);
}

int	**fill_with_zeros(int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (visited[i])
	{
		j = 0;
		while (visited[i][j])
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}
