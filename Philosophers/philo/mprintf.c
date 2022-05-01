/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:19 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:21 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mprintf(char *mess, t_philo_data *data)
{
	size_t	time;

	pthread_mutex_lock(data -> print);
	set_time_interval(data -> start_time, &time);
	printf(mess, time, data -> current_number + 1);
	pthread_mutex_unlock(data -> print);
}
