/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:03:26 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:03:28 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
void	*odd_philosopher(void *ptr)
{
	t_philo_data	*data;

	data = (t_philo_data *)ptr;
	if (philo_think(data))
		return (NULL);
	while (!philo_scenario(data))
		;
	return (NULL);
}

static
void	*even_philosopher(void *ptr)
{
	t_philo_data	*data;

	data = (t_philo_data *)ptr;
	if (philo_think(data))
		return (NULL);
	msleep(10);
	while (!philo_scenario(data))
		;
	return (NULL);
}

/*
 * 	Classic approach is to create odd and even philosophers
 * 	who should start dinner faster and who should wait until his
 * 	neighbours finish their meals.
 */

int	start_dinner(t_philo_data *personal, t_philo_data *general,
	pthread_t *philosophers)
{
	size_t	i;

	if (general -> philosophers_number == 1)
		if (pthread_mutex_lock(general -> forks))
			return (error(ACCESS_TO_MUTEX));
	i = 0;
	while (i < general -> philosophers_number)
	{
		if (pthread_create(&(philosophers[i]),
				NULL, odd_philosopher, &(personal[i])))
			return (error(MAX_THREADS));
		i += 2;
	}
	i = 1;
	while (i < general -> philosophers_number)
	{
		if (pthread_create(&(philosophers[i]),
				NULL, even_philosopher, &(personal[i])))
			return (error(MAX_THREADS));
		i += 2;
	}
	return (0);
}
