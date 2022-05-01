/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:27 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:30 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	msleep(size_t time)
{
	size_t	start;
	size_t	new_time;

	set_current_time(&start);
	set_current_time(&new_time);
	while (new_time - start < time)
	{
		usleep(1000);
		set_current_time(&new_time);
	}
}
