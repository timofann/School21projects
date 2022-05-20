/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_edges_isometric.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:31:41 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:31:43 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	count_first_vertex(t_edge *edge, t_drawable *model, size_t i, size_t j)
{
	edge -> x1 = ((model -> map -> table)[i][j].x + model -> x_centering_factor)
		* model -> zoom + X_CENTER;
	edge -> y1 = ((model -> map -> table)[i][j].z + model -> centering_factor)
		* model -> zoom + Y_CENTER;
	edge -> color1 = DEFAULT_COLOR;
	if (model -> color_mode)
		edge -> color1 = (model -> map -> table)[i][j].color;
}

static
void	count_second_vertex(t_edge *edge, t_drawable *model, size_t i, size_t j)
{
	edge -> x2 = ((model->map->table)[i][j].x + model -> x_centering_factor)
		* model -> zoom + X_CENTER;
	edge -> y2 = ((model->map->table)[i][j].z + model -> centering_factor)
		* model -> zoom + Y_CENTER;
	edge -> color2 = DEFAULT_COLOR;
	if (model -> color_mode)
		edge -> color2 = (model->map->table)[i][j].color;
}

static
void	put_related_edges_isometric(
		t_image *img, t_drawable *model, size_t i, size_t j)
{
	t_edge	edge;

	count_first_vertex(&edge, model, i, j);
	if (i != model -> map -> height - 1)
	{
		count_second_vertex(&edge, model, i + 1, j);
		put_edge(img, &edge);
	}
	if (j != model -> map -> width - 1)
	{
		count_second_vertex(&edge, model, i, j + 1);
		put_edge(img, &edge);
	}
}

void	put_edges_isometric(t_image *img, t_drawable *model)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < model -> map -> height)
	{
		j = 0;
		while (j < model -> map -> width)
		{
			put_related_edges_isometric(img, model, i, j);
			j++;
		}
		i++;
	}
}
