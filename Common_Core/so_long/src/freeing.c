/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:41:52 by akassous          #+#    #+#             */
/*   Updated: 2024/12/26 19:01:58 by amine            ###   ########.fr       */
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
}

void	cleanup_and_exit(t_vars *vars)
{
	if (vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	free_map(vars->map);
	free_images(vars);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

char	**error_handling(char *msg)
{
	ft_printf("Error\n%s", msg);
	return (NULL);
}
