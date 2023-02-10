#include "../includes/cube3D.h"
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_FORWARD 119
#define KEY_BACKWARD 115


void rotatePlayer(int keycode, t_player *player)
{
	float oldDirX;
	float oldplaneX;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
		{
			oldDirX = player->playerDir.dirX;
			player->playerDir.dirX = player->playerDir.dirX * cos(-ROTATIONSPEED) - player->playerDir.dirY * sin(-ROTATIONSPEED);
			player->playerDir.dirY = oldDirX * sin(-ROTATIONSPEED) + player->playerDir.dirY * cos(-ROTATIONSPEED);
			oldplaneX  = player->planeX;
			player->planeX = player->planeX * cos(-ROTATIONSPEED) - player->planeY * sin(-ROTATIONSPEED);
			player->planeY = oldplaneX * sin(-ROTATIONSPEED) + player->planeY * cos(-ROTATIONSPEED);
		}
		else
		{
			oldDirX = player->playerDir.dirX;
			player->playerDir.dirX = player->playerDir.dirX * cos(ROTATIONSPEED) - player->playerDir.dirY * sin(ROTATIONSPEED);
			player->playerDir.dirY = oldDirX * sin(ROTATIONSPEED) + player->playerDir.dirY * cos(ROTATIONSPEED);
			oldplaneX  = player->planeX;
			player->planeX = player->planeX * cos(ROTATIONSPEED) - player->planeY * sin(ROTATIONSPEED);
			player->planeY = oldplaneX * sin(ROTATIONSPEED) + player->planeY * cos(ROTATIONSPEED);
		}
	}
}

void movePlayer(int keycode, t_player *player)
{
	if (keycode == KEY_FORWARD || keycode == KEY_BACKWARD)
	{
		if (keycode == KEY_FORWARD)
		{
			player->xPos += player->playerDir.dirX * MOVESPEED;
			player->yPos += player->playerDir.dirY * MOVESPEED;
		}
		else
		{
			player->xPos -= player->playerDir.dirX * MOVESPEED;
			player->yPos -= player->playerDir.dirY * MOVESPEED;	
		}
	}
}

int	control_hooks(int keycode, t_cube *cube)
{
	if (keycode != 47)
		cube->player.lastKey = keycode;
	movePlayer(keycode, &cube->player);
	rotatePlayer(keycode, &cube->player);
	win_keyclose(keycode, cube);
	updateMinimap(cube);
	return (0);
}

int control_hooks_loop(int keycode, t_cube *cube)
{
	if (cube->player.lastKey != 60)
	{
		rotatePlayer(keycode, &cube->player);
		movePlayer(keycode, &cube->player);
		updateMinimap(cube);
	}
	return (0);
}

int	control_hooks_expose(int keycode, t_cube *cube)
{
	(void)keycode;
	cube->player.lastKey = 60;
	return (0);
}