#include "includes/cube3D.h"
#include "includes/struct.h"

void	init_ratio(t_cube *cube)
{
	if (cube->map_ylen > cube->map_xlen)
		cube->mlx.minimap_ratio = HEIGHT / 3 / cube->map_ylen;
	else
		cube->mlx.minimap_ratio = WIDTH / 3 / cube->map_xlen;
}

int main(int ac, char **av)
{
	t_cube		cube;
	ft_bzero((void*)&cube, sizeof(cube));
	init_mlx(&cube);
	file_map_parsing(ac, av, &cube);
	init_ratio(&cube);
	cube.map_xlen--;
	raycasting_loop(&cube);
	drawMinimap(&cube);
	mlx_put_image_to_window(cube.mlx.mlx, cube.mlx.mlx_win,cube.mlx.walls.img, 0, 0);
	mlx_hook(cube.mlx.mlx_win, 2, 1L << 0, &key_press, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, &click_close, &cube);
	mlx_hook(cube.mlx.mlx_win, 3, 1L << 1, &key_release, &cube);
	mlx_loop_hook(cube.mlx.mlx, &update_game, &cube);
	mlx_loop(cube.mlx.mlx);
	return (0);
}
