/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:56:04 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:56:06 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_philosophers(pid_t *pid_array, size_t pid_count)
{
	size_t	i;

	i = 0;
	while (i < pid_count)
	{
		kill(pid_array[i], SIGINT);
		++i;
	}
}
