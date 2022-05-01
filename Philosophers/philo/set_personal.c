/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_personal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:03:07 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:03:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_personal(t_philo_data **personal, t_philo_data *general)
{
	size_t	i;

	*personal = (t_philo_data *)
		malloc(sizeof(t_philo_data) * general -> philosophers_number);
	if (!(*personal))
		return (error(MEMORY_ERROR));
	i = 0;
	while (i < general -> philosophers_number)
	{
		(*personal)[i] = *general;
		(*personal)[i].current_number = i;
		(*personal)[i].left_fork = i;
		(*personal)[i].right_fork = (i + 1) % general -> philosophers_number;
		if (pthread_mutex_init(&((*personal)[i].last_meal_time_mutex), NULL))
			return (error(MEMORY_ERROR));
		if (pthread_mutex_init(&((*personal)[i].number_of_meals_mutex), NULL))
			return (error(MEMORY_ERROR));
		++i;
	}
	return (0);
}
