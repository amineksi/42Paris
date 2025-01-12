/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akassous <akassous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:43:06 by amine             #+#    #+#             */
/*   Updated: 2025/01/12 13:22:38 by akassous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_error(t_vars *vars)
{
	if (!vars->img_wall || !vars->img_floor || !vars->img_p
		|| !vars->img_e || !vars->img_c || !vars->winning_screen
		|| !vars->losing_screen || !vars->alien)
		cleanup_and_exit(vars, 0);
}

void	load_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->img_wall = mlx_xpm_file_to_image(vars->mlx,
			"assets/wall.xpm", &width, &height);
	vars->img_floor = mlx_xpm_file_to_image(vars->mlx,
			"assets/grass.xpm", &width, &height);
	vars->img_p = mlx_xpm_file_to_image(vars->mlx,
			"assets/player_new.xpm", &width, &height);
	vars->img_e = mlx_xpm_file_to_image(vars->mlx,
			"assets/exit_new.xpm", &width, &height);
	vars->img_c = mlx_xpm_file_to_image(vars->mlx,
			"assets/c_new.xpm", &width, &height);
	vars->winning_screen = mlx_xpm_file_to_image(vars->mlx,
			"assets/winning.xpm", &width, &height);
	vars->losing_screen = mlx_xpm_file_to_image(vars->mlx,
			"assets/losing.xpm", &width, &height);
	vars->alien = mlx_xpm_file_to_image(vars->mlx,
			"assets/alien_new.xpm", &width, &height);
	check_error(vars);
}

void	*select_image(t_vars *vars, int i, int j)
{
	void	*img;

	img = NULL;
	if (vars->map[i][j] == '1')
		img = vars->img_wall;
	else if (vars->map[i][j] == '0')
		img = vars->img_floor;
	else if (vars->map[i][j] == 'P')
		img = vars->img_p;
	else if (vars->map[i][j] == 'E')
		img = vars->img_e;
	else if (vars->map[i][j] == 'C')
		img = vars->img_c;
	else if (vars->map[i][j] == 'A')
		img = vars->alien;
	return (img);
}

void	draw_map(t_vars *vars)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j] && vars->map[i][j] != '\n')
		{
			img = select_image(vars, i, j);
			if (img && vars->win)
				mlx_put_image_to_window(vars->mlx, vars->win,
					img, j * 32, i * 32);
			j++;
		}
		i++;
	}
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0xFFFFFF, "0");
}
