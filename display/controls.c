#include "player.h"
#define KEY_LEFT 0
#define KEY_RIGHT 2
#define KEY_FORWARD 13
#define KEY_BACKWARD 1


void rotatePlayer(int keycode, t_player *player)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
		{
			player.angle -= 0.1;
			if (player.angle < 0)
				player.angle += 2 * M_PI;
		}
		else
		{
			player.angle += 0.1;
			if (player.angle > 2 * M_PI)
				player.angle -= 2 * M_PI;
		}
		player.delta_x = cos(player.angle) * 5;
		player.delta_y = sin(player.angle) * 5;
	}
}

void movePlayer(int keycode, t_player *player)
{
	if (keycode == KEY_FORWARD || keycode == KEY_BACKWARD)
	{
		if (keycode == KEY_FORWARD)
		{
			player->xPos += player->delta_x;
			player->yPos += player->delta_y;
		}
		else
		{
			player->xPos -= player->delta_x;
			player->yPos -= player->delta_y;	
		}
	}
}

// int displayMinimap(int keycode)
// {

// }

// int control_hooks(int keycode, cub)
// {

// }

void control_hooks_loop(int keycode, t_player *player)
{
	if (player->lastKey != 60)
	{
		rotatePlayer(keycode, player);
		movePlayer(keycode, player);
	}
}

int	control_hooks_expose(int keycode, t_player *player)
{
	(void)keycode;
	player->lastKey = 60;
	return (0);
}