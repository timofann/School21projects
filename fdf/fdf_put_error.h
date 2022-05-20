/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:00:56 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 19:00:58 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PUT_ERROR_H
# define FDF_PUT_ERROR_H

# define INVALID_ARG_COUNT "Usage : ./fdf <filename> [ max_altitude ]"
# define INVALID_FILENAME "No such file."
# define INVALID_ALTITUDE "<max_altitude> should be integer value."
# define EMPTY_FILE "No data found. Exiting."
# define INVALID_ROW_WIDTH "Found wrong line length. Exiting."
# define MEMORY_ERROR "Couldn't allocate memory. Exiting."
# define INVALID_NUMERIC_DATA "The map contains non-color data or non-integer values. \
Exiting."
# define INVALID_EXTENSION ".fdf extension expected."

# define MAP_INITIALIZATION_FAILED "Couldn't find actual version of mlx library. \
Sure you turn necessary files in the project directory."
# define IMG_INITIALIZATION_FAILED "Couldn't get image."

# include <stdlib.h>
# include <unistd.h>

size_t	str_len(char *str);
void	put_error(char *str);

#endif
