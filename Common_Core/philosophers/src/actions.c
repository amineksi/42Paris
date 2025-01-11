/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:14:10 by amine             #+#    #+#             */
/*   Updated: 2025/01/08 00:12:02 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo)
{
	philo->last_meal = get_time();
	philo->eating = 1;
	philo->thinking = 0;
	if (everyone_alive(philo->env))
		print_msg("is eating", philo);
	pthread_mutex_lock(&philo->meals);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->meals);
	while (get_time() <= philo->last_meal + philo->env->time_to_eat
		&& is_alive(philo))
	{
		if (get_time() >= philo->last_meal + philo->env->time_to_die)
			killing_philo(philo);
	}
	set_left_fork(philo, 0);
	set_right_fork(philo, 0);
}

void	philo_sleep(t_philo *philo)
{
	philo->eating = 0;
	philo->sleeping = 1;
	philo->last_sleep = get_time();
	if (everyone_alive(philo->env) && !check_meals(philo->env))
		print_msg("is sleeping", philo);
	while (get_time() <= philo->last_sleep + philo->env->time_to_sleep
		&& is_alive(philo))
	{
		if (get_time() >= philo->last_meal + philo->env->time_to_die)
			killing_philo(philo);
	}
	philo_thinking(philo);
}

void	philo_thinking(t_philo *philo)
{
	philo->thinking = 1;
	philo->sleeping = 0;
	if (everyone_alive(philo->env) && !check_meals(philo->env))
		print_msg("is thinking", philo);
}