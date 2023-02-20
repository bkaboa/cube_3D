#include "../includes/cube3D.h"

void drawDirection(t_cube *cube, int x, int y, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(&cube->mlx.walls, (x + (cube->player.planeY* i)), (y + (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.walls, (x - (cube->player.planeY* i)), (y - (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.walls, (x + (cube->player.playerDir.dirY* i)), (y + (cube->player.playerDir.dirX * i)), C_GREEN);
		i++;
	}
}

void drawPlayer(t_mlx *mlx, int x, int y)
{
	int j = -PLAYER_MINI_SIZE;

	while (j < PLAYER_MINI_SIZE)
	{
		int i = -PLAYER_MINI_SIZE;
		while (i < PLAYER_MINI_SIZE)
		{
			my_mlx_pixel_put(&mlx->walls, (x + i), (y + j), C_GREEN);
			i++;
		}
		j++;
	}
}

void drawMinimap(t_cube *cube)
{
	int y = 0;
	int x = 0;

	if (cube->mlx.minimap_ratio > 3)
	{
		while (y < cube->map_ylen * cube->mlx.minimap_ratio - 1)
		{
			x = 0;
			while (x < cube->map_xlen * cube->mlx.minimap_ratio - 1)
			{
				if (x / cube->mlx.minimap_ratio > ft_strlen(cube->map[y / cube->mlx.minimap_ratio]))
					;
				else if (y / cube->mlx.minimap_ratio > cube->map_ylen)
					;
				else if (cube->map[y / cube->mlx.minimap_ratio][x / cube->mlx.minimap_ratio] == '1')
					my_mlx_pixel_put(&cube->mlx.walls, x, y, C_WHITE);
				else if (cube->map[y / cube->mlx.minimap_ratio][x / cube->mlx.minimap_ratio] == '0')
					my_mlx_pixel_put(&cube->mlx.walls, x, y, C_BLUE);
				x++;
			}
			y++;
		}
		drawDirection(cube, Offset(*cube, cube->player.yPos), Offset(*cube, cube->player.xPos), 50);
		drawPlayer(&cube->mlx, Offset(*cube, cube->player.yPos), Offset(*cube, cube->player.xPos));
	}
}

void updateMinimap(t_cube *cube)
{
	cube->mlx.walls.img = mlx_new_image(cube->mlx.mlx, WIDTH, HEIGHT);
	cube->mlx.walls.addr = mlx_get_data_addr(cube->mlx.walls.img, &cube->mlx.walls.bits_per_pixel, \
		&cube->mlx.walls.line_length, &cube->mlx.walls.endian);
	raycasting_loop(cube);
	drawMinimap(cube);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.walls.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.walls.img);
}
