/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:28:36 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:28:38 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	put_vertex_isometric(t_image *img, t_vertex *vertex, t_drawable *model)
{
	int	x;
	int	y;
	int	color;

	x = (vertex -> x + model -> x_centering_factor) * model -> zoom + X_CENTER;
	y = (vertex -> z + model -> centering_factor) * model -> zoom + Y_CENTER;
	color = DEFAULT_COLOR;
	if (model -> color_mode)
		color = vertex -> color;
	put_pixel(img, x, y, color);
}

static
void	put_vertexes_isometric(t_image *img, t_drawable *model)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < model -> map -> height)
	{
		j = 0;
		while (j < model -> map -> width)
		{
			put_vertex_isometric(img, &((model -> map -> table)[i][j]), model);
			j++;
		}
		i++;
	}
}

static
void	put_vertex_perspective(
		t_image *img, t_vertex *vertex, t_drawable *model)
{
	int	x;
	int	y;
	int	color;

	x = (vertex -> x + model -> x_centering_factor)
		* 500 / model -> map -> width
		* powf(model -> zoom * 500 / model -> map -> width,
			vertex -> y / 1000) + X_CENTER;
	y = (vertex -> z + model -> centering_factor)
		* 500 / model -> map -> width
		* powf(model -> zoom * 500 / model -> map -> width,
			vertex -> y / 1000) + Y_CENTER;
	color = DEFAULT_COLOR;
	if (model -> color_mode)
		color = vertex -> color;
	put_pixel(img, x, y, color);
}

static
void	put_vertexes_perspective(t_image *img, t_drawable *model)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < model -> map -> height)
	{
		j = 0;
		while (j < model -> map -> width)
		{
			put_vertex_perspective(
				img, &((model -> map -> table)[i][j]), model);
			j++;
		}
		i++;
	}
}

void	draw_state(t_mlx *workspace, t_image *img, t_drawable *model)
{
	clear_window(img);
	if (model -> vertex_mode && model -> perspective_mode)
		put_vertexes_perspective(img, model);
	else if (model -> vertex_mode)
		put_vertexes_isometric(img, model);
	else if (model -> perspective_mode)
		put_edges_perspective(img, model);
	else
		put_edges_isometric(img, model);
	if (model -> enable_axes)
		put_axes(img, model);
	mlx_put_image_to_window(workspace->mlx, workspace->win, img->img_ptr, 0, 0);
	if (model -> enable_info)
		put_info(workspace, model);
}
