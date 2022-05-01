/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_scenario.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:56:54 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:57:00 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static
void	take_one_fork(t_philo_data *data)
{
	sem_wait(data -> forks_sem);
}

static
void	put_one_fork(t_philo_data *data)
{
	sem_post(data -> forks_sem);
}

void	philo_scenario(t_philo_data *data)
{
	take_one_fork(data);
	mprintf("%08zu %zu has taken a fork\n", data);
	take_one_fork(data);
	mprintf("%08zu %zu has taken a fork\n", data);
	philo_eat(data);
	put_one_fork(data);
	put_one_fork(data);
	philo_sleep(data);
	philo_think(data);
}
