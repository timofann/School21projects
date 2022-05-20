/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_axes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:31:25 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:31:27 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_x_axis(t_image *img, t_drawable *model)
{
	t_edge	edge;

	edge.x1 = (model -> map -> width) * model -> zoom / -2 + X_CENTER;
	edge.y1 = Y_CENTER;
	edge.color1 = RED;
	edge.x2 = (model -> map -> width) * model -> zoom / 2 + X_CENTER;
	edge.y2 = Y_CENTER;
	edge.color2 = RED;
	put_edge(img, &edge);
}

void	put_z_axis(t_image *img, t_drawable *model)
{
	t_edge	edge;

	edge.x1 = X_CENTER;
	edge.y1 = (model -> map -> altitude) * model -> zoom / -2 + Y_CENTER;
	edge.color1 = BLUE;
	edge.x2 = X_CENTER;
	edge.y2 = (model -> map -> altitude) * model -> zoom / 2 + Y_CENTER;
	edge.color2 = BLUE;
	put_edge(img, &edge);
}

void	put_axes(t_image *img, t_drawable *model)
{
	put_x_axis(img, model);
	put_z_axis(img, model);
}
