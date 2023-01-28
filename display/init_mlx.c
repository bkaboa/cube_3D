#include "../includes/cube3D.h"

void init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cube3d");
	mlx->minimap.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->minimap.addr = mlx_get_data_addr(mlx->minimap.img, &mlx->minimap.bits_per_pixel, \
	&mlx->minimap.line_length, &mlx->minimap.endian);
	mlx->walls.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->walls.addr = mlx_get_data_addr(mlx->walls.img, &mlx->walls.bits_per_pixel, \
	&mlx->walls.line_length, &mlx->walls.endian);

}