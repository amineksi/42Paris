/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:07:07 by amine             #+#    #+#             */
/*   Updated: 2025/01/08 12:42:06 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_alive(t_philo *philo)
{
	int	rslt;

	pthread_mutex_lock(&philo->dead);
	rslt = philo->alive;
	pthread_mutex_unlock(&philo->dead);
	return (rslt);
}

int	all_alive(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		if (!is_alive(&data->philos[i]))
			return (0);
	}
	return (1);
}

int	meals_done(t_data *data)
{
	int	i;

	i = 0;
	if (!data->nb_meals_defined)
		return (0);
	while (i < data->nb_philo)
	{
		if (data->philos[i++].nb_meals < data->nb_meals)
			return (0);
	}
	return (1);
}

void	take_forks(t_philo *philo)
{
	if (!get_right_fork(get_next_philo(philo->env, philo->idx))
		&& !get_left_fork(philo))
	{
		if (everyone_alive(philo->env) && !check_meals(philo->env))
			print_msg("has taken a fork", philo);
		set_left_fork(philo, 1);
	}
	if (!get_left_fork(get_next_philo(philo->env, philo->idx))
		&& !get_right_fork(philo))
	{
		if (everyone_alive(philo->env) && !check_meals(philo->env))
			print_msg("has taken a fork", philo);
		set_right_fork(philo, 1);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (is_alive(philo) && all_alive(philo->env)
		&& !meals_done(philo->env))
	{
		if (philo->thinking && (!get_left_fork(philo)
			|| !get_right_fork(philo)))
			take_forks(philo);
		if (get_left_fork(philo) && get_right_fork(philo))
			philo_eat(philo);
		if (philo->eating)
			philo_sleep(philo);
		if (get_time() >= philo->last_meal + philo->env->time_to_die)
			killing_philo(philo);
	}
	if (!is_alive(philo) &&	!check_meals(philo->env))
		print_msg("died", philo);
	return (NULL);
}
