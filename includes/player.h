#ifndef PLAYER
#define PLAYER

#include "include.h"
#include "display.h"

#define MOVESPEED 1;
#define FOV		45;
#define ROTATIONSPEED 1;

typedef struct s_player
{
	float 	xPos;
	float 	yPos;
	float	angle;
	float	delta_x;
	float	delta_y;
	int		lastKey;
}	t_player;

#endif