/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:27:02 by amine             #+#    #+#             */
/*   Updated: 2025/01/08 00:14:14 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	static t_data	data = {};

	if (ac < 5 || ac > 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!init_data(&data, ac, av))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	if (!init_philo(&data))
	{
		printf("Error: failed to initialize philosophers\n");
		return (1);
	}
	start_simulation(&data);
	free_all(&data);
	return (0);
}
