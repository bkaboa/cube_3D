#ifndef HOOKS
#define HOOKS

#include "player.h"

void rotatePlayer(int keycode, t_player *player);
void movePlayer(int keycode, t_player *player);
void control_hooks_loop(int keycode, t_player *player);
int	control_hooks_expose(int keycode, t_player *player);


#endif HOOKS