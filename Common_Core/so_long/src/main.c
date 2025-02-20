/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:44:35 by akassous          #+#    #+#             */
/*   Updated: 2025/01/12 12:58:47 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_width(char **map)
{
	int	width;

	width = 0;
	while (map[ft_doublestrlen(map) - 1][width])
		width++;
	return (width);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

int	mlx_err_handle(t_vars vars)
{
	free_map(vars.map);
	ft_putstr_fd("Error\nmlx error\n", 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.map = checking_args(argc, argv);
	if (!vars.map)
		return (0);
	if (!map_conditions(&vars))
		return (0);
	vars.count_moves = 0;
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (mlx_err_handle(vars));
	vars.win = mlx_new_window(vars.mlx, 32 * get_map_width(vars.map),
			32 * get_map_height(vars.map), "so_long");
	if (!vars.win)
	{
		free(vars.mlx);
		return (mlx_err_handle(vars));
	}
	load_images(&vars);
	draw_map(&vars);
	mlx_hook(vars.win, 2, 1L << 0, handle_key_press, &vars);
	mlx_hook(vars.win, 17, 0, handle_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
