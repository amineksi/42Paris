/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:06:54 by amine             #+#    #+#             */
/*   Updated: 2024/12/30 02:02:59 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_vars *vars, int x, int y, int **visited)
{
	if (!is_valid_cell(vars->map, x, y, visited)
		|| e_before_end(x, y, vars))
		return (0);
	visited[x][y] = 1;
	if (vars->map[x][y] == 'C')
		vars->count_c--;
	if (vars->count_c == 0 && x == vars->x_end_pos && y == vars->y_end_pos)
		return (1);
	if (dfs(vars, x + 1, y, visited) || dfs(vars, x - 1, y, visited)
		|| dfs(vars, x, y + 1, visited) || dfs(vars, x, y - 1, visited))
		return (1);
	visited[x][y] = 0;
	if (vars->map[x][y] == 'C')
		vars->count_c++;
	return (0);
}

int	**allocate_visited(char **map, int map_length)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * map_length);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map_length)
	{
		visited[i] = malloc(sizeof(int) * ft_strlen(map[i]));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		j = 0;
		while (map[i][j])
			visited[i][j++] = 0;
		i++;
	}
	return (visited);
}

void	free_visited(int **visited, int map_length)
{
	int	i;

	i = 0;
	while (i < map_length)
		free(visited[i++]);
	free(visited);
}

int	existing_path(t_vars *vars)
{
	int	**visited;
	int	rslt;
	int	map_length;

	map_length = ft_doublestrlen(vars->map);
	visited = allocate_visited(vars->map, map_length);
	if (!visited)
		return (0);
	rslt = dfs(vars, vars->x_begin_pos, vars->y_begin_pos, visited);
	free_visited(visited, map_length);
	return (rslt);
}
