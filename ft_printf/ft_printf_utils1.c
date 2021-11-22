/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:05:14 by dedelmir          #+#    #+#             */
/*   Updated: 2021/11/11 11:03:44 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	uputnbr(unsigned long long p, int fundament, char *alphabet)
{
	if (p == 0)
		return ;
	uputnbr(p / fundament, fundament, alphabet);
	write(1, &alphabet[p % fundament], 1);
}

void	iputnbr(long long d, int fundament, char *alphabet)
{
	if (d == 0)
		return ;
	iputnbr(d / fundament, fundament, alphabet);
	write(1, &alphabet[(d % fundament) *(2 * (d >= 0) - 1)], 1);
}

void	add_width(char *symbol, int width, int piece_len)
{
	while (piece_len++ < width)
		write(1, symbol, 1);
}

int	get_num_len(unsigned long long p, int fundament)
{
	int	num_len;

	num_len = 0;
	while (p != 0)
	{
		p = p / fundament;
		num_len++;
	}
	return (num_len);
}

char	*zn(long long d, t_flags flags)
{
	if (d < 0)
		return (&ZNAK[0]);
	if (flags.plus >= 0)
		return (&ZNAK[1]);
	return (&ZNAK[2]);
}
