/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:00:13 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 19:00:15 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_parse_model.h"
# include "fdf_put_error.h"
# include "fdf_put_message.h"
# include "fdf_keycodes.h"
# include "fdf_colors.h"
# include <math.h>
# include <mlx.h>

/*
 *	Settings for the window
 */

# define WIDTH 1400
# define HEIGHT 1000
# define NICE_HEIGHT 900
# define NICE_WIDTH 1350
# define TITLE "FIL DE FER"
# define X_CENTER 700
# define Y_CENTER 500

/*
 *	Settings for the model default state
 */

# define DEFAULT_X_ANGLE 30
# define DEFAULT_Y_ANGLE 0
# define DEFAULT_Z_ANGLE 30

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}	t_mlx;

typedef struct s_image {
	void	*img_ptr;
	char	*addr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_edge {
	int	x1;
	int	y1;
	int	color1;
	int	x2;
	int	y2;
	int	color2;
}	t_edge;

char	*float_to_string(float num, char *str);

void	init_workspace(t_mlx *workspace);
void	set_new_window(t_mlx *workspace);
void	apply_centering(t_drawable *model);
void	apply_perversion(t_drawable *model, float perversion_factor);
void	save_state(t_drawable *model, t_drawable *saved);

void	set_new_image(t_mlx *workspace, t_image *img);
void	clear_window(t_image *img);
void	set_default_state(t_drawable *model);
void	put_pixel(t_image *img, int x, int y, int color);
void	put_edge(t_image *img, t_edge *edge);
void	put_edges_isometric(t_image *img, t_drawable *model);
void	put_edges_perspective(t_image *img, t_drawable *model);
float	get_default_zoom(t_drawable *model);
void	rotate_model(t_map *map, int x_angle, int y_angle, int z_angle);
void	put_axes(t_image *img, t_drawable *model);
void	put_info(t_mlx *workspace, t_drawable *model);
void	draw_state(t_mlx *workspace, t_image *img, t_drawable *model);
void	set_hooks_for_drawing(t_mlx *workspace, t_drawable *model);

#endif
