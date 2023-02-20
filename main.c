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
	updateMinimap(&cube);
	mlx_hook(cube.mlx.mlx_win, 2, 1L << 0, &control_hooks, &cube);
	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, &click_close, &cube);
	mlx_hook(cube.mlx.mlx_win, 3, 1L << 1, &control_hooks_expose, &cube);
	mlx_loop_hook(cube.mlx.mlx_win, &control_hooks_loop, &cube);
	mlx_loop(cube.mlx.mlx);
	return (0);
}
