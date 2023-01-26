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
#include "includes/include.h"

t_player	initPlayer(void)
{
	t_player	player;
	player.position.xTile = 3;
	player.position.yTile = 4;
	return (player);
}

int main(void)
{
	t_mlx_data mlx;
	t_player	player;
	t_my_map	map;

    char* array[] = {"  11111", "10001 1", "1110N011111", "1000111", "11111  "};
	map.map = array;
	map.x_len = 5;
	map.y_len = 5;
	player = initPlayer();
	mlx = init_mlx();
	drawMinimap(&mlx, &map, player);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
