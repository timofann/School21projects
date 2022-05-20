/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks_for_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:35 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:37 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	key_move_pervers(int keycode, t_drawable *model)
{
	if (keycode == KEY_W)
		model -> centering_factor -= 1;
	else if (keycode == KEY_S)
		model -> centering_factor += 1;
	else if (keycode == KEY_D)
		model -> x_centering_factor += 1;
	else if (keycode == KEY_A)
		model -> x_centering_factor -= 1;
	else if (keycode == KEY_RIGHT_SQ_BRACKET)
	{
		if (model -> perversion_factor < 1000)
		{
			model -> perversion_factor *= 1.2;
			apply_perversion(model, 1.2);
		}
	}
	else if (keycode == KEY_LEFT_SQ_BRACKET)
	{
		if (model -> perversion_factor > 0.000001)
		{
			model -> perversion_factor /= 1.2;
			apply_perversion(model, (float)1 / 1.2);
		}
	}
}

static
void	key_rotate(int keycode, t_drawable *model)
{
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_RIGHT
		|| keycode == KEY_LEFT || keycode == KEY_LESS || keycode == KEY_MORE)
		model -> color_mode = 0;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		model -> x_angle += (keycode == KEY_DOWN) * 2 - 1;
		model -> x_angle = (model-> x_angle < 0) * 360 + model-> x_angle % 360;
		rotate_model(model -> map,
			(keycode == KEY_DOWN) * 2 - 1, 0, 0);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		model -> z_angle += (keycode == KEY_LEFT) * 2 - 1;
		model -> z_angle = (model-> z_angle < 0) * 360 + model-> z_angle % 360;
		rotate_model(model -> map,
			0, 0, (keycode == KEY_LEFT) * 2 - 1);
	}
	else if (keycode == KEY_LESS || keycode == KEY_MORE)
	{
		model -> y_angle += (keycode == KEY_LESS) * 2 - 1;
		model -> y_angle = (model-> y_angle < 0) * 360 + model-> y_angle % 360;
		rotate_model(model -> map,
			0, (keycode == KEY_LESS) * 2 - 1, 0);
	}
}

static
void	key_xcvpizoom(int keycode, t_drawable *model)
{
	if (keycode == KEY_PLUS)
	{
		if (model -> zoom < 83333.325)
			model -> zoom = model -> zoom * 1.2;
	}
	else if (keycode == KEY_MINUS)
	{
		if (model -> zoom > 0.00001)
			model -> zoom = model -> zoom / 1.2;
	}
	else if (keycode == KEY_X)
		model -> enable_axes = (model -> enable_axes == 0);
	else if (keycode == KEY_C)
		model -> color_mode = (model -> color_mode == 0);
	else if (keycode == KEY_V)
		model -> vertex_mode = (model -> vertex_mode == 0);
	else if (keycode == KEY_P)
		model -> perspective_mode = (model -> perspective_mode == 0);
	else if (keycode == KEY_I)
		model -> enable_info = (model -> enable_info == 0);
}

static
int	key_action(int keycode, t_drawable *model)
{
	key_move_pervers(keycode, model);
	key_rotate(keycode, model);
	key_xcvpizoom(keycode, model);
	return (0);
}

void	set_hooks_for_drawing(t_mlx *workspace, t_drawable *model)
{
	mlx_hook(workspace -> win, 2, 1L << 0, key_action, model);
}
