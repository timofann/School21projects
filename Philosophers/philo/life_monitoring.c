/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_monitoring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:59:35 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/30 20:59:37 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
int	check_living(t_philo_data *personal, t_philo_data *general)
{
	size_t	i;
	size_t	current_time;
	size_t	interval;

	set_time_interval(general -> start_time, &current_time);
	i = 0;
	while (i < general -> philosophers_number)
	{
		pthread_mutex_lock(&(personal[i].last_meal_time_mutex));
		set_time_interval(personal[i].last_meal_time, &interval);
		pthread_mutex_unlock(&(personal[i].last_meal_time_mutex));
		if (interval > general -> time_to_die)
		{
			pthread_mutex_lock(general -> print);
			pthread_mutex_lock(general -> alive_mutex);
			*(general -> alive) = 0;
			pthread_mutex_unlock(general -> alive_mutex);
			printf("%08zu %zu died\n", current_time,
				personal[i].current_number + 1);
			return (1);
		}
		++i;
	}
	return (0);
}

static
int	check_satisfying(t_philo_data *personal, t_philo_data *general)
{
	size_t	i;

	if (general -> must_eat == 0)
		return (0);
	i = 0;
	while (i < general -> philosophers_number)
	{
		pthread_mutex_lock(&(personal[i].number_of_meals_mutex));
		if (personal[i].number_of_meals < general -> must_eat)
		{
			pthread_mutex_unlock(&(personal[i].number_of_meals_mutex));
			return (0);
		}
		pthread_mutex_unlock(&(personal[i].number_of_meals_mutex));
		++i;
	}
	pthread_mutex_lock(general -> print);
	pthread_mutex_lock(general -> alive_mutex);
	*(general -> alive) = 0;
	pthread_mutex_unlock(general -> alive_mutex);
	printf("Philosophers are replete with spaghetti\n");
	return (1);
}

void	life_monitoring(t_philo_data *general, t_philo_data *personal)
{
	while (!check_alive(general))
	{
		if (check_living(personal, general))
			break ;
		if (check_satisfying(personal, general))
			break ;
	}
}
