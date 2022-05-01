/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_scenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:55 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:58 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
int	put_left_fork(t_philo_data *data)
{
	if (pthread_mutex_unlock(&(data -> forks)[data -> left_fork]))
		return (error(NOT_MY_FORK));
	return (check_alive(data));
}

static
int	put_right_fork(t_philo_data *data)
{
	if (pthread_mutex_unlock(&(data -> forks)[data -> right_fork]))
		return (error(NOT_MY_FORK));
	return (check_alive(data));
}

static
int	take_left_fork(t_philo_data *data)
{
	if (pthread_mutex_lock(&((data -> forks)[data -> left_fork])))
		return (error(ACCESS_TO_MUTEX));
	mprintf("%08zu %zu has taken a fork\n", data);
	return (check_alive(data));
}

static
int	take_right_fork(t_philo_data *data)
{
	if (pthread_mutex_lock(&((data -> forks)[data -> right_fork])))
		return (error(ACCESS_TO_MUTEX));
	mprintf("%08zu %zu has taken a fork\n", data);
	return (check_alive(data));
}

int	philo_scenario(t_philo_data *data)
{
	if (take_left_fork(data))
		return (1);
	if (take_right_fork(data))
		return (1);
	if (philo_eat(data))
		return (1);
	if (put_right_fork(data))
		return (1);
	if (put_left_fork(data))
		return (1);
	if (philo_sleep(data))
		return (1);
	if (philo_think(data))
		return (1);
	return (0);
}
