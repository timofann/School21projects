/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:04:27 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/09 23:04:31 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_print(int c, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		i;

	get_flags(&flags, fmt_piece, last_i);
	if (flags.minus >= 0)
		write(1, &c, 1);
	if (flags.width >= 1)
	{
		i = 1;
		while (i++ < flags.width)
			write(1, &ZERO_OR_SPACE[(flags.zero >= 0)], 1);
	}
	if (flags.minus < 0)
		write(1, &c, 1);
	return (0);
}

int	s_print(char *s, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		piece_len;
	int		i;

	if (!s)
		return (s_print("(null)", fmt_piece, last_i));
	else
		piece_len = (int)ft_strlen(s);
	get_flags(&flags, fmt_piece, last_i);
	if (flags.precision >= 0 && flags.precision < piece_len)
		piece_len = flags.precision;
	if (flags.minus >= 0)
		write(1, s, piece_len);
	if (flags.width >= 1)
	{
		i = piece_len;
		while (i++ < flags.width)
			write(1, &ZERO_OR_SPACE[(flags.zero >= 0)], 1);
	}
	if (flags.minus < 0)
		write(1, s, piece_len);
	return (0);
}

int	p_print(unsigned long long p, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		piece_len;
	int		num_len;

	get_flags(&flags, fmt_piece, last_i);
	num_len = get_num_len(p, 16);
	piece_len = num_len + 2;
	if (flags.precision >= num_len)
		piece_len = flags.precision + 2;
	if (flags.zero >= 0)
		write(1, "0x", 2);
	if (flags.width >= 1 && flags.minus < 0)
		add_width(&ZERO_OR_SPACE[(flags.zero >= 0)], flags.width,
			piece_len + (flags.precision < 0 && num_len == 0));
	if (flags.zero < 0)
		write(1, "0x", 2);
	if (flags.precision < 0 && num_len == 0)
		flags.precision = 1;
	while (flags.precision-- > num_len)
		write(1, "0", 1);
	uputnbr(p, 16, LOW_HEX);
	if (flags.width >= 1 && flags.minus >= 0)
		add_width(" ", flags.width,
			piece_len + (flags.precision < 0 && num_len == 0));
	return (0);
}

int	d_print(int d, const char *fmt_piece, int last_i)
{
	t_flags	flags;
	int		num_len;
	int		piece_len;

	get_flags(&flags, fmt_piece, last_i);
	num_len = get_num_len((unsigned long long)d * (2 * (d > 0) - 1), 10);
	piece_len = num_len + (flags.precision < 0 && num_len == 0);
	if (flags.precision > num_len)
		piece_len = flags.precision;
	piece_len += (d < 0 || flags.space >= 0 || flags.plus >= 0);
	if (flags.zero >= 0)
		write(1, zn(d, flags), (d < 0 || flags.space >= 0 || flags.plus >= 0));
	if (flags.width >= 1 && flags.minus < 0)
		add_width(&ZERO_OR_SPACE[(flags.zero >= 0)], flags.width, piece_len);
	if (flags.zero < 0)
		write(1, zn(d, flags), (d < 0 || flags.space >= 0 || flags.plus >= 0));
	if (flags.precision < 0 && num_len == 0)
		flags.precision = 1;
	while (flags.precision-- > num_len)
		write(1, "0", 1);
	iputnbr(d, 10, DECIMAL);
	if (flags.width >= 1 && flags.minus >= 0)
		add_width(" ", flags.width, piece_len);
	return (0);
}
