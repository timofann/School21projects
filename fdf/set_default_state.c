/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:15 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:17 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default_state(t_drawable *model)
{
	size_t	i;

	model -> x_angle = DEFAULT_X_ANGLE;
	model -> y_angle = DEFAULT_Y_ANGLE;
	model -> z_angle = DEFAULT_Z_ANGLE;
	i = 0;
	while (i++ < DEFAULT_Z_ANGLE)
		rotate_model(model -> map, 0, 0, 1);
	i = 0;
	while (i++ < DEFAULT_X_ANGLE)
		rotate_model(model -> map, 1, 0, 0);
	model -> zoom = get_default_zoom(model);
	model -> enable_axes = 0;
	model -> centering_factor = 0;
	model -> x_centering_factor = 0;
	model -> vertex_mode = 0;
	model -> color_mode = 0;
	model -> perspective_mode = 0;
	model -> enable_info = 1;
}
