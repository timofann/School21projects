/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:29:56 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:29:58 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_parse_model.h"

static
int	get_hex_digit(char c)
{
	size_t	i;

	i = 0;
	while (i < HEX_BASE_COUNT)
	{
		if (c == UPPERCASE_HEX[i] || c == LOWERCASE_HEX[i])
			return (i);
		i++;
	}
	return (i);
}

static
int	get_hex(char **line)
{
	size_t	len;
	int		digit;
	int		new_hex;

	len = 0;
	new_hex = 0;
	while (**line != ' ' && **line != '\n' && **line != '\0')
	{
		if (len == MAX_COLOR_LEN)
			put_error(INVALID_NUMERIC_DATA);
		digit = get_hex_digit(**line);
		if (digit == HEX_BASE_COUNT)
			put_error(INVALID_NUMERIC_DATA);
		new_hex = new_hex * 16 + digit;
		(*line)++;
		len++;
	}
	return (new_hex);
}

int	get_next_color(char **line)
{
	int	color;

	color = WHITE;
	if (**line == ',')
	{
		if (*(*line)++ != ',' || *(*line)++ != '0' || *(*line)++ != 'x')
			put_error(INVALID_NUMERIC_DATA);
		color = get_hex(line);
	}
	return (color);
}
