/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:13:25 by amine             #+#    #+#             */
/*   Updated: 2025/01/08 00:06:04 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	new_philo(t_data *data)
{
	t_philo	philo;

	philo.alive = 1;
	philo.eating = 0;
	philo.sleeping = 0;
	philo.thinking = 1;
	philo.last_meal = get_time();
	philo.nb_meals = 0;
	philo.env = data;
	philo.left_fork = 0;
	philo.right_fork = 0;
	return (philo);
}

int	init_philo(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i] = new_philo(data);
		pthread_mutex_init(&data->philos[i].dead, NULL);
		pthread_mutex_init(&data->philos[i].meals, NULL);
		pthread_mutex_init(&data->philos[i].check_fork, NULL);
		data->philos[i].idx = i;
		i++;
	}
	return (1);
}

int	init_data(t_data *data, int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 6)
	{
		data->nb_meals_defined = 1;
		data->nb_meals = ft_atoi(av[5]);
	}
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (0);
		}
	}
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->start_time = get_time();
	pthread_mutex_init(&data->print, NULL);
	return (1);
}

void	start_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->philos[i].thread, NULL,
			routine, &data->philos[i]);
		usleep(1000);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	everyone_alive(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (!data->philos[i].alive)
			return (0);
		i++;
	}
	return (1);
}
