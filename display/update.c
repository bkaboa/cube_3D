/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:45:22 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:03:58 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	render_frame(t_cube *cube)
{
	cube->mlx.walls.img = mlx_new_image(cube->mlx.mlx, WIDTH, HEIGHT);
	if (!cube->mlx.walls.img)
		exit(1);
	cube->mlx.walls.addr = mlx_get_data_addr(cube->mlx.walls.img, \
	&cube->mlx.walls.bits_per_pixel, \
		&cube->mlx.walls.line_length, &cube->mlx.walls.endian);
	raycasting_loop(cube);
	draw_minimap(cube);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, \
	cube->mlx.walls.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.walls.img);
}

int	update_game(t_cube *cube)
{
	keys_move_player(cube);
	render_frame(cube);
	return (0);
}
