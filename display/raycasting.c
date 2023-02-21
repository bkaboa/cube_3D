/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:48:14 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:10:56 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_step(t_cube *cube)
{
	if (cube->ray.ray_dir.dirx < 0)
	{
		cube->ray.step_x = -1;
		cube->ray.side_distx = \
		(cube->player.x_pos - cube->ray.map_x) * cube->ray.delta_dist_x;
	}
	else
	{
		cube->ray.step_x = 1;
		cube->ray.side_distx = \
		(cube->ray.map_x + 1.0 - cube->player.x_pos) * cube->ray.delta_dist_x;
	}
	if (cube->ray.ray_dir.diry < 0)
	{
		cube->ray.step_y = -1;
		cube->ray.side_disty = \
		(cube->player.y_pos - cube->ray.map_y) * cube->ray.delta_dist_y;
	}
	else
	{
		cube->ray.step_y = 1;
		cube->ray.side_disty = \
		(cube->ray.map_y + 1.0 - cube->player.y_pos) * cube->ray.delta_dist_y;
	}
}

void	define_height_start_end(t_cube *cube)
{
	cube->ray.lineheight = (int)HEIGHT / cube->ray.perpwalldist;
	cube->ray.drawstart = -(cube->ray.lineheight >> 1) + (HEIGHT >> 1) + 1;
	if (cube->ray.drawstart < 0)
		cube->ray.drawstart = 0;
	cube->ray.drawend = (cube->ray.lineheight >> 1) + (HEIGHT >> 1) - 1;
	if (cube->ray.drawend >= HEIGHT)
		cube->ray.drawend = HEIGHT - 1;
}

void	run_dda(t_cube *cube)
{
	while (cube->ray.hit == 0)
	{
		if (cube->ray.side_distx < cube->ray.side_disty)
		{
			cube->ray.side_distx += cube->ray.delta_dist_x;
			cube->ray.map_x += cube->ray.step_x;
			cube->ray.side = 0;
		}
		else
		{
			cube->ray.side_disty += cube->ray.delta_dist_y;
			cube->ray.map_y += cube->ray.step_y;
			cube->ray.side = 1;
		}
		if (cube->map[cube->ray.map_x][cube->ray.map_y] == '1')
			cube->ray.hit = 1;
	}
}

void	init_ray(t_cube *cube, int x)
{
	cube->ray.hit = 0;
	cube->ray.camera_x = 2 * x / (float)WIDTH - 1;
	cube->ray.ray_dir.dirx = cube->player.playerdir.dirx \
	+ cube->player.plane_x * cube->ray.camera_x;
	cube->ray.ray_dir.diry = cube->player.playerdir.diry \
	+ cube->player.plane_y * cube->ray.camera_x;
	cube->ray.map_x = (int)cube->player.x_pos;
	cube->ray.map_y = (int)cube->player.y_pos;
	cube->ray.delta_dist_x = sqrt(1 + (cube->ray.ray_dir.diry \
	* cube->ray.ray_dir.diry) / (cube->ray.ray_dir.dirx * \
	cube->ray.ray_dir.dirx));
	cube->ray.delta_dist_y = sqrt(1 + (cube->ray.ray_dir.dirx \
	* cube->ray.ray_dir.dirx) / (cube->ray.ray_dir.diry * \
	cube->ray.ray_dir.diry));
}

void	raycasting_loop(t_cube *cube)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(cube, x);
		init_step(cube);
		run_dda(cube);
		if (cube->ray.side == 0)
			cube->ray.perpwalldist = ((cube->ray.map_x - cube->player.x_pos \
			+ (1 - cube->ray.step_x) / 2) / cube->ray.ray_dir.dirx);
		else
			cube->ray.perpwalldist = ((cube->ray.map_y - cube->player.y_pos \
			+ (1 - cube->ray.step_y) / 2) / cube->ray.ray_dir.diry);
		define_height_start_end(cube);
		init_pixel_ray(cube, cube->ray.textnum);
		if (cube->ray.lineheight > HEIGHT)
			cube->ray.lineheight = HEIGHT;
		trace_line_from_ray(cube, x);
		x++;
	}
}
