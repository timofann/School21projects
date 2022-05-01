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

#include "philo_bonus.h"

void	mprintf(char *mess, t_philo_data *data)
{
	size_t	time;

	sem_wait(data -> print_sem);
	set_time_interval(data -> start_time, &time);
	printf(mess, time, data -> current_number + 1);
	sem_post(data -> print_sem);
}
