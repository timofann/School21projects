/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:29:00 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:29:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
void	fill_first(int first_part, char *str, size_t *i)
{
	int	mask;

	mask = 100000;
	while (first_part / mask == 0 && mask > 1)
		mask = mask / 10;
	while (mask > 1)
	{
		str[*i] = (first_part / mask) % 10 + '0';
		(*i)++;
		mask = mask / 10;
	}
	str[*i] = first_part % 10 + '0';
	(*i)++;
}

static
void	fill_last(int last_part, char *str, size_t *i)
{
	str[*i] = last_part / 10 + '0';
	(*i)++;
	str[*i] = last_part % 10 + '0';
	(*i)++;
}

char	*float_to_string(float num, char *str)
{
	int		first_part;
	int		last_part;
	size_t	i;

	first_part = (int)num;
	last_part = (int)(((float)(num - first_part)) * 100);
	i = 0;
	if (first_part < 0)
	{
		str[i++] = '-';
		first_part = first_part * -1;
	}
	fill_first(first_part, str, &i);
	str[i++] = '.';
	fill_last(last_part, str, &i);
	while (i < 10)
		str[i++] = '\0';
	return (str);
}
