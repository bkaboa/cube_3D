/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:47:04 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:02:58 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	if (!cube->mlx.mlx)
		exit(1);
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx, WIDTH, HEIGHT, "cube3d");
	if (!cube->mlx.mlx_win)
	{
		mlx_destroy_display(cube->mlx.mlx);
		free(cube->mlx.mlx);
		exit(1);
	}
}
