/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:04:16 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:04:19 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_precision(const char *fmt_piece, int *i)
{
	unsigned int	precision;
	int				flag;

	flag = 1;
	(*i)++;
	precision = 0;
	while (fmt_piece[*i] >= '0' && fmt_piece[*i] <= '9')
	{
		if (precision > MAX_INT / 10)
			flag = 0;
		if (flag)
			precision = precision * 10 + (fmt_piece[*i] - '0');
		(*i)++;
	}
	if (flag)
		return ((int)precision);
	return (-5);
}

static int	get_width(const char *fmt_piece, int *i)
{
	unsigned int	width;
	int				flag;

	flag = 1;
	width = 0;
	while (fmt_piece[*i] >= '0' && fmt_piece[*i] <= '9')
	{
		if (width > MAX_INT / 10)
			flag = 0;
		if (flag)
			width = width * 10 + (fmt_piece[*i] - '0');
		(*i)++;
	}
	if (flag)
		return ((int)width);
	return (-5);
}

static void	fill_by_zeroes(t_flags *flags)
{
	flags -> precision = -1;
	flags -> hash = -1;
	flags -> plus = -1;
	flags -> space = -1;
	flags -> width = -1;
	flags -> minus = -1;
	flags -> zero = -1;
}

static void	delete_exceptions(t_flags *flags, const char spec)
{
	if (flags -> plus >= 0)
		flags -> space = -1;
	if (flags -> minus >= 0)
		flags -> zero = -1;
	if (flags -> precision >= 0 && (spec == 'p' || spec == 'd'
			|| spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X'))
		flags -> zero = -1;
}

void	get_flags(t_flags *flags, const char *fmt_piece, int last_i)
{
	int		i;

	fill_by_zeroes(flags);
	i = 0;
	while (i < last_i)
	{
		if (fmt_piece[i] == '-')
			flags -> minus = i++;
		else if (fmt_piece[i] == '+')
			flags->plus = i++;
		else if (fmt_piece[i] == '0')
			flags -> zero = i++;
		else if (fmt_piece[i] == '#')
			flags -> hash = i++;
		else if (fmt_piece[i] == ' ')
			flags -> space = i++;
		else if (fmt_piece[i] == '.')
			flags -> precision = get_precision(fmt_piece, &i);
		else if (fmt_piece[i] >= '1' && fmt_piece[i] <= '9')
			flags -> width = get_width(fmt_piece, &i);
	}
	delete_exceptions(flags, fmt_piece[last_i]);
}
