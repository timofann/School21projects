/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_model.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:00:45 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 19:00:48 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSE_MODEL_H
# define FDF_PARSE_MODEL_H

# include <sys/file.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "fdf_put_error.h"
# include "fdf_put_message.h"
# include "fdf_colors.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define MAX_COLOR_LEN 8

# define HEX_BASE_COUNT 16
# define UPPERCASE_HEX "0123456789ABCDEF"
# define LOWERCASE_HEX "0123456789abcdef"

typedef struct s_vertex {
	float	x;
	float	y;
	float	z;
	float	display_y;
	int		color;
}	t_vertex;

typedef struct s_map {
	t_vertex	**table;
	size_t		width;
	size_t		height;
	size_t		altitude;
}	t_map;

typedef struct s_drawable {
	t_map	*map;
	int		x_angle;
	int		y_angle;
	int		z_angle;
	float	zoom;
	float	x_centering_factor;
	float	centering_factor;
	float	def_centering_factor;
	float	perversion_factor;
	int		enable_axes;
	int		vertex_mode;
	int		color_mode;
	int		perspective_mode;
	int		enable_info;
}	t_drawable;

void	put_error(char *str);
void	put_message(char *str);

int		long_type_is_needed(int altitude, int sign, char next_char);
int		get_sign(char **arg);

int		get_fd(char *filename);
int		get_default_altitude(int argc, char **argv);

void	set_empty_map(char *filename, t_map **map);

int		get_next_altitude(char **line);
int		get_next_color(char **line);
void	fill_map(char *filename, t_map *map);

void	parse_model(int argc, char **argv, t_drawable *model);

#endif
