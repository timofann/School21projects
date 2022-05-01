/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sighandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:55:48 by dedelmir          #+#    #+#             */
/*   Updated: 2022/04/25 16:55:52 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static
void	save_info_then_kill(pid_t *pid_array, size_t pid_count)
{
	static pid_t	*philosophers;
	static size_t	philosophers_number;

	if (pid_array)
	{
		philosophers = pid_array;
		philosophers_number = pid_count;
		return ;
	}
	else
	{
		sem_unlink("print_sem");
		sem_unlink("forks_sem");
		kill_philosophers(philosophers, philosophers_number);
		exit(1);
	}
}

static
void	sighandler(int sig)
{
	(void)sig;
	save_info_then_kill(NULL, 0);
}

void	init_sighandler(pid_t *pid_array, size_t pid_count)
{
	save_info_then_kill(pid_array, pid_count);
	signal(SIGINT, sighandler);
}
