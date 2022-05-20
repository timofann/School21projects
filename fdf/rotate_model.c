/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_model.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:01 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	rotate_vertex_x(t_vertex *vertex, int angle)
{
	float	rad;

	rad = M_PI * (float)angle / 180;
	vertex -> x = 1 * vertex -> x + 0 * vertex -> y + 0 * vertex -> z;
	vertex -> y = cosf(rad) * vertex -> y - sinf(rad) * vertex -> z;
	vertex -> z = sinf(rad) * vertex -> y + cosf(rad) * vertex -> z;
}

static
void	rotate_vertex_y(t_vertex *vertex, int angle)
{
	float	rad;

	rad = M_PI * (float)angle / 180;
	vertex -> x = cosf(rad) * vertex -> x + sinf(rad) * vertex -> z;
	vertex -> y = 0 * vertex -> x + 1 * vertex -> y + 0 * vertex -> z;
	vertex -> z = -sinf(rad) * vertex -> x + cosf(rad) * vertex -> z;
}

static
void	rotate_vertex_z(t_vertex *vertex, int angle)
{
	float	rad;

	rad = M_PI * (float)angle / 180;
	vertex -> x = cosf(rad) * vertex -> x - sinf(rad) * vertex -> y;
	vertex -> y = sinf(rad) * vertex -> x + cosf(rad) * vertex -> y;
	vertex -> z = 0 * vertex -> x + 0 * vertex -> y + 1 * vertex -> z;
}

void	rotate_model(t_map *map, int x_angle, int y_angle, int z_angle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map -> height)
	{
		j = 0;
		while (j < map -> width)
		{
			rotate_vertex_y(&((map -> table)[i][j]), y_angle);
			rotate_vertex_z(&((map -> table)[i][j]), z_angle);
			rotate_vertex_x(&((map -> table)[i][j]), x_angle);
			j++;
		}
		i++;
	}
}
