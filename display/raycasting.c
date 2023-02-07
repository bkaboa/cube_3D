#include "../includes/cube3D.h"

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

}

void	drawOneRay()