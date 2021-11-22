/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:03:47 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:03:50 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_piece(va_list a, const char *fmt_piece,
						int last_i, int *full_len)
{
	if (!fmt_piece[last_i])
		return (0);
	if (fmt_piece[last_i] == 'c')
		return (c_check(va_arg(a, int), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 's')
		return (s_check(va_arg(a, char *), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'p')
		return (p_check(va_arg(a, unsigned long long),
				fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'd')
		return (d_check(va_arg(a, int), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'i')
		return (d_check(va_arg(a, int), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'u')
		return (u_check(va_arg(a, unsigned int), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'x')
		return (x_check(va_arg(a, unsigned int), fmt_piece, last_i, full_len));
	if (fmt_piece[last_i] == 'X')
		return (x_check(va_arg(a, unsigned int), fmt_piece, last_i, full_len));
	return (c_check(fmt_piece[last_i], fmt_piece, last_i, full_len));
}

static void	check_validity(va_list a, const char *fmt, int *full_len)
{
	int	i;
	int	j;
	int	error_index;

	j = 0;
	error_index = 0;
	while (fmt[j])
	{
		if (fmt[j++] != '%')
			(*full_len)++;
		else
		{
			i = 0;
			while (is_flag(fmt[j + i]))
				i++;
			if (check_piece(a, &fmt[j], i, full_len) == 1)
			{
				*full_len = (error_index * -1) - 1;
				return ;
			}
			j += i + (fmt[j + i] != '\0');
			error_index = j;
		}
	}
}

static int	print_piece(va_list a, const char *fmt_piece, int last_i)
{
	if (!fmt_piece[last_i])
		return (0);
	if (fmt_piece[last_i] == 'c')
		return (c_print(va_arg(a, int), fmt_piece, last_i));
	if (fmt_piece[last_i] == 's')
		return (s_print(va_arg(a, char *), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'p')
		return (p_print(va_arg(a, unsigned long long), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'd')
		return (d_print(va_arg(a, int), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'i')
		return (d_print(va_arg(a, int), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'u')
		return (u_print(va_arg(a, unsigned int), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'x')
		return (x_print(va_arg(a, unsigned int), fmt_piece, last_i));
	if (fmt_piece[last_i] == 'X')
		return (xx_print(va_arg(a, unsigned int), fmt_piece, last_i));
	return (c_print(fmt_piece[last_i], fmt_piece, last_i));
}

static void	print_f_string(va_list a, const char *fmt, int *full_len)
{
	int	i;
	int	j;

	j = 0;
	while (fmt[j])
	{
		if (j == (*full_len + 1) * (-1))
		{
			*full_len = -1;
			return ;
		}
		if (fmt[j] != '%')
			write(1, &fmt[j++], 1);
		else
		{
			j++;
			i = 0;
			while (is_flag(fmt[i + j]))
				i++;
			print_piece(a, &fmt[j], i);
			j += i + (fmt[i + j] != '\0');
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	a1;
	va_list	a2;
	int		full_len;

	if (!fmt)
		return (0);
	full_len = 0;
	va_start(a1, fmt);
	check_validity(a1, fmt, &full_len);
	va_end(a1);
	if (full_len == 0)
		return (full_len);
	va_start(a2, fmt);
	print_f_string(a2, fmt, &full_len);
	va_end(a2);
	return (full_len);
}
