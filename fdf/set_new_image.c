/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:47 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:33:48 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_new_image(t_mlx *workspace, t_image *img)
{
	img -> img_ptr = mlx_new_image(workspace -> mlx, WIDTH, HEIGHT);
	if (!img -> img_ptr)
		put_error(IMG_INITIALIZATION_FAILED);
	img -> addr = mlx_get_data_addr(img -> img_ptr,
			&img -> bit_per_pixel, &img -> size_line, &img -> endian);
	if (!img -> addr)
		put_error(IMG_INITIALIZATION_FAILED);
}
