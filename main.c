/*
#include "includes/header_struct_object.h"
#include "includes/parsing.h"

int main(int ac, char **av)
{
	t_cube	map;

	if (ac != 2)
		exit_error(ARG_ERROR_MSG);
	file_map_parsing(av[1], map);
	return (0);
}
*/

# include "includes/cube3D.h"

t_player	initPlayer(void)
{
	t_player	player;
	player.xPos = 3;
	player.yPos = 5;
	player.angle = M_PI;
	player.delta_x = cos(player.angle) * 5;
	player.delta_y = sin(player.angle) * 5;
	return (player);
}


int main(void)
{
	t_mlx		mlx;
	t_cube		cube;

	init_mlx(&mlx);
    char* array[] = {"1111111", "1001001", "1001001", "1000001", "1000001", "1000001", "1111111"};
	cube.map_xlen = 7;
	cube.map_ylen = 7;
	cube.player = initPlayer();
	cube.map = array;
	drawMinimap(&mlx, &cube);
	my_mlx_pixel_put(&mlx.walls, 500, 500, C_WHITE);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.minimap.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 1L << 0, &click_close, &mlx);
	// mlx_loop_hook(mlx.mlx_win, &control_hooks_loop, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
