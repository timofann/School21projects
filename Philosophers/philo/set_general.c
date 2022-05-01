/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:03:00 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:03:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
int	set_forks(pthread_mutex_t **mutexes, size_t philosophers_number)
{
	size_t	i;

	*mutexes = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * philosophers_number);
	if (!(*mutexes))
		return (error(MEMORY_ERROR));
	i = 0;
	while (i < philosophers_number)
	{
		if (pthread_mutex_init(&((*mutexes)[i]), NULL))
			return (error(MEMORY_ERROR));
		i++;
	}
	return (0);
}

static
int	set_one_mutex(pthread_mutex_t **mutex)
{
	*mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!(*mutex))
		return (error(MEMORY_ERROR));
	if (pthread_mutex_init(*mutex, NULL))
		return (error(MEMORY_ERROR));
	return (0);
}

int	set_mutexes(t_philo_data *general)
{
	if (set_forks(&(general -> forks), general -> philosophers_number))
		return (1);
	if (set_one_mutex(&(general -> print)))
		return (1);
	if (set_one_mutex(&(general -> alive_mutex)))
		return (1);
	return (0);
}

/*
 * 	General information is similar for all the dinning
 * 	philosophers. It would be used while creating separate
 * 	personal structures for every philosopher so that they
 * 	could address only their own memory space.
 */

int	set_general(t_philo_data *general, int argc, char **argv)
{
	if (set_arguments(general, argc, argv))
		return (1);
	general -> alive = (int *)malloc(sizeof(int));
	if (!(general -> alive))
		return (error(MEMORY_ERROR));
	*(general -> alive) = 1;
	if (set_mutexes(general))
		return (1);
	set_current_time(&(general -> start_time));
	general -> number_of_meals = 0;
	general -> last_meal_time = general -> start_time;
	return (0);
}
