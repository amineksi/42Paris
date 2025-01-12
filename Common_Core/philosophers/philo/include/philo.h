/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:27:15 by amine             #+#    #+#             */
/*   Updated: 2025/01/08 00:11:26 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	int				nb_meals;
	int				alive;
	long			last_meal;
	long			last_sleep;
	int				eating;
	int				sleeping;
	int				thinking;
	int				left_fork;
	int				right_fork;
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	dead;
	pthread_mutex_t	meals;
	pthread_mutex_t	check_fork;
	t_data	*env;	
}				t_philo;

typedef struct s_data
{
	int				nb_philo;
	long long				time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int				nb_meals_defined;
	int				nb_meals;
	t_philo			*philos;
	pthread_mutex_t	print;
	long long			start_time;
}				t_data;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
long	get_time(void);
void	print_msg(char *msg, t_philo *philo);
void	killing_philo(t_philo *philo);

int		init_data(t_data *data, int ac, char **av);
void	start_simulation(t_data *data);
int		init_philo(t_data *data);
int		everyone_alive(t_data *data);
void	free_all(t_data *data);

int		get_left_fork(t_philo *philo);
int		get_right_fork(t_philo *philo);
void	set_left_fork(t_philo *philo, int value);
void	set_right_fork(t_philo *philo, int value);
t_philo	*get_next_philo(t_data *data, int idx);

int		check_meals(t_data *data);

void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	*routine(void *arg);

void	killing_philo(t_philo *philo);
int		is_alive(t_philo *philo);
int		all_alive(t_data *data);
int		meals_done(t_data *data);

#endif