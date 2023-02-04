#include "../includes/cube3D.h"
#define KEY_LEFT 97
#define KEY_RIGHT 100
#define KEY_FORWARD 119
#define KEY_BACKWARD 115


void rotatePlayer(int keycode, t_player *player)
{
	double oldDirX;
	double oldPlaneX;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
		{
			printf("Rotate left\n");
			oldDirX = player->delta_x;
			player->delta_x = player->delta_x * cos(-ROTATIONSPEED) - player->delta_y * sin(-ROTATIONSPEED);
			player->delta_y = oldDirX * sin(-ROTATIONSPEED) + player->delta_y * cos(-ROTATIONSPEED);
			oldPlaneX  = player->planex;
			player->planex = player->planex * cos(-ROTATIONSPEED) - player->planey * sin(-ROTATIONSPEED);
			player->planey = oldPlaneX * sin(-ROTATIONSPEED) + player->planey * cos(-ROTATIONSPEED);
		}
		else
		{
			printf("Rotate right\n");
			oldDirX = player->delta_x;
			player->delta_x = player->delta_x * cos(ROTATIONSPEED) - player->delta_y * sin(ROTATIONSPEED);
			player->delta_y = oldDirX * sin(ROTATIONSPEED) + player->delta_y * cos(ROTATIONSPEED);
			oldPlaneX  = player->planex;
			player->planex = player->planex * cos(ROTATIONSPEED) - player->planey * sin(ROTATIONSPEED);
			player->planey = oldPlaneX * sin(ROTATIONSPEED) + player->planey * cos(ROTATIONSPEED);
		}
	}
}

void movePlayer(int keycode, t_player *player)
{
	if (keycode == KEY_FORWARD || keycode == KEY_BACKWARD)
	{
		if (keycode == KEY_FORWARD)
		{
			printf("J'avance, xpos %f ypos %f deltax %f deltay %f\n", player->xPos, player->yPos, player->delta_x, player->delta_y);
			player->xPos += player->delta_x * MOVESPEED;
			player->yPos += player->delta_y * MOVESPEED;
		}
		else
		{
			printf("Je recule, xpos %f ypos %f\n", player->xPos, player->yPos);
			player->xPos -= player->delta_x * MOVESPEED;
			player->yPos -= player->delta_y * MOVESPEED;	
		}
	}
}

int	control_hooks(int keycode, t_cube *cube)
{
	if (keycode != 47)
		cube->player.lastKey = keycode;
	printf("keycode %d\n", keycode);
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