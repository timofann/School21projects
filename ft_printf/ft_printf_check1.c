/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:03:56 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:03:58 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_check(unsigned char c, const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;

	piece_len = 1;
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.width > 1)
		piece_len = flags.width;
	*full_len += piece_len;
	if (!c)
		return (0);
	return (0);
}

int	s_check(char *s, const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;

	if (!s)
		piece_len = 6;
	else
		piece_len = (int)ft_strlen(s);
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.precision >= 0 && flags.precision < piece_len)
		piece_len = flags.precision;
	if (flags.width > piece_len)
		piece_len = flags.width;
	*full_len += piece_len;
	return (0);
}

int	p_check(unsigned long long p,
			const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;

	piece_len = 0;
	while (p != 0)
	{
		p = p / 16;
		piece_len++;
	}
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && piece_len == 0)
		piece_len = 1;
	piece_len += 2;
	if (flags.width > piece_len)
		piece_len = flags.width;
	*full_len += piece_len;
	return (0);
}

int	d_check(int d, const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;
	int		is_negative;

	is_negative = (d < 0);
	piece_len = 0;
	while (d != 0)
	{
		d = d / 10;
		piece_len++;
	}
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && piece_len == 0)
		piece_len = 1;
	piece_len += (is_negative || flags.space >= 0 || flags.plus >= 0);
	if (flags.width > piece_len)
		piece_len = flags.width;
	*full_len += piece_len;
	return (0);
}
