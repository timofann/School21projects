/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_edge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:31:33 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:31:35 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_xydata {
	int		xsize;
	int		ysize;
	double	xstep;
	double	ystep;
	double	x;
	double	y;
}	t_xydata;

typedef struct s_rgb_step {
	double	rstep;
	double	gstep;
	double	bstep;
	double	rstart;
	double	gstart;
	double	bstart;
}	t_rgb_step;

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	set_color_step(t_rgb_step *color_step, t_edge *edge, int m)
{
	color_step -> rstep
		= (((edge -> color2 & 0xff0000) >> 16)
			- ((edge -> color1 & 0xff0000) >> 16)) / (double)m;
	color_step -> gstep
		= (((edge -> color2 & 0xff00) >> 8)
			- ((edge -> color1 & 0xff00) >> 8)) / (double)m;
	color_step -> bstep
		= ((edge -> color2 & 0xff)
			- (edge -> color1 & 0xff)) / (double)m;
	color_step -> rstart = (edge -> color1 & 0xff0000) >> 16;
	color_step -> gstart = (edge -> color1 & 0xff00) >> 8;
	color_step -> bstart = edge -> color1 & 0xff;
}

int	get_color(int i, t_rgb_step *color_step)
{
	t_rgb	rgb;

	rgb.r = (int)(color_step -> rstart + color_step -> rstep * (double)i);
	rgb.g = (int)(color_step -> gstart + color_step -> gstep * (double)i);
	rgb.b = (int)(color_step -> bstart + color_step -> bstep * (double)i);
	return ((rgb.r * 256 + rgb.g) * 256 + rgb.b);
}

void	put_edge(t_image *img, t_edge *edge)
{
	t_xydata	t;
	t_rgb_step	color_step;
	int			i;
	int			m;

	t.xsize = (edge -> x2 - edge -> x1);
	t.ysize = (edge -> y2 - edge -> y1);
	m = max(abs(t.xsize), abs(t.ysize));
	t.xstep = (double)t.xsize / (double)m;
	t.ystep = (double)t.ysize / (double)m;
	set_color_step(&color_step, edge, m);
	i = 0;
	while (i++ != m)
	{
		t.x = edge -> x1 + t.xstep * i;
		t.y = edge -> y1 + t.ystep * i;
		put_pixel(img, (int)t.x, (int)t.y, get_color(i, &color_step));
	}
}
