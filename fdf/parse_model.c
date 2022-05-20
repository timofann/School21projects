/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:31:12 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:31:14 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

static
int	str_compare(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		++str1;
		++str2;
	}
	return (*str1 - *str2);
}

static
void	check_file_extension(char *filename)
{
	size_t	i;
	size_t	last_dot;

	i = 0;
	last_dot = 0;
	while (filename[i] != '\0')
	{
		while (filename[i] != '\0' && filename[i] != '.')
			i++;
		if (filename[i] == '.')
			last_dot = i++;
	}
	if (last_dot == 0 || str_compare(&filename[last_dot], ".fdf") != 0)
		put_error(INVALID_EXTENSION);
}

static
int	get_max_altitude(t_map *map)
{
	int		max_altitude;
	size_t	x;
	size_t	y;

	max_altitude = (map -> table)[0][0].z;
	y = 0;
	while (y < map -> height)
	{
		x = 0;
		while (x < map -> width)
		{
			if ((map -> table)[y][x].z > max_altitude)
				max_altitude = (map -> table)[y][x].z;
			x++;
		}
		y++;
	}
	return (max_altitude);
}

static
int	get_min_altitude(t_map *map)
{
	int		min_altitude;
	size_t	x;
	size_t	y;

	min_altitude = (map -> table)[0][0].z;
	y = 0;
	while (y < map -> height)
	{
		x = 0;
		while (x < map -> width)
		{
			if ((map -> table)[y][x].z < min_altitude)
				min_altitude = (map -> table)[y][x].z;
			x++;
		}
		y++;
	}
	return (min_altitude);
}

void	parse_model(int argc, char **argv, t_drawable *model)
{
	float	default_altitude;
	float	max_altitude;
	float	min_altitude;

	if (argc != 2 && argc != 3)
		put_error(INVALID_ARG_COUNT);
	check_file_extension(argv[1]);
	set_empty_map(argv[1], &(model -> map));
	default_altitude = get_default_altitude(argc, argv);
	put_message(WAIT_MESSAGE);
	fill_map(argv[1], model -> map);
	put_message(SUCCESSFUL_PARSING);
	max_altitude = get_max_altitude(model -> map);
	min_altitude = get_min_altitude(model -> map);
	model -> def_centering_factor = 0 - (max_altitude + min_altitude) / 2;
	max_altitude = max_altitude + model -> def_centering_factor;
	if (default_altitude == 0 || max_altitude == 0)
		model -> perversion_factor = 1;
	else
		model -> perversion_factor = default_altitude / max_altitude;
	model -> map -> altitude = 2 * max_altitude
		* model -> perversion_factor + 1;
}
