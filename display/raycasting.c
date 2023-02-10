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
	int x;
	float cameraX;
	t_vector rayDir;
	int mapX;
	int mapY;
	float sideDistX;
	float sideDistY;
	float deltaDistX;
	float deltaDistY;
	float perpWallDist;
	int stepX;
	int stepY;
	int hit; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

	hit = 0;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (float)WIDTH - 1;
		rayDir.dirX = cube->player.playerDir.dirX + cube->player.planeX * cameraX;
		rayDir.dirY = cube->player.playerDir.dirY + cube->player.planeY * cameraX;
		x++;
		//which box of the map we're in
		mapX = (int)cube->player.xPos;
		mapY = (int)cube->player.yPos;
		//length of ray from one x or y-side to next x or y-side
		deltaDistX = (rayDir.dirX == 0) ? 1e30 : fabs(1 / rayDir.dirX);
		deltaDistY = (rayDir.dirY == 0) ? 1e30 : fabs(1 / rayDir.dirY);


		//calculate step and initial sideDist
		if (rayDir.dirX < 0)
		{
			stepX = -1;
			sideDistX = (cube->player.xPos - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cube->player.xPos) * deltaDistX;
		}
		if (rayDir.dirY < 0)
		{
			stepY = -1;
			sideDistY = (cube->player.yPos - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cube->player.yPos) * deltaDistY;
		}
		//perform DDA
		// int i = 0;
		// while (i < 500)
		// {
		// 	my_mlx_pixel_put(&cube->mlx.minimap, (minimapOffset(cube->player.xPos) + (rayDir.dirX * i)), (minimapOffset(cube->player.yPos) + (rayDir.dirY * i)), C_RED);
		// 	i++;
		// }
		while (hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (cube->map[mapX][mapY] > 0)
				hit = 1; 	//Check if ray has hit a wall
		}
		if(side == 0) 
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		printf("perpWalldist %f\n", perpWallDist);
		int lineHeight = (int)(WALL_SIZE / perpWallDist);
		int drawStart = -lineHeight / 2 + WALL_SIZE / 2;
      	if(drawStart < 0)
			drawStart = 0;
      	int drawEnd = lineHeight / 2 + WALL_SIZE / 2;
      	if(drawEnd >= WALL_SIZE)
			drawEnd = WALL_SIZE - 1;
		printf("start %d\n", drawStart);
		printf("end %d\n", drawEnd);
		if (perpWallDist != 0)
		{
			while(drawStart != drawEnd)
			{
				my_mlx_pixel_put(&cube->mlx.walls, x, (drawStart + HEIGHT / 2), C_RED);
				drawStart--;
			}
		}
		x++;
	}
	return (perpWallDist);
}
