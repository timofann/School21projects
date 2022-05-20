/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_type_is_needed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:30:50 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:30:51 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

int	long_type_is_needed(int altitude, int sign, char next_char)
{
	if (altitude > MAX_INT / 10
		|| (altitude == MAX_INT / 10
			&& sign * (next_char - '0') > MAX_INT % 10))
		return (1);
	if (altitude < MIN_INT / 10
		|| (altitude == MIN_INT / 10
			&& sign * (next_char - '0') < MIN_INT % 10))
		return (1);
	return (0);
}
