/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 02:45:18 by amine             #+#    #+#             */
/*   Updated: 2025/01/12 13:22:32 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	change_counter(t_vars *vars)
{
	char	*counter;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_wall,
		0, 0);
	counter = ft_itoa(vars->count_moves);
	if (!counter)
		return ;
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF,
		counter);
	free(counter);
}

int	is_valid_move(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_x][new_y] == '1' || (vars->map[new_x][new_y] == 'E'
		&& vars->initial_count_c != 0))
		return (0);
	if (vars->map[new_x][new_y] == 'A')
	{
		ft_printf("%i\n", ++vars->count_moves);
		end_screen(vars, 0);
		cleanup_and_exit(vars, 0);
	}
	return (1);
}

void	move_player(t_vars *vars, int new_x, int new_y)
{
	if (is_valid_move(vars, new_x, new_y))
	{
		if (vars->map[new_x][new_y] == 'C')
			vars->initial_count_c--;
		vars->map[vars->x_begin_pos][vars->y_begin_pos] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_floor,
			vars->y_begin_pos * 32, vars->x_begin_pos * 32);
		vars->x_begin_pos = new_x;
		vars->y_begin_pos = new_y;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img_p,
			vars->y_begin_pos * 32, vars->x_begin_pos * 32);
		if (vars->map[vars->x_begin_pos][vars->y_begin_pos] == 'E'
			&& vars->count_c == 0)
		{
			ft_printf("%i\n", ++vars->count_moves);
			change_counter(vars);
			end_screen(vars, 1);
		}
		vars->map[vars->x_begin_pos][vars->y_begin_pos] = 'P';
		ft_printf("%i\n", ++vars->count_moves);
		change_counter(vars);
	}
}

int	handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		cleanup_and_exit(vars, 0);
	if (keycode == 119)
		move_player(vars, vars->x_begin_pos - 1, vars->y_begin_pos);
	if (keycode == 97)
		move_player(vars, vars->x_begin_pos, vars->y_begin_pos - 1);
	if (keycode == 115)
		move_player(vars, vars->x_begin_pos + 1, vars->y_begin_pos);
	if (keycode == 100)
		move_player(vars, vars->x_begin_pos, vars->y_begin_pos + 1);
	return (0);
}

int	handle_close(t_vars *vars)
{
	cleanup_and_exit(vars, 0);
	return (0);
}
