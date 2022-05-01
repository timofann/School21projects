/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:02:40 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:02:43 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static
int	longer_type_is_required(size_t new_int, char arg)
{
	if (new_int > SIZE_MAX / 10 || (new_int == SIZE_MAX / 10
			&& (arg - '0') > (char)(SIZE_MAX % 10)))
		return (1);
	return (0);
}

/*
 * 	Put numeric value of the unsigned integer no more
 * 	than SIZE_MAX from <stdlib.h> on the passed poiter.
 * 	Any additional symbols including '+' and '-' cause
 * 	errors.
 */

static
int	set_uint(char *arg, size_t *new_uint)
{
	*new_uint = 0;
	if (*arg == '\0')
		return (1);
	if (*arg >= '1' && *arg <= '9')
	{
		while (*arg >= '0' && *arg <= '9')
		{
			if (longer_type_is_required(*new_uint, *arg))
				return (1);
			*new_uint = *new_uint * 10 + (*arg - '0');
			arg++;
		}
	}
	if (*arg == '0')
		arg++;
	if (*arg)
		return (1);
	return (0);
}

static
int	confirm_philosophers_number(size_t number)
{
	char	c;

	if (number > 200)
	{
		printf("Are you sure you want to create %zu philosophers? [y]\n"
			"Beware! They are dangerous for your computer.\n", number);
		read(1, &c, 1);
		if (c != 'y')
			return (1);
	}
	return (0);
}

/*
 * 	The program should take the following arguments:
 * 	<number_of_philosophers> ;
 * 	<time_to_die> ;
 * 	<time_to_eat> ;
 * 	<time_to_sleep> ;
 * 	[ number_of_times_each_philosopher_must_eat ] .
 */

/*
 * 	Function exit() and raising/catching errors are
 * 	forbidden for that part of project.
 */

int	set_arguments(t_philo_data *data, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (error(INVALID_ARG_COUNT));
	if (set_uint(argv[1], &(data -> philosophers_number)))
		return (error(INVALID_NUMERIC_DATA));
	if (confirm_philosophers_number(data -> philosophers_number))
		return (error(AMOUNT_OF_PHILOSOPHERS));
	if (set_uint(argv[2], &(data -> time_to_die)))
		return (error(INVALID_NUMERIC_DATA));
	if (set_uint(argv[3], &(data -> time_to_eat)))
		return (error(INVALID_NUMERIC_DATA));
	if (set_uint(argv[4], &(data -> time_to_sleep)))
		return (error(INVALID_NUMERIC_DATA));
	data -> must_eat = 0;
	if (argc == 6)
	{
		if (set_uint(argv[5], &(data -> must_eat)))
			return (error(INVALID_NUMERIC_DATA));
		if (data -> must_eat == 0)
			return (error(LEAVE_EMPTY_FIELD));
	}
	return (0);
}
