/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:01 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:32:03 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_put_error.h"

void	put_error(char *str)
{
	size_t	len;

	len = str_len(str);
	write(2, str, len);
	write(2, "\n", 1);
	exit(1);
}
