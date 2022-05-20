/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_perversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:28:13 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:28:17 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_perversion(t_drawable *model, float perversion_factor)
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
				= (model -> map -> table)[i][j].z * perversion_factor;
			j++;
		}
		i++;
	}
}
