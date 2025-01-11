/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:15:46 by amine             #+#    #+#             */
/*   Updated: 2025/01/07 04:21:41 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	rslt;

	i = 0;
	min = 1;
	rslt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		rslt *= 10;
		rslt += str[i++] - '0';
	}
	return (rslt * min);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].dead);
		pthread_mutex_destroy(&data->philos[i].meals);
		pthread_mutex_destroy(&data->philos[i].check_fork);
	}
	pthread_mutex_destroy(&data->print);
	free(data->philos);
}

void	print_msg(char *msg, t_philo *philo)
{
	long	time;

	time = get_time() - philo->env->start_time;
	pthread_mutex_lock(&philo->env->print);
	printf("%ld %d %s\n", time, philo->idx + 1, msg);
	pthread_mutex_unlock(&philo->env->print);
}
