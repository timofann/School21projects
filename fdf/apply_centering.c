/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_centering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:27:54 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:28:03 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_centering(t_drawable *model)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < model -> map -> height)
	{
		j = 0;
		while (j < model -> map -> width)
		{
			(model -> map -> table)[i][j].z
				= (model -> map -> table)[i][j].z
				+ model -> def_centering_factor;
			j++;
		}
		i++;
	}
}
