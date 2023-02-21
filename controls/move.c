#include "../includes/cube3D.h"

void movePlayerFront(t_cube *cube)
{
    if (cube->map[(int)(cube->player.xPos + cube->player.playerDir.dirX * MOVESPEED)][(int)(cube->player.yPos)] == '0')
        cube->player.xPos += cube->player.playerDir.dirX * MOVESPEED;
    if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos + cube->player.playerDir.dirY * MOVESPEED)] == '0')
        cube->player.yPos += cube->player.playerDir.dirY * MOVESPEED;
}

void movePlayerBack(t_cube *cube)
{
    if (cube->map[(int)(cube->player.xPos - cube->player.playerDir.dirX * MOVESPEED)][(int)(cube->player.yPos)] == '0')
        cube->player.xPos -= cube->player.playerDir.dirX * MOVESPEED;
    if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos - cube->player.playerDir.dirY * MOVESPEED)] == '0')
        cube->player.yPos -= cube->player.playerDir.dirY * MOVESPEED;
}

void moveStrafeLeft(t_cube *cube)
{
    if (cube->map[(int)(cube->player.xPos - cube->player.playerDir.dirY * MOVESPEED)][(int)(cube->player.yPos)] == '0')
        cube->player.xPos -= cube->player.playerDir.dirY * MOVESPEED;
    if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos + cube->player.playerDir.dirX * MOVESPEED)] == '0')
        cube->player.yPos += cube->player.playerDir.dirX * MOVESPEED;
}
void moveStrafeRight(t_cube *cube)
{
	if (cube->map[(int)(cube->player.xPos + cube->player.playerDir.dirY * MOVESPEED)][(int)(cube->player.yPos)] == '0')
		cube->player.xPos += cube->player.playerDir.dirY * MOVESPEED;
	if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos - cube->player.playerDir.dirX * MOVESPEED)] == '0')
		cube->player.yPos -= cube->player.playerDir.dirX * MOVESPEED;
}
