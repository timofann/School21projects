/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:04:07 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:04:09 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_check(unsigned int u, const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;

	piece_len = 0;
	while (u != 0)
	{
		u = u / 10;
		piece_len++;
	}
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && piece_len == 0)
		piece_len = 1;
	if (flags.width > piece_len)
		piece_len = flags.width;
	*full_len += piece_len;
	return (0);
}

int	x_check(unsigned int x, const char *fmt_piece, int last_i, int *full_len)
{
	t_flags	flags;
	int		piece_len;
	int		non_zero;

	non_zero = (x != 0);
	piece_len = 0;
	while (x != 0)
	{
		x = x / 16;
		piece_len++;
	}
	get_flags(&flags, fmt_piece, last_i);
	if (flags.width == -5 || flags.precision == -5)
		return (1);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && piece_len == 0)
		piece_len = 1;
	if (flags.hash >= 0 && non_zero)
		piece_len += 2;
	if (flags.width > piece_len)
		piece_len = flags.width;
	*full_len += piece_len;
	return (0);
}
