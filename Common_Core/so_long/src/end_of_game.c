/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:42:43 by amine             #+#    #+#             */
/*   Updated: 2024/12/30 01:58:43 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_key_press(int keycode, t_vars *vars)
{
	if (keycode == 65307 || keycode == 65293)
	{
		mlx_destroy_window(vars->mlx, vars->end_win);
		cleanup_and_exit(vars);
	}
	return (0);
}

int	end_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->end_win);
	cleanup_and_exit(vars);
	return (0);
}

void	end_screen(t_vars *vars, int won)
{
	vars->end_win = mlx_new_window(vars->mlx, 600, 400, "End Screen");
	if (!vars->end_win)
	{
		ft_putstr_fd("Error\nFailed to create end screen window\n", 2);
		cleanup_and_exit(vars);
	}
	if (won)
	{
		ft_printf("TILL IS ALIVE");
		mlx_put_image_to_window(vars->mlx,
			vars->end_win, vars->winning_screen, 0, 0);
	}
	else
	{
		ft_printf(":)");
		mlx_put_image_to_window(vars->mlx,
			vars->end_win, vars->losing_screen, 0, 0);
	}
	mlx_do_sync(vars->mlx);
	mlx_hook(vars->end_win, 2, 1L << 0, end_key_press, vars);
	mlx_hook(vars->end_win, 17, 0, end_close, vars);
	mlx_loop(vars->mlx);
}
