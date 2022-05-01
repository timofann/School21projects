/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:06 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
int	set_empty_philosophers(pthread_t **threads, size_t philosophers_number)
{
	*threads = (pthread_t *)
		malloc(sizeof(pthread_t) * philosophers_number);
	if (!(*threads))
		return (error(MEMORY_ERROR));
	return (0);
}

static
void	finish_dinner(t_philo_data *general, pthread_t *philosophers)
{
	size_t			i;

	i = 0;
	while (i < general -> philosophers_number)
	{
		pthread_detach(philosophers[i]);
		i++;
	}
}

/*
 * 	Dinning philosophers.
 */

int	main(int argc, char **argv)
{
	t_philo_data	general;
	t_philo_data	*personal;
	pthread_t		*philosophers;

	if (set_general(&general, argc, argv))
		return (1);
	if (set_empty_philosophers(&philosophers,
			general.philosophers_number))
		return (1);
	if (set_personal(&personal, &general))
		return (1);
	if (start_dinner(personal, &general, philosophers))
		return (1);
	life_monitoring(&general, personal);
	finish_dinner(&general, philosophers);
	return (0);
}
