#include "../includes/cube3D.h"

void	raycast(t_cube *cube)
{
	int r,mx,my,mp,dof; float rx,ry,rdx,rdy,xo,yo;
	rdx = cube->player.dirX;
	rdy = cube->player.dirY;
	for (r = 0; r < 1; r++)
	{
		//check horizontal lines//
		dof=0;
		if (rdy < 0)
		{

		}
	}
}

int	get_wall_dist()
{

}

void    protoRay(t_cube *cube)
{
	int x;
	float cameraX;
	float rayDirX;
	float rayDirY;

	x = 0;
	while (x < WIDTH)
	{
		cameraX = 2 * x / (float)WIDTH - 1;
		rayDirX = cube->player.dirX + cube->player.planeX * cameraX;
		rayDirY = cube->player.dirY + cube->player.planeY * cameraX;
		x++;
	}
	//which box of the map we're in
	int mapX = (int)cube->player.xPos;
	int mapY = (int)cube->player.yPos;

	//length of ray from current position to next x or y-side
	float sideDistX;
	float sideDistY;
	
	//length of ray from one x or y-side to next x or y-side
	float deltaDistX = (rayDirX == 0) ? 1e30 : abs(1 / rayDirX);
	float deltaDistY = (rayDirY == 0) ? 1e30 : abs(1 / rayDirY);
	float perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?
	//calculate step and initial sideDist
	if (rayDirX < 0)
	{
	stepX = -1;
	sideDistX = (cube->player.xPos - mapX) * deltaDistX;
	}
	else
	{
	stepX = 1;
	sideDistX = (mapX + 1.0 - cube->player.xPos) * deltaDistX;
	}
	if (rayDirY < 0)
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
	//Check if ray has hit a wall
	if (cube->map[mapX][mapY] > 0) hit = 1;
	}
	if(side == 0) perpWallDist = (sideDistX - deltaDistX);
	else          perpWallDist = (sideDistY - deltaDistY);
}

void	drawOneRay()