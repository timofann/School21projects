/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:56:16 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:56:18 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static
void	check_living(t_philo_data *personal)
{
	size_t			current_time;
	size_t			interval;

	if (pthread_mutex_lock(&(personal -> last_meal_time_mutex)))
		put_error(ACCESS_TO_MUTEX);
	set_time_interval(personal -> last_meal_time, &interval);
	if (pthread_mutex_unlock(&(personal -> last_meal_time_mutex)))
		put_error(MUTEX_UNLOCK_ACCESS);
	if (interval > personal -> time_to_die)
	{
		sem_wait(personal -> print_sem);
		set_time_interval(personal -> start_time, &current_time);
		printf("%08zu %zu died\n", current_time,
			personal -> current_number + 1);
		exit(1);
	}
}

static
void	check_satisfying(t_philo_data *personal)
{
	if (pthread_mutex_lock(&(personal -> number_of_meals_mutex)))
		put_error(ACCESS_TO_MUTEX);
	if (personal -> number_of_meals == personal -> must_eat
		&& personal -> must_eat != 0)
	{
		sem_post(personal -> print_sem);
		exit(0);
	}
	if (pthread_mutex_unlock(&(personal -> number_of_meals_mutex)))
		put_error(MUTEX_UNLOCK_ACCESS);
}

void	*life_monitoring(void *ptr)
{
	t_philo_data	*personal;

	personal = (t_philo_data *)ptr;
	while (1)
	{
		msleep(5);
		check_living(personal);
		check_satisfying(personal);
	}
}
