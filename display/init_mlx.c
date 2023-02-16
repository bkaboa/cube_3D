#include "../includes/cube3D.h"



void init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx, WIDTH, HEIGHT, "cube3d");
	cube->mlx.walls.img = mlx_new_image(cube->mlx.mlx, WIDTH, HEIGHT);
	cube->mlx.walls.addr = mlx_get_data_addr(cube->mlx.walls.img, &cube->mlx.walls.bits_per_pixel, \
	&cube->mlx.walls.line_length, &cube->mlx.walls.endian);
}