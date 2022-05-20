/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_workspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:30:41 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:30:44 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_workspace(t_mlx *workspace)
{
	workspace -> mlx = mlx_init();
	if (!workspace -> mlx)
		put_error(MAP_INITIALIZATION_FAILED);
	workspace -> win = mlx_new_window(workspace -> mlx, WIDTH, HEIGHT, TITLE);
	if (!workspace -> win)
		put_error(MEMORY_ERROR);
}
