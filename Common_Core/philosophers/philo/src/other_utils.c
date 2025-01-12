/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 01:06:01 by amine             #+#    #+#             */
/*   Updated: 2025/01/07 04:39:19 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	killing_philo(t_philo *philo)
{
	if (!everyone_alive(philo->env))
		return ;
	pthread_mutex_lock(&philo->dead);
	philo->alive = 0;
	pthread_mutex_unlock(&philo->dead);
}

t_philo	*get_next_philo(t_data *data, int idx)
{
	if (idx == data->nb_philo - 1)
		return (&data->philos[0]);
	return (&data->philos[idx + 1]);
}

int	check_meals(t_data *data)
{
	int	i;

	i = 0;
	if (!data->nb_meals_defined)
		return (0);
	while (i < data->nb_philo)
	{
		if (data->philos[i].nb_meals < data->nb_meals)
			return (0);
		i++;
	}
	return (1);
}
