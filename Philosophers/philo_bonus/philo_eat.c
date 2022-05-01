/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:56:40 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:56:42 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo_data *data)
{
	if (pthread_mutex_lock(&(data -> last_meal_time_mutex)))
		put_error(ACCESS_TO_MUTEX);
	set_current_time(&(data -> last_meal_time));
	if (pthread_mutex_unlock(&(data -> last_meal_time_mutex)))
		put_error(MUTEX_UNLOCK_ACCESS);
	mprintf("%08zu %zu is eating\n", data);
	msleep(data -> time_to_eat);
	if (pthread_mutex_lock(&(data -> number_of_meals_mutex)))
		put_error(ACCESS_TO_MUTEX);
	++(data -> number_of_meals);
	if (pthread_mutex_unlock(&(data -> number_of_meals_mutex)))
		put_error(MUTEX_UNLOCK_ACCESS);
}
