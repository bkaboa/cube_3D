#include "../includes/cube3D.h"



void init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx, WIDTH, HEIGHT, "cube3d");
}
