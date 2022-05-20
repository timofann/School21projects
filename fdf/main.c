/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:30:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:31:01 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_render {
	t_mlx		*workspace;
	t_image		*img;
	t_drawable	*model;
}	t_render;

int	render_next_frame(t_render *render)
{
	draw_state(render -> workspace, render -> img, render -> model);
	return (0);
}

int	main(int argc, char **argv)
{
	t_render	render;
	t_drawable	model;
	t_mlx		workspace;
	t_image		img;

	parse_model(argc, argv, &model);
	apply_centering(&model);
	apply_perversion(&model, model.perversion_factor * -1);
	set_default_state(&model);
	set_new_window(&workspace);
	set_new_image(&workspace, &img);
	set_hooks_for_drawing(&workspace, &model);
	render.workspace = &workspace;
	render.img = &img;
	render.model = &model;
	mlx_loop_hook(workspace.mlx, render_next_frame, &render);
	mlx_loop(workspace.mlx);
	return (0);
}
