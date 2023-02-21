/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:48:14 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:17:20 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_step(t_cube *cube)
{
	if (cube->ray.rayDir.dirx < 0)
	{
		cube->ray.stepX = -1;
		cube->ray.sideDistX = \
		(cube->player.xPos - cube->ray.mapX) * cube->ray.deltaDistX;
	}
	else
	{
		cube->ray.stepX = 1;
		cube->ray.sideDistX = \
		(cube->ray.mapX + 1.0 - cube->player.xPos) * cube->ray.deltaDistX;
	}
	if (cube->ray.rayDir.diry < 0)
	{
		cube->ray.stepY = -1;
		cube->ray.sideDistY = \
		(cube->player.yPos - cube->ray.mapY) * cube->ray.deltaDistY;
	}
	else
	{
		cube->ray.stepY = 1;
		cube->ray.sideDistY = \
		(cube->ray.mapY + 1.0 - cube->player.yPos) * cube->ray.deltaDistY;
	}
}

void	define_height_start_end(t_cube *cube)
{
	cube->ray.lineHeight = (int)HEIGHT / cube->ray.perpWallDist;
	cube->ray.drawstart = -(cube->ray.lineHeight >> 1) + (HEIGHT >> 1) + 1;
	if (cube->ray.drawstart < 0)
		cube->ray.drawstart = 0;
	cube->ray.drawend = (cube->ray.lineHeight >> 1) + (HEIGHT >> 1) - 1;
	if (cube->ray.drawend >= HEIGHT)
		cube->ray.drawend = HEIGHT - 1;
}

void	run_dda(t_cube *cube)
{
	while (cube->ray.hit == 0)
	{
		if (cube->ray.sideDistX < cube->ray.sideDistY)
		{
			cube->ray.sideDistX += cube->ray.deltaDistX;
			cube->ray.mapX += cube->ray.stepX;
			cube->ray.side = 0;
		}
		else
		{
			cube->ray.sideDistY += cube->ray.deltaDistY;
			cube->ray.mapY += cube->ray.stepY;
			cube->ray.side = 1;
		}
		if (cube->map[cube->ray.mapX][cube->ray.mapY] == '1')
			cube->ray.hit = 1;
	}
}

void	init_ray(t_cube *cube, int x)
{
	cube->ray.hit = 0;
	cube->ray.cameraX = 2 * x / (float)WIDTH - 1;
	cube->ray.rayDir.dirx = cube->player.playerdir.dirx \
	+ cube->player.planeX * cube->ray.cameraX;
	cube->ray.rayDir.diry = cube->player.playerdir.diry \
	+ cube->player.planeY * cube->ray.cameraX;
	cube->ray.mapX = (int)cube->player.xPos;
	cube->ray.mapY = (int)cube->player.yPos;
	cube->ray.deltaDistX = sqrt(1 + (cube->ray.rayDir.diry \
	* cube->ray.rayDir.diry) / (cube->ray.rayDir.dirx * cube->ray.rayDir.dirx));
	cube->ray.deltaDistY = sqrt(1 + (cube->ray.rayDir.dirx \
	* cube->ray.rayDir.dirx) / (cube->ray.rayDir.diry * cube->ray.rayDir.diry));
}

void	raycasting_loop(t_cube *cube)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(cube, x);
		init_step(cube);
		run_dda(cube);
		if (cube->ray.side == 0)
			cube->ray.perpWallDist = ((cube->ray.mapX - cube->player.xPos \
			+ (1 - cube->ray.stepX) / 2) / cube->ray.rayDir.dirx);
		else
			cube->ray.perpWallDist = ((cube->ray.mapY - cube->player.yPos \
			+ (1 - cube->ray.stepY) / 2) / cube->ray.rayDir.diry);
		select_wall_to_put_pixel(cube, x);
		define_height_start_end(cube);
		init_pixel_ray(cube, cube->ray.textnum);
		if (cube->ray.lineHeight > HEIGHT)
			cube->ray.lineHeight = HEIGHT;
		trace_line_from_ray(cube, x);
		x++;
	}
}
