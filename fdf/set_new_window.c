/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_new_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedelmir <dedelmir@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:59 by dedelmir          #+#    #+#             */
/*   Updated: 2022/03/20 18:34:01 by dedelmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static
int	exit_by_escape(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

static
int	exit_by_cross(void)
{
	exit(0);
}

static
void	set_exit_by_escape(t_mlx *workspace)
{
	mlx_key_hook(workspace -> win, exit_by_escape, workspace);
}

static
void	set_exit_by_cross(t_mlx *workspace)
{
	mlx_hook(workspace -> win, 17, 0L, exit_by_cross, workspace);
}

void	set_new_window(t_mlx *workspace)
{
	init_workspace(workspace);
	set_exit_by_cross(workspace);
	set_exit_by_escape(workspace);
}
