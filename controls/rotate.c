#include "../includes/cube3D.h"

void rotateLeft(t_player *player)
{
    float oldDirX;
    float oldplaneX;
	oldDirX = player->playerDir.dirX;
	player->playerDir.dirX = player->playerDir.dirX * cos(ROTATIONSPEED) - player->playerDir.dirY * sin(ROTATIONSPEED);
	player->playerDir.dirY = oldDirX * sin(ROTATIONSPEED) + player->playerDir.dirY * cos(ROTATIONSPEED);
	oldplaneX = player->planeX;
	player->planeX = player->planeX * cos(ROTATIONSPEED) - player->planeY * sin(ROTATIONSPEED);
	player->planeY = oldplaneX * sin(ROTATIONSPEED) + player->planeY * cos(ROTATIONSPEED);

}

void rotateRight(t_player *player)
{
	float oldDirX;
	float oldplaneX;
	oldDirX = player->playerDir.dirX;
	player->playerDir.dirX = player->playerDir.dirX * cos(-ROTATIONSPEED) - player->playerDir.dirY * sin(-ROTATIONSPEED);
	player->playerDir.dirY = oldDirX * sin(-ROTATIONSPEED) + player->playerDir.dirY * cos(-ROTATIONSPEED);
	oldplaneX = player->planeX;
	player->planeX = player->planeX * cos(-ROTATIONSPEED) - player->planeY * sin(-ROTATIONSPEED);
	player->planeY = oldplaneX * sin(-ROTATIONSPEED) + player->planeY * cos(-ROTATIONSPEED);
}