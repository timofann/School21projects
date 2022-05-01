/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:02:51 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:02:54 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_current_time(size_t *time_mlsec)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	*time_mlsec = current.tv_sec % 100000 * 1000 + current.tv_usec / 1000;
}
