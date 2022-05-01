/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_general.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:03:00 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/24 18:03:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/*
 * 	General information is similar for all the dinning
 * 	philosophers. It would be used while creating separate
 * 	personal structures for every philosopher so that they
 * 	could address only their own memory space.
 */

void	set_general(t_philo_data *general, int argc, char **argv)
{
	set_arguments(general, argc, argv);
	set_current_time(&(general -> start_time));
	general -> last_meal_time = general -> start_time;
	general -> number_of_meals = 0;
}
