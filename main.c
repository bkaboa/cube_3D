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

t_my_map	create_my_map(void)
{
	t_my_map rmap;
	char *map[6];
	map[0] = "1111111";
	map[0] = "1000001";
	map[0] = "1011001";
	map[0] = "10N0001";
	map[0] = "1000101";
	map[0] = "1111111";
	rmap.map = map;
	rmap.x_len = 8;
	rmap.y_len = 6;
	return (rmap);
}

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
	t_my_map	map;
	t_player	player;

	player = initPlayer();
	mlx = init_mlx();
	map = create_my_map();
	drawMinimap(&mlx, &map, player);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
