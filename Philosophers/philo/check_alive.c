/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:11:08 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/26 23:11:11 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo_data *data)
{
	pthread_mutex_lock(data -> alive_mutex);
	if (*(data -> alive) == 1)
	{
		pthread_mutex_unlock(data -> alive_mutex);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(data -> alive_mutex);
		return (1);
	}
}
