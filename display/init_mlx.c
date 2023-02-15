#include "../includes/cube3D.h"



void init_mlx(t_cube *cube)
{
	cube->mlx.mlx = mlx_init();
	cube->mlx.mlx_win = mlx_new_window(cube->mlx.mlx, WIDTH, HEIGHT, "cube3d");
	cube->mlx.minimap.img = mlx_new_image(cube->mlx.mlx, (int)(cube->map_xlen * MINIMAP_RATIO), (int)(cube->map_ylen * MINIMAP_RATIO));
	cube->mlx.minimap.addr = mlx_get_data_addr(cube->mlx.minimap.img, &cube->mlx.minimap.bits_per_pixel, \
	&cube->mlx.minimap.line_length, &cube->mlx.minimap.endian);
	cube->mlx.walls.img = mlx_new_image(cube->mlx.mlx, WIDTH, HEIGHT);
	cube->mlx.walls.addr = mlx_get_data_addr(cube->mlx.walls.img, &cube->mlx.walls.bits_per_pixel, \
	&cube->mlx.walls.line_length, &cube->mlx.walls.endian);
}