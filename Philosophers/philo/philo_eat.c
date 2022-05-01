/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:42 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:44 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo_data *data)
{
	pthread_mutex_lock(&(data -> last_meal_time_mutex));
	set_current_time(&(data -> last_meal_time));
	pthread_mutex_unlock(&(data -> last_meal_time_mutex));
	mprintf("%08zu %zu is eating\n", data);
	msleep(data -> time_to_eat);
	pthread_mutex_lock(&(data -> number_of_meals_mutex));
	data -> number_of_meals++;
	pthread_mutex_unlock(&(data -> number_of_meals_mutex));
	return (check_alive(data));
}
