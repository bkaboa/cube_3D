#include "display.h"

t_my_map	create_my_map(void)
{
	
}

int main(void)
{
	t_mlx_data mlx;
	t_my_map	map;

	mlx = init_mlx();
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}