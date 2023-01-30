#include "../includes/cube3D.h"
#define KEY_LEFT 0
#define KEY_RIGHT 2
#define KEY_FORWARD 13
#define KEY_BACKWARD 1


void rotatePlayer(int keycode, t_player *player)
{
	double oldDirX;
	double oldPlaneX;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
		{
			oldDirX = player->delta_x;
			player->delta_x = player->delta_x * cos(ROTATIONSPEED) - player->delta_y * sin(ROTATIONSPEED);
			player->delta_y = oldDirX * sin(ROTATIONSPEED) + player->delta_y * cos(ROTATIONSPEED);
			oldPlaneX  = player->planex;
			player->planex = player->planex * cos(ROTATIONSPEED) - player->planey * sin(ROTATIONSPEED);
			player->planey = oldPlaneX * sin(ROTATIONSPEED) + player->planey * cos(ROTATIONSPEED);
		}
		else
		{
			oldDirX = player->delta_x;
			player->delta_x = player->delta_x * cos(-ROTATIONSPEED) - player->delta_y * sin(-ROTATIONSPEED);
			player->delta_y = oldDirX * sin(-ROTATIONSPEED) + player->delta_y * cos(-ROTATIONSPEED);
			oldPlaneX  = player->planex;
			player->planex = player->planex * cos(-ROTATIONSPEED) - player->planey * sin(-ROTATIONSPEED);
			player->planey = oldPlaneX * sin(-ROTATIONSPEED) + player->planey * cos(-ROTATIONSPEED);
		}
	}
}

void movePlayer(int keycode, t_player *player)
{
	if (keycode == KEY_FORWARD || keycode == KEY_BACKWARD)
	{
		if (keycode == KEY_FORWARD)
		{
			player->xPos += player->delta_x * MOVESPEED;
			player->yPos += player->delta_y * MOVESPEED;
		}
		else
		{
			player->xPos -= player->delta_x * MOVESPEED;
			player->yPos -= player->delta_y * MOVESPEED;	
		}
	}
}

// int displayMinimap(int keycode)
// {

// }

// int control_hooks(int keycode, cub)
// {

// }

int control_hooks_loop(int keycode, t_player *player)
{
	if (player->lastKey != 60)
	{
		rotatePlayer(keycode, player);
		movePlayer(keycode, player);
	}
	return (0);
}

int	control_hooks_expose(int keycode, t_player *player)
{
	(void)keycode;
	player->lastKey = 60;
	return (0);
}