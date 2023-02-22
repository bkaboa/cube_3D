/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:20:00 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/22 01:25:44 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	free_all_and_exit(t_cube *cube)
{
	int	i;

	i = 0;
	cube->text_file.string_destructor(&cube->text_file);
	free(cube->map);
	while (i < 4)
	{
		mlx_destroy_image(cube->mlx.mlx, cube->mlx.wall_sprite[i].sprite);
		i++;
	}
	mlx_clear_window(cube->mlx.mlx, cube->mlx.mlx_win);
	mlx_destroy_window(cube->mlx.mlx, cube->mlx.mlx_win);
	mlx_destroy_display(cube->mlx.mlx);
	free(cube->mlx.mlx);
	exit(0);
}

int	click_close(t_cube *cube)
{
	free_all_and_exit(cube);
	return (0);
}
