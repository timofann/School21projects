/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_empty_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:24 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:26 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
size_t	get_width(char *line)
{
	size_t	i;
	size_t	width;

	if (!line)
		put_error(EMPTY_FILE);
	i = 0;
	width = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		else
		{
			width++;
			while (line[i] != '\0' && line[i] != '\n' && line[i] != ' ')
				i++;
		}
	}
	if (width == 0)
		put_error(EMPTY_FILE);
	return (width);
}

static
size_t	get_width_n_free(char *line)
{
	size_t	width;

	width = get_width(line);
	free(line);
	return (width);
}

static
size_t	get_height(char *line, size_t width, int fd)
{
	size_t	height;
	char	*next_line;

	height = 1;
	while (line)
	{
		if (get_width(line) != width)
		{
			next_line = get_next_line(fd);
			if (*line == '\n' && !next_line)
				height--;
			else
				put_error(INVALID_ROW_WIDTH);
		}
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

static
void	set_empty_table(t_map *map)
{
	size_t	row;

	map -> table = (t_vertex **)malloc(sizeof(t_vertex *) * map -> height);
	if (!(map -> table))
		put_error(MEMORY_ERROR);
	row = 0;
	while (row < map -> height)
	{
		map -> table[row] = (t_vertex *)malloc(sizeof(t_vertex) * map -> width);
		if (!map -> table[row])
			put_error(MEMORY_ERROR);
		row++;
	}
}

void	set_empty_map(char *filename, t_map **map)
{
	int	fd;

	fd = get_fd(filename);
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
		put_error(MEMORY_ERROR);
	(*map)-> width = get_width_n_free(get_next_line(fd));
	(*map)-> height = get_height(get_next_line(fd), (*map)-> width, fd);
	set_empty_table(*map);
	close(fd);
}
