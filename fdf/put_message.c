/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_message.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:32:19 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:32:21 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_put_message.h"

void	put_message(char *str)
{
	size_t	len;

	len = str_len(str);
	write(1, str, len);
	write(1, "\n", 1);
}
