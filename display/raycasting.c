#include "../includes/cube3D.h"

void	init_step(t_cube *cube)
{
	if (cube->ray.rayDir.dirX < 0)
	{
		cube->ray.stepX = -1;
		cube->ray.sideDistX = (cube->player.xPos - cube->ray.mapX) * cube->ray.deltaDistX;
	}
	else
	{
		cube->ray.stepX = 1;
		cube->ray.sideDistX = (cube->ray.mapX + 1.0 - cube->player.xPos) * cube->ray.deltaDistX;
	}
	if (cube->ray.rayDir.dirY < 0)
	{
		cube->ray.stepY = -1;
		cube->ray.sideDistY = (cube->player.yPos - cube->ray.mapY) * cube->ray.deltaDistY;
	}
	else
	{
		cube->ray.stepY = 1;
		cube->ray.sideDistY = (cube->ray.mapY + 1.0 - cube->player.yPos) * cube->ray.deltaDistY;
	}
}

void define_height_start_end(t_cube *cube)
{
	cube->ray.lineHeight = (int)HEIGHT / cube->ray.perpWallDist;
	cube->ray.drawstart = -(cube->ray.lineHeight >> 1) + (HEIGHT >> 1) + 1;
	if (cube->ray.drawstart < 0)
		cube->ray.drawstart = 0;
	cube->ray.drawend = (cube->ray.lineHeight >> 1) + (HEIGHT >> 1) - 1;
	if (cube->ray.drawend >= HEIGHT)
		cube->ray.drawend = HEIGHT - 1;
}

void    raycasting_loop(t_cube *cube)
{
	t_ray ray;
	int x;

	x = 0;
	while (x < WIDTH)
	{
		cube->ray.hit = 0;
		cube->ray.cameraX = 2 * x / (float)WIDTH - 1;
		cube->ray.rayDir.dirX = cube->player.playerDir.dirX + cube->player.planeX * cube->ray.cameraX;
		cube->ray.rayDir.dirY = cube->player.playerDir.dirY + cube->player.planeY * cube->ray.cameraX;

		cube->ray.mapX = (int)cube->player.xPos;//which box of the map we're in
		cube->ray.mapY = (int)cube->player.yPos;

		cube->ray.deltaDistX = sqrt(1 + (cube->ray.rayDir.dirY * cube->ray.rayDir.dirY) / (cube->ray.rayDir.dirX * cube->ray.rayDir.dirX));
		cube->ray.deltaDistY = sqrt(1 + (cube->ray.rayDir.dirX * cube->ray.rayDir.dirX) / (cube->ray.rayDir.dirY * cube->ray.rayDir.dirY));

		init_step(cube);
		while (cube->ray.hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
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
				cube->ray.hit = 1; // Check if ray has hit a wall
		}

		if (cube->ray.side == 0)
			cube->ray.perpWallDist = ((cube->ray.mapX - cube->player.xPos + (1 - cube->ray.stepX) / 2) / cube->ray.rayDir.dirX);
		else
			cube->ray.perpWallDist = ((cube->ray.mapY - cube->player.yPos + (1 - cube->ray.stepY) / 2) / cube->ray.rayDir.dirY);
		select_wall_to_put_pixel(cube, x);
		define_height_start_end(cube);
		init_pixel_ray(cube, cube->ray.textnum);
		if (cube->ray.lineHeight > HEIGHT)
			cube->ray.lineHeight = HEIGHT;
		trace_line_from_ray(cube, x);
		x++;
	}
}