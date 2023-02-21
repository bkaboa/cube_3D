#include "../includes/cube3D.h"

int init_pixel_ray(t_cube *cube, int textnum)
{
	cube->ray.ty_step = (HEIGHT / 10) / cube->ray.lineHeight;
	if (cube->ray.side == 0)
		cube->ray.wallX = cube->player.yPos + cube->ray.perpWallDist * cube->ray.rayDir.dirY;
	else
		cube->ray.wallX = cube->player.xPos + cube->ray.perpWallDist * cube->ray.rayDir.dirX;
	cube->ray.wallX -= floorf(cube->ray.wallX);
	cube->ray.texX = (int)(cube->ray.wallX * (float)cube->mlx.wall_sprite[textnum].width);
	cube->ray.texX = cube->mlx.wall_sprite[textnum].width - cube->ray.texX - 1;
	cube->ray.f_step = 1.0 * cube->mlx.wall_sprite[textnum].height / cube->ray.lineHeight / 1.0;
	cube->ray.tex_pos = (cube->ray.drawstart - (HEIGHT / 2) + (cube->ray.lineHeight / 2)) * cube->ray.f_step;

}

void get_tex_color(t_cube *cube, int texnum, int x, int y)
{
	int *new_addr;

	new_addr = (int *)cube->mlx.wall_sprite[texnum].addr;
	cube->ray.texY = (int)cube->ray.tex_pos & (cube->mlx.wall_sprite[texnum].height - 1);
	cube->ray.tex_pos += cube->ray.f_step;
	my_mlx_pixel_put(&cube->mlx.walls, x, y, new_addr[cube->ray.texY * cube->mlx.wall_sprite[texnum].height + cube->ray.texX]);
}

void select_wall_to_put_pixel(t_cube *cube, int x)
{
	if (cube->ray.side == 1 && cube->ray.mapY < cube->player.yPos)//est
		cube->ray.textnum = 2;
	else if (cube->ray.side == 1)//west
		cube->ray.textnum = 3;
	else if (cube->ray.side == 0 && cube->ray.mapX > cube->player.xPos) //north
		cube->ray.textnum = 0;
	else //sud
		cube->ray.textnum = 1;
}

void trace_line_from_ray(t_cube *cube, int x)
{
	int j;

	j = 0;
	select_wall_to_put_pixel(cube, x);
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
