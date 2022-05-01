/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:02:08 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:02:10 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_sleep(t_philo_data *data)
{
	mprintf("%08zu %zu is sleeping\n", data);
	msleep(data -> time_to_sleep);
	return (check_alive(data));
}
