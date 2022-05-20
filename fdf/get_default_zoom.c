/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:29:27 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:29:30 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
float	get_x_size(t_map *map, float zoom)
{
	size_t	i;
	size_t	j;
	float	max_x;
	float	min_x;

	max_x = (map -> table)[0][0].x * zoom;
	min_x = max_x;
	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if ((map -> table)[i][j].x * zoom > max_x)
				max_x = (map -> table)[i][j].x * zoom;
			if ((map -> table)[i][j].x * zoom < min_x)
				min_x = (map -> table)[i][j].x * zoom;
			j++;
		}
		i++;
	}
	return (max_x - min_x);
}

static
float	get_y_size(t_map *map, float zoom)
{
	size_t	i;
	size_t	j;
	float	max_y;
	float	min_y;

	max_y = (map -> table)[0][0].z * zoom;
	min_y = max_y;
	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			if ((map -> table)[i][j].z * zoom > max_y)
				max_y = (map -> table)[i][j].z * zoom;
			if ((map -> table)[i][j].z * zoom < min_y)
				min_y = (map -> table)[i][j].z * zoom;
			j++;
		}
		i++;
	}
	return (max_y - min_y);
}

float	get_default_zoom(t_drawable *model)
{
	float	linear_size;
	float	zoom;

	zoom = 10;
	linear_size = get_x_size(model -> map, zoom);
	while (linear_size < NICE_WIDTH / 2.0736)
	{
		zoom = zoom * 1.2;
		linear_size = get_x_size(model -> map, zoom);
	}
	while (linear_size > NICE_WIDTH)
	{
		zoom = zoom / 1.2;
		linear_size = get_x_size(model -> map, zoom);
	}
	linear_size = get_y_size(model -> map, zoom);
	while (linear_size > NICE_HEIGHT)
	{
		zoom = zoom / 1.2;
		linear_size = get_y_size(model -> map, zoom);
	}
	return (zoom);
}
