/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:47:23 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:32:34 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	draw_direction(t_cube *cube, int x, int y, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(&cube->mlx.walls, (x + (cube->player.planeY * i)), \
		(y + (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.walls, (x - (cube->player.planeY * i)), \
		(y - (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.walls, (x + \
		(cube->player.playerdir.diry * i)), (y + \
		(cube->player.playerdir.dirx * i)), C_GREEN);
		i++;
	}
}

void	draw_player(t_mlx *mlx, int x, int y)
{
	int	j;
	int	i;

	j = -PLAYER_MINI_SIZE;
	while (j < PLAYER_MINI_SIZE)
	{
		i = -PLAYER_MINI_SIZE;
		while (i < PLAYER_MINI_SIZE)
		{
			my_mlx_pixel_put(&mlx->walls, (x + i), (y + j), C_GREEN);
			i++;
		}
		j++;
	}
}

void	draw_cells(t_cube *cube)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	if (cube->mlx.minimap_ratio > 3)
	{
		while (++y < cube->map_ylen * cube->mlx.minimap_ratio - 1)
		{
			while (++x < cube->map_xlen * cube->mlx.minimap_ratio - 1)
			{
				if (x / cube->mlx.minimap_ratio > \
				ft_strlen(cube->map[y / cube->mlx.minimap_ratio]))
					;
				else if (y / cube->mlx.minimap_ratio > cube->map_ylen)
					;
				else if (cube->map[y / \
				cube->mlx.minimap_ratio][x / cube->mlx.minimap_ratio] == '1')
					my_mlx_pixel_put(&cube->mlx.walls, x, y, C_WHITE);
				else if (cube->map[y / \
				cube->mlx.minimap_ratio][x / cube->mlx.minimap_ratio] == '0')
					my_mlx_pixel_put(&cube->mlx.walls, x, y, C_BLUE);
			}
		}
	}
}

void	draw_minimap(t_cube *cube)
{
	draw_cells(cube);
	draw_direction(cube, offset(*cube, cube->player.yPos), \
	offset(*cube, cube->player.xPos), 50);
	draw_player(&cube->mlx, offset(*cube, cube->player.yPos), \
	offset(*cube, cube->player.xPos));
}
