#include "../includes/cube3D.h"

// void	raycastVideo(t_cube *cube)
// {
// 	int r,mx,my,mp,dof; float rx,ry,xo,yo;
// 	t_vector rayDir;
// 	rayDir.dirX = cube->player.playerDir.dirX;
// 	rayDir.dirY = cube->player.playerDir.dirY;
// 	for (r = 0; r < 1; r++)
// 	{
// 		//check horizontal lines//
// 		dof=0;
// 		float aTan = -1/tan(rayDir.dirX + rayDir.dirY);
// 		if (rayDir.dirY < 0) //raydir is pointing up
// 		{
// 			ry = (((int)cube->player.yPos>>6)<<6)-0.0001;
// 			rx = (cube->player.yPos - ry) * aTan + cube->player.xPos;
// 			yo = -64;
// 			xo = -yo*aTan;
// 		}
// 		else if (rayDir.dirY > 0) //raydir is pointing down
// 		{
// 			ry = (((int)cube->player.yPos>>6)<<6)+64;
// 			rx = (cube->player.yPos - ry) * aTan + cube->player.xPos;
// 			yo = 64;
// 			xo = -yo*aTan;
// 		}
// 		else if (rayDir.dirY == 0 && (rayDir.dirX == 1 || rayDir.dirX == -1)) //raydir is looking straight left or right
// 		{
// 			while (dof < 8)
// 			{
// 				mx = (int)(rx)>>6;
// 				my = (int)(ry)>>6;
// 				mp = my * cube->map_xlen + mx;
// 				if (mp < cube->map_xlen * cube->map_ylen && cube->map[mp])
// 			}
// 		}
// 	}
// }

// int	get_wall_dist()
// {

// }

// void drawDirection(t_cube *cube, int x, int y, int length) 
// {
// 	int i;

// 	i = 0;
// 	while (i < length)
// 	{
// 		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.planeX* i)), (y + (cube->player.planeY * i)), C_RED);
// 		my_mlx_pixel_put(&cube->mlx.minimap, (x - (cube->player.planeX* i)), (y - (cube->player.planeY * i)), C_RED);
// 		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.playerDir.dirX* i)), (y + (cube->player.playerDir.dirY * i)), C_GREEN);
// 		i++;
// 	}
// }


float    protoRayDocument(t_cube *cube)
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
		while (i < 50)
		{
			if (x == 0)
				my_mlx_pixel_put(&cube->mlx.minimap, minimapOffset(cube->player.yPos) + i * ray.rayDir.dirY, minimapOffset(cube->player.xPos) + i * ray.rayDir.dirX, C_GREEN);
			if (x == WIDTH - 1)
			 	my_mlx_pixel_put(&cube->mlx.minimap, minimapOffset(cube->player.yPos) + i * ray.rayDir.dirY, minimapOffset(cube->player.xPos) + i * ray.rayDir.dirX, C_RED);
			i++;
		}

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
		if (ray.side == 0)
			ray.perpWallDist = (ray.sideDistX - ray.deltaDistX);
		else
			ray.perpWallDist = (ray.sideDistY - ray.deltaDistY);
		if (ray.perpWallDist == 0)
			ray.perpWallDist = -1;
		ray.lineHeight = (int)(WALL_SIZE / ray.perpWallDist);

		ray.line = 0;
		while (ray.line < ray.lineHeight)
		{
			if (ray.side == 0)
				my_mlx_pixel_put(&cube->mlx.walls, x, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_RED);
			if (ray.side == 1)
				my_mlx_pixel_put(&cube->mlx.walls, x, (ray.line + (-ray.lineHeight / 2) + (HEIGHT / 2)), C_GREEN);
			ray.line++;
		}
		x++;
	}
	return (0);
}
