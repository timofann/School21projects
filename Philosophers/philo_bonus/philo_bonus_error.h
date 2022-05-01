/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:04:40 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:04:42 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_ERROR_H
# define PHILO_BONUS_ERROR_H

# include <stdlib.h>
# include <unistd.h>

# define INVALID_NUMERIC_DATA "\
List of arguments contains non-unsigned-integer values.\n\
Usage : ./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [ number_of_times_each_philosopher_must_eat ]"
# define INVALID_ARG_COUNT "\
Invalid amount of arguments.\n\
Usage : ./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [ number_of_times_each_philosopher_must_eat ]"
# define TOO_MANY_PHILOSPHERS "\
<number_of_philosophers> can't be equal or more than INT32_MAX."
# define AMOUNT_OF_PHILOSOPHERS "\
If you really want to create more then 400 philosophers \
you should confirm your choice by enter [y]. Try one more time."
# define LEAVE_EMPTY_FIELD "\
If you want to set optional argument as zero no needs to set it at all.\n\
Zero means you don't want to set borders for satiety."
# define MEMORY_ERROR "\
Can't allocate memory. Probably there is a problem with available space."
# define MAX_PROCESSES "\
The MAXUPRC value is reached. Can't create more processes."
# define ACCESS_TO_MUTEX "\
Deadlock! Deadlock! Deadlock! Additional thread for life monitoring is going to \
destroy the program or philosophers"
# define MUTEX_UNLOCK_ACCESS "\
Thread has no permissions to unlock mutex. Probably program can't support \
monitorig of life for one of the philosophers"
# define NOT_MY_FORK "\
Philosopher is going to put on the table the fork but \
there is no fork in his hand."
# define SEMAPHORE_ALREADY_EXISTS "\
One of the semaphores you try to create \
has the name of the existing semaphore."
# define SEMAPHORES_LIMIT_OR_MEMORY_LACK "\
There are too many semaphores or file descriptors in use or your disk is full.\n\
Can't create new semaphore"
# define MAX_THREADS "\
The MAX_THREADS value is reached. Can't create more threads."

void	put_error(char *str);

#endif
