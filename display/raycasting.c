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
	drawBackground(&cube->mlx);
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

	hit = 0;
	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (float)WIDTH - 1;
		rayDir.dirX = cube->player.playerDir.dirX + cube->player.planeX * cameraX;
		rayDir.dirY = cube->player.playerDir.dirY + cube->player.planeY * cameraX;

		mapX = (int)cube->player.xPos;//which box of the map we're in
		mapY = (int)cube->player.yPos;
		deltaDistX = (rayDir.dirX == 0) ? 1e30 : fabs(1 / rayDir.dirX);//length of ray from one x or y-side to next x or y-side
		deltaDistY = (rayDir.dirY == 0) ? 1e30 : fabs(1 / rayDir.dirY);

		int side; //was a NS or a EW wall hit?
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
			if (cube->map[mapX][mapY] != 0)
				hit = 1; 	//Check if ray has hit a wall
		}
		int i = 0;
		if(side == 0) 
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		printf("perpWalldist %f\n", perpWallDist);
		if(perpWallDist == 0)
			perpWallDist = -1;
		int lineHeight = (int)(WALL_SIZE / perpWallDist) * -1;
		while (i < distance)
		{
			my_mlx_pixel_put(&cube->mlx.minimap, (minimapOffset(cube->player.xPos) + (rayDir.dirX * i)), (minimapOffset(cube->player.yPos) + (rayDir.dirY * i)), C_RED);
			i++;
		}
		printf("lineheight = %d\n", lineHeight);
		int line = 0;
		while(line < lineHeight)
		{
			my_mlx_pixel_put(&cube->mlx.walls, x, (line + (-lineHeight / 2) + (HEIGHT / 2)), C_RED);
			line++;
		}
		x++;
	}
	return (perpWallDist);
}
