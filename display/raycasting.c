#include "../includes/cube3D.h"

float    raycasting_loop(t_cube *cube)
{
	t_ray ray;
	drawBackground(&cube->mlx);
	int x;

	x = 0;
	while (x < WIDTH)
	{
		ray.hit = 0;
		ray.cameraX = 2 * x / (float)WIDTH - 1;
		ray.rayDir.dirX = cube->player.playerDir.dirX + cube->player.planeX * ray.cameraX;
		ray.rayDir.dirY = cube->player.playerDir.dirY + cube->player.planeY * ray.cameraX;

		ray.mapX = (int)cube->player.xPos;//which box of the map we're in
		ray.mapY = (int)cube->player.yPos;

		ray.deltaDistX = sqrt(1 + (ray.rayDir.dirY * ray.rayDir.dirY) / (ray.rayDir.dirX * ray.rayDir.dirX));
		ray.deltaDistY = sqrt(1 + (ray.rayDir.dirX * ray.rayDir.dirX) / (ray.rayDir.dirY * ray.rayDir.dirY));


		int i = 0;
		if (ray.rayDir.dirX < 0)
		{
			ray.stepX = -1;
			ray.sideDistX = (cube->player.xPos - ray.mapX) * ray.deltaDistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sideDistX = (ray.mapX + 1.0 - cube->player.xPos) * ray.deltaDistX;
		}
		if (ray.rayDir.dirY < 0)
		{
			ray.stepY = -1;
			ray.sideDistY = (cube->player.yPos - ray.mapY) * ray.deltaDistY;
		}
		else
		{
			ray.stepY = 1;
			ray.sideDistY = (ray.mapY + 1.0 - cube->player.yPos) * ray.deltaDistY;
		}

		while (ray.hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (ray.sideDistX < ray.sideDistY)
			{
				ray.sideDistX += ray.deltaDistX;
				ray.mapX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.sideDistY += ray.deltaDistY;
				ray.mapY += ray.stepY;
				ray.side = 1;
			}
			if (cube->map[ray.mapX][ray.mapY] == '1')
				ray.hit = 1; // Check if ray has hit a wall
		}
		for (int i = 0; i < 50; i++)
		{
			my_mlx_pixel_put(&cube->mlx.minimap, Offset(cube->player.yPos ) + ray.rayDir.dirY * i , Offset(cube->player.xPos) + ray.rayDir.dirX * i, C_RED);
		}
		if (ray.side == 0)
			ray.perpWallDist = ((ray.mapX - cube->player.xPos + (1 - ray.stepX) / 2) / ray.rayDir.dirX);
		else
			ray.perpWallDist = ((ray.mapY - cube->player.yPos + (1 - ray.stepY) / 2) / ray.rayDir.dirY);
		ray.lineHeight = (int)(WALL_SIZE / ray.perpWallDist);
		ray.line = 0;
		if (ray.lineHeight > HEIGHT)
			ray.lineHeight = HEIGHT;
		while (ray.line < ray.lineHeight)
		{
			if (ray.side == 0)
			{
				my_mlx_pixel_put(&cube->mlx.walls, x, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
				my_mlx_pixel_put(&cube->mlx.walls, x + 1, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
				my_mlx_pixel_put(&cube->mlx.walls, x + 2, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
			}

			if (ray.side == 1)
			{
				my_mlx_pixel_put(&cube->mlx.walls, x, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
				my_mlx_pixel_put(&cube->mlx.walls, x + 1, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
				my_mlx_pixel_put(&cube->mlx.walls, x + 2, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
			}
			ray.line++;
		}
		x += 3;
	}
	return (0);
}
