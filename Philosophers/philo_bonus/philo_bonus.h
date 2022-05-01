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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include "philo_bonus_error.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <errno.h>

typedef struct s_philo_data {
	size_t			philosophers_number;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			must_eat;
	size_t			start_time;
	size_t			current_number;
	pthread_t		life_monitoring;
	size_t			last_meal_time;
	pthread_mutex_t	last_meal_time_mutex;
	pthread_mutex_t	number_of_meals_mutex;
	size_t			number_of_meals;
	sem_t			*print_sem;
	sem_t			*forks_sem;
}	t_philo_data;

void	msleep(size_t time);
void	mprintf(char *mess, t_philo_data *data);

void	kill_philosophers(pid_t *pid_array, size_t pid_count);
void	init_sighandler(pid_t *pid_array, size_t pid_count);

void	set_current_time(size_t *time_mlsec);
void	set_time_interval(size_t last_time, size_t *time);

void	set_arguments(t_philo_data *data, int argc, char **argv);
void	set_general(t_philo_data *general, int argc, char **argv);

void	philo_eat(t_philo_data *data);
void	philo_sleep(t_philo_data *data);
void	philo_think(t_philo_data *data);
void	philo_scenario(t_philo_data *data);
void	*life_monitoring(void *ptr);

void	start_dinner(t_philo_data *general, pid_t *philosophers);

#endif
