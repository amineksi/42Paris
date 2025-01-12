/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:21:23 by amine             #+#    #+#             */
/*   Updated: 2025/01/12 12:58:25 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E'
		|| c == 'C' || c == 'A');
}

void	count_chars(char c, int *count_e, int *count_p, int *count_c)
{
	if (c == 'E')
		(*count_e)++;
	if (c == 'P')
		(*count_p)++;
	if (c == 'C')
		(*count_c)++;
}

void	set_positions(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P')
	{
		vars->x_begin_pos = i;
		vars->y_begin_pos = j;
	}
	if (vars->map[i][j] == 'E')
	{
		vars->x_end_pos = i;
		vars->y_end_pos = j;
	}
}

int	correct_caracters(t_vars *vars)
{
	int	i;
	int	j;

	vars->count_e = 0;
	vars->count_p = 0;
	vars->count_c = 0;
	i = -1;
	while (vars->map[++i])
	{
		j = 0;
		while (vars->map[i][j] && vars->map[i][j] != '\n')
		{
			if (!valid_char(vars->map[i][j]))
				return (0);
			set_positions(vars, i, j);
			count_chars(vars->map[i][j], &vars->count_e,
				&vars->count_p, &vars->count_c);
			j++;
		}
	}
	vars->initial_count_c = vars->count_c;
	return (vars->count_e == 1 && vars->count_p == 1 && vars->count_c >= 1);
}

int	map_conditions(t_vars *vars)
{
	if (!matching_size(vars->map))
	{
		free_map(vars->map);
		error_handling("Incorrect map size");
		return (0);
	}
	if (!correct_caracters(vars))
	{
		free_map(vars->map);
		error_handling("Incorrect caracters.");
		return (0);
	}
	if (!existing_path(vars))
	{
		free_map(vars->map);
		error_handling("No path to exit.");
		return (0);
	}
	return (1);
}
