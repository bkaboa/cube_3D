#include "../includes/cube3D.h"

int key_press(int keycode, t_cube *cube)
{
    // if (keycode == 65307)
    // quit
    if (keycode == KEY_FORWARD)
        cube->keys[0] = 1;
    if (keycode == KEY_BACKWARD)
        cube->keys[1] = 1;
    if (keycode == KEY_RIGHT)
        cube->keys[2] = 1;
    if (keycode == KEY_LEFT)
        cube->keys[3] = 1;
    if (keycode == ARROW_LEFT)
        cube->keys[4] = 1;
    if (keycode == ARROW_RIGHT)
        cube->keys[5] = 1;
    return (0);
}

int key_release(int keycode, t_cube *cube)
{
    // if (keycode == 65307)
    // quit
    if (keycode == KEY_FORWARD)
        cube->keys[0] = 0;
    if (keycode == KEY_BACKWARD)
        cube->keys[1] = 0;
    if (keycode == KEY_RIGHT)
        cube->keys[2] = 0;
    if (keycode == KEY_LEFT)
        cube->keys[3] = 0;
    if (keycode == ARROW_LEFT)
        cube->keys[4] = 0;
    if (keycode == ARROW_RIGHT)
        cube->keys[5] = 0;
    return (0);
}

int check_mov(t_cube *cube)
{
    if (cube->keys[0] || cube->keys[1] || cube->keys[2] || cube->keys[3] || cube->keys[4] || cube->keys[5])
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}

void keys_move_player(t_cube *cube)
{
	if (check_mov(cube) == EXIT_SUCCESS)
    {
		if (cube->keys[0])
			movePlayerFront(cube);
		if (cube->keys[1])
			movePlayerBack(cube);
		if (cube->keys[2])
			moveStrafeRight(cube);
		if (cube->keys[3])
			moveStrafeLeft(cube);
		if (cube->keys[4])
			rotateLeft(&cube->player);
		if (cube->keys[5])
			rotateRight(&cube->player);
    }
}