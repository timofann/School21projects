/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:04:48 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:05:02 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_print(unsigned int u, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		num_len;
	int		piece_len;

	num_len = get_num_len(u, 10);
	get_flags(&flags, fmt_piece, last_i);
	piece_len = num_len + (flags.precision < 0 && u == 0);
	if (flags.precision > num_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && u == 0)
		flags.precision = 1;
	if (flags.width >= 1 && flags.minus < 0)
		add_width(&ZERO_OR_SPACE[(flags.zero >= 0)], flags.width, piece_len);
	while (flags.precision-- > num_len)
		write(1, "0", 1);
	uputnbr(u, 10, DECIMAL);
	if (flags.width >= 1 && flags.minus >= 0)
		add_width(" ", flags.width, piece_len);
	return (0);
}

int	x_print(unsigned int x, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		num_len;
	int		piece_len;

	get_flags(&flags, fmt_piece, last_i);
	num_len = get_num_len(x, 16);
	piece_len = num_len + (flags.precision < 0 && x == 0);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && x == 0)
		flags.precision = 1;
	piece_len += 2 * (flags.hash >= 0 && x != 0);
	if (flags.hash >= 0 && x != 0 && flags.zero >= 0)
		write(1, "0x", 2);
	if (flags.width >= 1 && flags.minus < 0)
		add_width(&ZERO_OR_SPACE[(flags.zero >= 0)], flags.width, piece_len);
	if (flags.hash >= 0 && x != 0 && flags.zero < 0)
		write(1, "0x", 2);
	while (flags.precision-- > num_len)
		write(1, "0", 1);
	uputnbr(x, 16, LOW_HEX);
	if (flags.width >= 1 && flags.minus >= 0)
		add_width(" ", flags.width, piece_len);
	return (0);
}

int	xx_print(unsigned int x, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		piece_len;
	int		num_len;

	get_flags(&flags, fmt_piece, last_i);
	num_len = get_num_len(x, 16);
	piece_len = num_len + (flags.precision < 0 && x == 0);
	if (flags.precision > piece_len)
		piece_len = flags.precision;
	if (flags.precision < 0 && x == 0)
		flags.precision = 1;
	piece_len += 2 * (flags.hash >= 0 && x != 0);
	if (flags.hash >= 0 && x != 0 && flags.zero >= 0)
		write(1, "0X", 2);
	if (flags.width >= 1 && flags.minus < 0)
		add_width(&ZERO_OR_SPACE[(flags.zero >= 0)], flags.width, piece_len);
	if (flags.hash >= 0 && x != 0 && flags.zero < 0)
		write(1, "0X", 2);
	while (flags.precision-- > num_len)
		write(1, "0", 1);
	uputnbr(x, 16, UPP_HEX);
	if (flags.width >= 1 && flags.minus >= 0)
		add_width(" ", flags.width, piece_len);
	return (0);
}
