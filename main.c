#include "includes/cube3D.h"

int main(int ac, char **av)
{
	t_cube		cube;
	ft_bzero((void*)&cube, sizeof(cube));
	init_mlx(&cube);
	file_map_parsing(ac, av, &cube);
	cube.map_xlen--;
	cube.mlx.minimap.img = mlx_new_image(cube.mlx.mlx, (int)(cube.map_xlen * MINIMAP_RATIO), (int)(cube.map_ylen * MINIMAP_RATIO));
	cube.mlx.minimap.addr = mlx_get_data_addr(cube.mlx.minimap.img,
											   &cube.mlx.minimap.bits_per_pixel, &cube.mlx.minimap.line_length, &cube.mlx.minimap.endian);
	drawMinimap(&cube);
	raycasting_loop(&cube);
	mlx_put_image_to_window(cube.mlx.mlx, cube.mlx.mlx_win,cube.mlx.walls.img, 0, 0);
	mlx_put_image_to_window(cube.mlx.mlx, cube.mlx.mlx_win, cube.mlx.minimap.img, 0, 0);
	mlx_hook(cube.mlx.mlx_win, 2, 1L << 0, &control_hooks, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, &click_close, &cube);
	mlx_hook(cube.mlx.mlx_win, 3, 1L << 1, &control_hooks_expose, &cube);
	mlx_loop_hook(cube.mlx.mlx_win, &control_hooks_loop, &cube);
	mlx_loop(cube.mlx.mlx);
	return (0);
}
