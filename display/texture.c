/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 01:45:42 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:15 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	init_pixel_ray(t_cube *cube, int textnum)
{
	cube->ray.ty_step = (HEIGHT / 10) / cube->ray.lineheight;
	if (cube->ray.side == 0)
		cube->ray.wall_x = cube->player.y_pos + cube->ray.perpwalldist \
		* cube->ray.ray_dir.diry;
	else
		cube->ray.wall_x = cube->player.x_pos + cube->ray.perpwalldist \
		* cube->ray.ray_dir.dirx;
	cube->ray.wall_x -= floorf(cube->ray.wall_x);
	cube->ray.tex_x = (int)(cube->ray.wall_x * \
	(float)cube->mlx.wall_sprite[textnum].width);
	cube->ray.tex_x = cube->mlx.wall_sprite[textnum].width - \
	cube->ray.tex_x - 1;
	cube->ray.f_step = 1.0 * cube->mlx.wall_sprite[textnum].height \
	/ cube->ray.lineheight / 1.0;
	cube->ray.tex_pos = (cube->ray.drawstart - (HEIGHT / 2) + \
	(cube->ray.lineheight / 2)) * cube->ray.f_step;
}

void	get_tex_color(t_cube *cube, int texnum, int x, int y)
{
	int	*new_addr;

	new_addr = (int *)cube->mlx.wall_sprite[texnum].addr;
	cube->ray.tex_y = (int)cube->ray.tex_pos & \
	(cube->mlx.wall_sprite[texnum].height - 1);
	cube->ray.tex_pos += cube->ray.f_step;
	my_mlx_pixel_put(&cube->mlx.walls, x, y, \
	new_addr[cube->ray.tex_y * \
	cube->mlx.wall_sprite[texnum].height + cube->ray.tex_x]);
}

void	select_wall_to_put_pixel(t_cube *cube)
{
	if (cube->ray.side == 1 && cube->ray.map_y < cube->player.y_pos)
		cube->ray.textnum = 2;
	else if (cube->ray.side == 1)
		cube->ray.textnum = 3;
	else if (cube->ray.side == 0 && cube->ray.map_x > cube->player.x_pos)
		cube->ray.textnum = 0;
	else
		cube->ray.textnum = 1;
}

void	trace_line_from_ray(t_cube *cube, int x)
{
	int	j;

	j = 0;
	select_wall_to_put_pixel(cube);
	while (++j < HEIGHT)
	{
		if (j < cube->ray.drawstart)
			my_mlx_pixel_put(&cube->mlx.walls, x, j, cube->mlx.hexa_color[0]);
		if (j >= cube->ray.drawstart && j <= cube->ray.drawend)
			get_tex_color(cube, cube->ray.textnum, x, j);
		else if (j > cube->ray.drawend)
			my_mlx_pixel_put(&cube->mlx.walls, x, j, cube->mlx.hexa_color[1]);
	}
}
