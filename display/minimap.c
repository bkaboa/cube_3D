#include "../includes/cube3D.h"

void circle_fill(t_img *img, int xc, int yc, int radius) 
{
	int x;
	int y;
	int d;

	x = 0;
	y = radius;
	d = 3 - 2 * radius;
	while (y >= x) {
		for (int i = xc - x; i <= xc + x; i++) {
			my_mlx_pixel_put(img, i, (yc + x), C_WHITE);
			my_mlx_pixel_put(img, i, (yc - x), C_WHITE);
		}
		for (int i = xc - y; i <= xc + y; i++) {
			my_mlx_pixel_put(img, i, (yc + x), C_WHITE);
			my_mlx_pixel_put(img, i, (yc - x), C_WHITE);
		}
		if (d < 0) {
			d = d + 4 * x + 6;
		} else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
}

void	drawPlayer(t_mlx *mlx, int x, int y, t_player player)
{
	circle_fill(&mlx->minimap, x, y, PLAYER_MINI_SIZE);
	circle_fill(&mlx->minimap, (x + (player.delta_x * 5)), (y + (player.delta_y * 5)), PLAYER_MINI_SIZE);
	// int j = -PLAYER_MINI_SIZE;

	// while (j < PLAYER_MINI_SIZE)
	// {
	// 	int i = -PLAYER_MINI_SIZE;
	// 	while (i < PLAYER_MINI_SIZE)
	// 	{
	// 		my_mlx_pixel_put(&mlx->minimap, (y - i - MINIMAP_RATIO), (x - j + MINIMAP_RATIO), color);
	// 		i++;
	// 	}
	// 	j++;
	// }
}

void	drawMinimap(t_cube *cube)
{
	int y = 0;
	int x = 0;
	while (y < cube->map_ylen * MINIMAP_RATIO - 1)
	{
		x = 0;
		while (x < cube->map_xlen * MINIMAP_RATIO - 1)
		{
			if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '1')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_BLUE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '0')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_RED);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == ' ')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			x++;
		}
		y++;
	}
	drawPlayer(&cube->mlx, (cube->player.xPos * MINIMAP_RATIO) / CELL_SIZE, (cube->player.yPos* MINIMAP_RATIO) / CELL_SIZE, cube->player);
}

void	updateMinimap(t_cube *cube)
{
	cube->mlx.minimap.img = mlx_new_image(cube->mlx.mlx, (int)(cube->map_xlen * MINIMAP_RATIO), (int)(cube->map_ylen * MINIMAP_RATIO));
	cube->mlx.minimap.addr = mlx_get_data_addr(cube->mlx.minimap.img, \
	&cube->mlx.minimap.bits_per_pixel, &cube->mlx.minimap.line_length, &cube->mlx.minimap.endian);
	drawMinimap(cube);
	drawPlayer(&cube->mlx, (cube->player.xPos * MINIMAP_RATIO) / CELL_SIZE, (cube->player.yPos* MINIMAP_RATIO) / CELL_SIZE, cube->player);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.minimap.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.minimap.img);
}