/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:57:57 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:58:00 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static
int	odd_philosopher(t_philo_data *personal, size_t number)
{
	personal -> current_number = number;
	if (pthread_mutex_init(&(personal -> last_meal_time_mutex), NULL))
		put_error(MEMORY_ERROR);
	if (pthread_mutex_init(&(personal -> number_of_meals_mutex), NULL))
		put_error(MEMORY_ERROR);
	if (pthread_create(&(personal -> life_monitoring),
			NULL, life_monitoring, personal))
		put_error(MAX_THREADS);
	philo_think(personal);
	while (1)
		philo_scenario(personal);
}

static
int	even_philosopher(t_philo_data *personal, size_t number)
{
	personal -> current_number = number;
	if (pthread_mutex_init(&(personal -> last_meal_time_mutex), NULL))
		put_error(MEMORY_ERROR);
	if (pthread_mutex_init(&(personal -> number_of_meals_mutex), NULL))
		put_error(MEMORY_ERROR);
	if (pthread_create(&(personal -> life_monitoring),
			NULL, life_monitoring, personal))
		put_error(MAX_THREADS);
	philo_think(personal);
	msleep(10);
	while (1)
		philo_scenario(personal);
}

static
void	start_odd_philosophers(t_philo_data *general, pid_t *philosophers)
{
	size_t	i;
	pid_t	process_id;

	i = 0;
	while (i < general -> philosophers_number)
	{
		process_id = fork();
		if (process_id == -1)
		{
			kill_philosophers(philosophers, i);
			sem_unlink("print_sem");
			sem_unlink("forks");
			put_error(MAX_PROCESSES);
		}
		else if (process_id == 0)
			odd_philosopher(general, i);
		else
			philosophers[i] = process_id;
		i += 2;
	}
}

static
void	start_even_philosophers(t_philo_data *general, pid_t *philosophers)
{
	size_t	i;
	pid_t	process_id;

	i = 1;
	while (i < general -> philosophers_number)
	{
		process_id = fork();
		if (process_id == -1)
		{
			kill_philosophers(philosophers, i);
			sem_unlink("print_sem");
			sem_unlink("forks");
			put_error(MAX_PROCESSES);
		}
		else if (process_id == 0)
			even_philosopher(general, i);
		else
			philosophers[i] = process_id;
		i += 2;
	}
}

void	start_dinner(t_philo_data *general, pid_t *philosophers)
{
	start_odd_philosophers(general, philosophers);
	start_even_philosophers(general, philosophers);
}
