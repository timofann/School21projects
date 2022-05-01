/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:04:27 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:04:30 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_error.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_data {
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*alive_mutex;
	pthread_mutex_t	number_of_meals_mutex;
	pthread_mutex_t	last_meal_time_mutex;
	size_t			philosophers_number;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat;
	size_t			start_time;
	size_t			current_number;
	size_t			left_fork;
	size_t			right_fork;
	size_t			last_meal_time;
	size_t			number_of_meals;
	int				*alive;
}	t_philo_data;

void	msleep(size_t time);
void	mprintf(char *mess, t_philo_data *data);
int		check_alive(t_philo_data *data);

void	set_current_time(size_t *time_mlsec);
void	set_time_interval(size_t last_time, size_t *time);

int		set_arguments(t_philo_data *data, int argc, char **argv);
int		set_general(t_philo_data *general, int argc, char **argv);
int		set_personal(t_philo_data **personal, t_philo_data *general);

int		philo_eat(t_philo_data *data);
int		philo_sleep(t_philo_data *data);
int		philo_think(t_philo_data *data);
int		philo_scenario(t_philo_data *data);
void	life_monitoring(t_philo_data *general, t_philo_data *personal);

int		start_dinner(t_philo_data *personal, t_philo_data *general,
			pthread_t *philosophers);

#endif