/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:06:54 by amine             #+#    #+#             */
/*   Updated: 2024/12/23 23:33:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_cell(char **map, int x, int y, int **visited)
{
	return (x >= 0 && y >= 0 && map[x][y] != '1' && !visited[x][y]);
}

int	e_before_end(int x, int y, t_vars *vars)
{
	return ((x == vars->x_end_pos && y == vars->y_end_pos)
		&& vars->count_c != 0);
}

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

int	existing_path(t_vars *vars)
{
	int	**visited;
	int	rslt;
	int	i;
	int	j;

	i = -1;
	visited = malloc (sizeof(int *) * ft_doublestrlen(vars->map));
	while (vars->map[++i])
	{
		j = 0;
		visited[i] = malloc (sizeof(int) * ft_strlen(vars->map[i]));
		while (vars->map[i][j])
			visited[i][j++] = 0;
	}
	rslt = dfs(vars, vars->x_begin_pos, vars->y_begin_pos, visited);
	i = 0;
	while (i < ft_doublestrlen(vars->map))
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (rslt);
}
