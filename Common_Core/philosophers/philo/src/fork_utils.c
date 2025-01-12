/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:20:45 by amine             #+#    #+#             */
/*   Updated: 2025/01/07 01:07:56 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_left_fork(t_philo *philo)
{
	int	rslt;

	pthread_mutex_lock(&philo->check_fork);
	rslt = philo->left_fork;
	pthread_mutex_unlock(&philo->check_fork);
	return (rslt);
}

int	get_right_fork(t_philo *philo)
{
	int	rslt;

	pthread_mutex_lock(&philo->check_fork);
	rslt = philo->right_fork;
	pthread_mutex_unlock(&philo->check_fork);
	return (rslt);
}

void	set_left_fork(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->left_fork = value;
	pthread_mutex_unlock(&philo->check_fork);
}

void	set_right_fork(t_philo *philo, int value)
{
	pthread_mutex_lock(&philo->check_fork);
	philo->right_fork = value;
	pthread_mutex_unlock(&philo->check_fork);
}
