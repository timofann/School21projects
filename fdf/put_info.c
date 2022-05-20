/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:10 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:32:12 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	put_standard_info(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 30, 60, DEFAULT_COLOR,
		" zoom (keys + / -) : -------------- ");
	mlx_string_put(mlx, win, 30, 80, DEFAULT_COLOR,
		" x-rotation (up / down arrows) : -- ");
	mlx_string_put(mlx, win, 30, 100, DEFAULT_COLOR,
		" y-rotation (keys < / >) : -------- ");
	mlx_string_put(mlx, win, 30, 120, DEFAULT_COLOR,
		" z-rotation (left / right arrows) : ");
	mlx_string_put(mlx, win, 30, 140, DEFAULT_COLOR,
		" perversion (keys [ / ]) : -------- ");
	mlx_string_put(mlx, win, 30, 160, DEFAULT_COLOR,
		" x-shift (keys A / D) : ----------- ");
	mlx_string_put(mlx, win, 30, 180, DEFAULT_COLOR,
		" z-shift (keys W / S) : ----------- ");
	mlx_string_put(mlx, win, 30, 240, DEFAULT_COLOR,
		" perspective (key P) : ------------ ");
	mlx_string_put(mlx, win, 30, 200, DEFAULT_COLOR,
		" vertex (key V) : ----------------- ");
	mlx_string_put(mlx, win, 30, 220, DEFAULT_COLOR,
		" color (key C) : ------------------ ");
	mlx_string_put(mlx, win, 30, 260, DEFAULT_COLOR,
		" axes (key X) : ------------------- ");
	mlx_string_put(mlx, win, 30, 280, DEFAULT_COLOR,
		" info (key I) : ------------------- ");
}

static
void	put_binary_values(void *mlx, void *win, t_drawable *model)
{
	if (model -> perspective_mode)
		mlx_string_put(mlx, win, 400, 200, DEFAULT_COLOR, "ON");
	else
		mlx_string_put(mlx, win, 400, 200, DEFAULT_COLOR, "OFF");
	if (model -> vertex_mode)
		mlx_string_put(mlx, win, 400, 220, DEFAULT_COLOR, "ON");
	else
		mlx_string_put(mlx, win, 400, 220, DEFAULT_COLOR, "OFF");
	if (model -> color_mode)
		mlx_string_put(mlx, win, 400, 240, DEFAULT_COLOR, "ON");
	else
		mlx_string_put(mlx, win, 400, 240, DEFAULT_COLOR, "OFF");
	if (model -> enable_axes)
		mlx_string_put(mlx, win, 400, 260, DEFAULT_COLOR, "ON");
	else
		mlx_string_put(mlx, win, 400, 260, DEFAULT_COLOR, "OFF");
	if (model -> enable_info)
		mlx_string_put(mlx, win, 400, 280, DEFAULT_COLOR, "ON");
	else
		mlx_string_put(mlx, win, 400, 280, DEFAULT_COLOR, "OFF");
}

static
void	put_numeric_values(void *mlx, void *win, t_drawable *model)
{
	char	a[10];

	mlx_string_put(mlx, win, 400, 60, DEFAULT_COLOR,
		float_to_string(model -> zoom * 10, a));
	mlx_string_put(mlx, win, 400, 80, DEFAULT_COLOR,
		float_to_string(model -> x_angle, a));
	mlx_string_put(mlx, win, 400, 100, DEFAULT_COLOR,
		float_to_string(model -> y_angle, a));
	mlx_string_put(mlx, win, 400, 120, DEFAULT_COLOR,
		float_to_string(model -> z_angle, a));
	mlx_string_put(mlx, win, 400, 140, DEFAULT_COLOR,
		float_to_string(model -> perversion_factor, a));
	mlx_string_put(mlx, win, 400, 160, DEFAULT_COLOR,
		float_to_string(model -> x_centering_factor, a));
	mlx_string_put(mlx, win, 400, 180, DEFAULT_COLOR,
		float_to_string(model -> centering_factor
			+ model -> def_centering_factor, a));
}

void	put_info(t_mlx *workspace, t_drawable *model)
{
	mlx_string_put(workspace -> mlx, workspace -> win,
		30, 40, DEFAULT_COLOR,
		"---- Information about current state ----");
	put_standard_info(workspace -> mlx, workspace -> win);
	put_binary_values(workspace -> mlx, workspace -> win, model);
	put_numeric_values(workspace -> mlx, workspace -> win, model);
}
