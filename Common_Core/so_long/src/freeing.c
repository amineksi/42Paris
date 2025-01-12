/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:41:52 by akassous          #+#    #+#             */
/*   Updated: 2024/12/30 01:44:33 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_vars *vars)
{
	if (vars->img_wall)
		mlx_destroy_image(vars->mlx, vars->img_wall);
	if (vars->img_floor)
		mlx_destroy_image(vars->mlx, vars->img_floor);
	if (vars->img_p)
		mlx_destroy_image(vars->mlx, vars->img_p);
	if (vars->img_e)
		mlx_destroy_image(vars->mlx, vars->img_e);
	if (vars->img_c)
		mlx_destroy_image(vars->mlx, vars->img_c);
	if (vars->winning_screen)
		mlx_destroy_image(vars->mlx, vars->winning_screen);
	if (vars->losing_screen)
		mlx_destroy_image(vars->mlx, vars->losing_screen);
	if (vars->alien)
		mlx_destroy_image(vars->mlx, vars->alien);
}

void	cleanup_and_exit(t_vars *vars, int end)
{
	if (vars && vars->mlx)
	{
		if (vars->win)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			vars->win = NULL;
		}
		if (end && vars->end_win)
		{
			mlx_destroy_window(vars->mlx, vars->end_win);
			vars->end_win = NULL;
		}
		free_map(vars->map);
		free_images(vars);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**error_handling(char *msg)
{
	ft_printf("Error\n%s", msg);
	return (NULL);
}
