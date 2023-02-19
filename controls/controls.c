#include "../includes/cube3D.h"



void rotatePlayer(int keycode, t_player *player)
{
	float oldDirX;
	float oldplaneX;
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
	{
		if (keycode == ARROW_LEFT)
		{
			oldDirX = player->playerDir.dirX;
			player->playerDir.dirX = player->playerDir.dirX * cos(ROTATIONSPEED) - player->playerDir.dirY * sin(ROTATIONSPEED);
			player->playerDir.dirY = oldDirX * sin(ROTATIONSPEED) + player->playerDir.dirY * cos(ROTATIONSPEED);
			oldplaneX  = player->planeX;
			player->planeX = player->planeX * cos(ROTATIONSPEED) - player->planeY * sin(ROTATIONSPEED);
			player->planeY = oldplaneX * sin(ROTATIONSPEED) + player->planeY * cos(ROTATIONSPEED);
		}
		else
		{
			oldDirX = player->playerDir.dirX;
			player->playerDir.dirX = player->playerDir.dirX * cos(-ROTATIONSPEED) - player->playerDir.dirY * sin(-ROTATIONSPEED);
			player->playerDir.dirY = oldDirX * sin(-ROTATIONSPEED) + player->playerDir.dirY * cos(-ROTATIONSPEED);
			oldplaneX  = player->planeX;
			player->planeX = player->planeX * cos(-ROTATIONSPEED) - player->planeY * sin(-ROTATIONSPEED);
			player->planeY = oldplaneX * sin(-ROTATIONSPEED) + player->planeY * cos(-ROTATIONSPEED);
		}
	}
}

void movePlayerFrontBack(int keycode, t_cube *cube)
{
	if (keycode == KEY_FORWARD || keycode == KEY_BACKWARD)
	{
		if (keycode == KEY_FORWARD)
		{
			if (cube->map[(int)(cube->player.xPos + cube->player.playerDir.dirX * MOVESPEED)][(int)(cube->player.yPos)] == '0')
				cube->player.xPos += cube->player.playerDir.dirX * MOVESPEED;
			if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos + cube->player.playerDir.dirY * MOVESPEED)] == '0')
				cube->player.yPos += cube->player.playerDir.dirY * MOVESPEED;
		}
		else
		{
			if (cube->map[(int)(cube->player.xPos - cube->player.playerDir.dirX * MOVESPEED)][(int)(cube->player.yPos)] == '0')
				cube->player.xPos -= cube->player.playerDir.dirX * MOVESPEED;
			if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos - cube->player.playerDir.dirY * MOVESPEED)] == '0')
				cube->player.yPos -= cube->player.playerDir.dirY * MOVESPEED;
		}
	}
}

void movePlayerSides(int keycode, t_cube *cube)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		if (keycode == KEY_LEFT)
		{
			if (cube->map[(int)(cube->player.xPos - cube->player.playerDir.dirY * MOVESPEED)][(int)(cube->player.yPos)] == '0')
				cube->player.xPos -= cube->player.playerDir.dirY * MOVESPEED;
			if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos + cube->player.playerDir.dirX * MOVESPEED)] == '0')
				cube->player.yPos += cube->player.playerDir.dirX * MOVESPEED;
		}
		else
		{
			if (cube->map[(int)(cube->player.xPos + cube->player.playerDir.dirY * MOVESPEED)][(int)(cube->player.yPos)] == '0')
				cube->player.xPos += cube->player.playerDir.dirY * MOVESPEED;
			if (cube->map[(int)(cube->player.xPos)][(int)(cube->player.yPos - cube->player.playerDir.dirX * MOVESPEED)] == '0')
				cube->player.yPos -= cube->player.playerDir.dirX * MOVESPEED;
		}
	}
}

int	control_hooks(int keycode, t_cube *cube)
{
	if (keycode != 47)
		cube->player.lastKey = keycode;
	movePlayerFrontBack(keycode, cube);
	movePlayerSides(keycode, cube);
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
		movePlayerFrontBack(keycode, cube);
		movePlayerSides(keycode, cube);
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
