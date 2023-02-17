#include "../includes/cube3D.h"

float    raycasting_loop(t_cube *cube)
{
	t_ray ray;
	drawBackground(&cube->mlx);
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


		int i = 0;
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
		for (int i = 0; i < 50; i++)
		{
			my_mlx_pixel_put(&cube->mlx.minimap, Offset(cube->player.yPos ) + cube->ray.rayDir.dirY * i , Offset(cube->player.xPos) + cube->ray.rayDir.dirX * i, C_RED);
		}
		if (cube->ray.side == 0)
			cube->ray.perpWallDist = ((cube->ray.mapX - cube->player.xPos + (1 - cube->ray.stepX) / 2) / cube->ray.rayDir.dirX);
		else
			cube->ray.perpWallDist = ((cube->ray.mapY - cube->player.yPos + (1 - cube->ray.stepY) / 2) / cube->ray.rayDir.dirY);
		cube->ray.lineHeight = (int)(WALL_SIZE / cube->ray.perpWallDist);
		cube->ray.line = 0;
		if (cube->ray.lineHeight > HEIGHT)
			cube->ray.lineHeight = HEIGHT;
		while (cube->ray.line < cube->ray.lineHeight)
		{
			if (cube->ray.side == 0)
			{
				my_mlx_pixel_put(&cube->mlx.walls, x, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
				my_mlx_pixel_put(&cube->mlx.walls, x + 1, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
				my_mlx_pixel_put(&cube->mlx.walls, x + 2, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
			}

			if (cube->ray.side == 1)
			{
				my_mlx_pixel_put(&cube->mlx.walls, x, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
				my_mlx_pixel_put(&cube->mlx.walls, x + 1, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
				my_mlx_pixel_put(&cube->mlx.walls, x + 2, (cube->ray.line + (-cube->ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
			}
			cube->ray.line++;
		}
		x += 3;
	}
	return (0);
}
