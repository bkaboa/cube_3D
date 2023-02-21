/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:36:32 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 21:05:17 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3D.h"
#include "includes/struct.h"

void	init_ratio(t_cube *cube)
{
	if (cube->map_ylen > cube->map_xlen)
		cube->mlx.minimap_ratio = HEIGHT / 3 / cube->map_ylen;
	else
		cube->mlx.minimap_ratio = WIDTH / 3 / cube->map_xlen;
}

int	main(int ac, char **av)
{
	t_cube	cube;

	ft_bzero((void *)&cube, sizeof(cube));
	init_mlx(&cube);
	file_map_parsing(ac, av, &cube);
	// printf("posx %f posy %f\n", cube.player.x_pos, cube.player.y_pos);
	// int i = -1;
	// while (cube.map[++i])
	// 	dprintf(2, "%s\n", cube.map[i]);
	// exit(1);
	init_ratio(&cube);
	cube.map_xlen--;
	render_frame(&cube);
	mlx_hook(cube.mlx.mlx_win, 2, 1L << 0, &key_press, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, &click_close, &cube);
	mlx_hook(cube.mlx.mlx_win, 3, 1L << 1, &key_release, &cube);
	mlx_loop_hook(cube.mlx.mlx, &update_game, &cube);
	mlx_loop(cube.mlx.mlx);
	return (0);
}
