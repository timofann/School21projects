/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_altitude.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:29:46 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:29:48 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

int	get_next_altitude(char **line)
{
	int	altitude;
	int	sign;

	while (**line == ' ')
		(*line)++;
	sign = get_sign(line);
	altitude = 0;
	if (**line >= '1' && **line <= '9')
	{
		while (**line >= '0' && **line <= '9')
		{
			if (long_type_is_needed(altitude, sign, **line))
				put_error(INVALID_NUMERIC_DATA);
			altitude = altitude * 10 + sign * (**line - '0');
			(*line)++;
		}
	}
	if (**line == '0')
		(*line)++;
	if (**line != '\0' && **line != '\n' && **line != ' ' && **line != ',')
		put_error(INVALID_NUMERIC_DATA);
	return (altitude);
}
