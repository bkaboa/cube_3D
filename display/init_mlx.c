#include "../includes/display.h"

t_mlx_data	init_mlx(void)
{
	t_mlx_data mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cube3d");
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	mlx.addr = mlx_get_data_addr(mlx.img, \
	&mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	return (mlx);
}