/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:01:06 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:01:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static
void	set_empty_philosophers(pid_t **philosophers, size_t philosophers_number)
{
	*philosophers = (pid_t *)
		malloc(sizeof(pid_t) * philosophers_number);
	if (!(*philosophers))
		put_error(MEMORY_ERROR);
}

static
void	enable_print_semaphore(t_philo_data *general)
{
	if (sem_open("print_sem", O_EXCL) != SEM_FAILED)
		put_error(SEMAPHORE_ALREADY_EXISTS);
	else if (errno != ENOENT)
		put_error(SEMAPHORES_LIMIT_OR_MEMORY_LACK);
	if (sem_open("print_sem", O_CREAT, 0644, 1) == SEM_FAILED)
		put_error(SEMAPHORES_LIMIT_OR_MEMORY_LACK);
	general -> print_sem = sem_open("print_sem", O_CREAT, 0644, 1);
}

static
void	enable_forks_semaphore(t_philo_data *general)
{
	size_t	n;

	n = general -> philosophers_number;
	if (sem_open("forks_sem", O_EXCL) != SEM_FAILED)
	{
		sem_unlink("print_sem");
		put_error(SEMAPHORE_ALREADY_EXISTS);
	}
	else if (errno != ENOENT)
	{
		sem_unlink("print_sem");
		put_error(SEMAPHORES_LIMIT_OR_MEMORY_LACK);
	}
	if (sem_open("forks_sem", O_CREAT, 0644, n) == SEM_FAILED)
	{
		sem_unlink("print_sem");
		put_error(SEMAPHORES_LIMIT_OR_MEMORY_LACK);
	}
	general -> forks_sem = sem_open("forks_sem", O_CREAT, 0644, n);
}

static
void	finish_dinner(t_philo_data *general, pid_t *philosophers)
{
	int		exit_status;
	size_t	i;

	waitpid(-1, &exit_status, WUNTRACED);
	i = 1;
	while (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) == 0
		&& i++ < general -> philosophers_number)
		waitpid(-1, &exit_status, WUNTRACED);
	kill_philosophers(philosophers, general -> philosophers_number);
	if (WIFEXITED(exit_status) && WEXITSTATUS(exit_status) == 0)
	{
		sem_wait(general -> print_sem);
		printf("Philosophers are replete with spaghetti\n");
	}
	sem_unlink("print_sem");
	sem_unlink("forks_sem");
}

/*
 * 	Dinning philosophers.
 */

int	main(int argc, char **argv)
{
	t_philo_data	general;
	pid_t			*philosophers;

	set_general(&general, argc, argv);
	set_empty_philosophers(&philosophers, general.philosophers_number);
	init_sighandler(philosophers, general.philosophers_number);
	enable_print_semaphore(&general);
	enable_forks_semaphore(&general);
	start_dinner(&general, philosophers);
	finish_dinner(&general, philosophers);
	return (0);
}
