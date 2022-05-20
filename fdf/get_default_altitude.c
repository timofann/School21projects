/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default_altitude.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:29:19 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:30:21 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

static
int	parse_default_altitude(char *arg)
{
	int	altitude;
	int	sign;

	sign = get_sign(&arg);
	altitude = 0;
	if (*arg >= '1' && *arg <= '9')
	{
		while (*arg >= '0' && *arg <= '9')
		{
			if (long_type_is_needed(altitude, sign, *arg))
				put_error(INVALID_ALTITUDE);
			altitude = altitude * 10 + sign * (*arg - '0');
			arg++;
		}
	}
	if (*arg == '0')
		arg++;
	if (*arg != '\0')
		put_error(INVALID_ALTITUDE);
	return (altitude);
}

int	get_default_altitude(int argc, char **argv)
{
	int	default_altitude;

	default_altitude = 0;
	if (argc == 3)
		default_altitude = parse_default_altitude(argv[2]);
	return (default_altitude);
}
