/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:28:50 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:28:51 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

static
t_vertex	get_next_vertex(char **line, t_map *map, size_t x, size_t y)
{
	t_vertex	vertex;

	vertex.x = (float)x - (float)(map -> width - 1) / 2;
	vertex.y = (float)y - (float)(map -> height - 1) / 2;
	vertex.z = get_next_altitude(line);
	vertex.color = get_next_color(line);
	return (vertex);
}

static
void	fill_row(char *line, t_map *map, size_t y)
{
	size_t	x;

	x = 0;
	while (x < (map -> width))
	{
		map -> table[y][x] = get_next_vertex(&line, map, x, y);
		x++;
	}
}

void	fill_map(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	size_t	y;

	fd = get_fd(filename);
	y = 0;
	while (y < (map -> height))
	{
		line = get_next_line(fd);
		fill_row(line, map, y);
		free(line);
		y++;
	}
	close(fd);
}
