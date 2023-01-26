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
#include "includes/display.h"

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
	t_mlx_data mlx;
	t_player	player;
	t_my_map	map;

    char* array[] = {"1111111", "1001001", "1001001", "1000001", "100N001", "1000001", "1111111"};
	map.map = array;
	map.x_len = 7;
	map.y_len = 7;
	player = initPlayer();
	mlx = init_mlx();
	drawMinimap(&mlx, &map, player);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(fdf.mlx.win, 17, 1L << 0, &win_close, &fdf);
	mlx_hook_loop(mlx.win, &control_hooks_loop, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
