#include "includes/cube3D.h"
#include "includes/struct.h"

//t_player	initPlayer(void)
//{
//	t_player	player;
//	player.xPos = 3 * CELL_SIZE + CELL_SIZE / 2;
//	player.yPos = 4 * CELL_SIZE + CELL_SIZE / 2;
//	player.angle = M_PI;
//	player.delta_x = cos(player.angle) * 5;
//	player.delta_y = sin(player.angle) * 5;
//	player.planex = 0;
//	player.planey = -1;
//	return (player);
//}
//
//
//
//int main(void)
//{
//	t_cube		cube;
//
//	cube.map_xlen = 7;
//	cube.map_ylen = 7;
//	init_mlx(&cube);
//    char* array[] = {"1111111", "1001001", "1001001", "1000001", "1000001", "1000001", "1111111"};
//	cube.player = initPlayer();
//	cube.map = array;
//	cube.mlx.ceiling_color[0] = 0xff;
//	cube.mlx.ceiling_color[1] = 0x00;
//	cube.mlx.ceiling_color[2] = 0xff;
//	cube.mlx.floor_color[0] = 0x0;
//	cube.mlx.floor_color[1] = 0x0;
//	cube.mlx.floor_color[2] = 0xff;
//
//	drawMinimap(&cube);
//	drawBackground(&cube.mlx);
//	my_mlx_pixel_put(&cube.mlx.walls, 500, 500, C_WHITE);
//	// mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.walls.img, 0, 0);
//	mlx_put_image_to_window(cube.mlx.mlx, cube.mlx.mlx_win, cube.mlx.background.img, 0, 0);
//	mlx_put_image_to_window(cube.mlx.mlx, cube.mlx.mlx_win, cube.mlx.minimap.img, 0, 0);
//	mlx_hook(cube.mlx.mlx_win, 17, 1L << 0, &click_close, &cube.mlx);
//	mlx_loop_hook(cube.mlx.mlx_win, &control_hooks_loop, &cube.player);
//	mlx_loop(cube.mlx.mlx);
//	return (0);
//}
//

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
