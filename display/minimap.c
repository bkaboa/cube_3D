#include "../includes/cube3D.h"

void drawDirection(t_cube *cube, int x, int y, int length) 
{
	int i;

	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.planeX* i)), (y + (cube->player.planeY * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.minimap, (x - (cube->player.planeX* i)), (y - (cube->player.planeY * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.playerDir.dirX* i)), (y + (cube->player.playerDir.dirY * i)), C_GREEN);
		i++;
	}
}

void	drawPlayer(t_mlx *mlx, int x, int y)
{
	int j = -PLAYER_MINI_SIZE;

	while (j < PLAYER_MINI_SIZE)
	{
		int i = -PLAYER_MINI_SIZE;
		while (i < PLAYER_MINI_SIZE)
		{
			my_mlx_pixel_put(&mlx->minimap, (x + i), (y + j), C_GREEN);
			i++;
		}
		j++;
	}
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
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '0')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_BLUE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == ' ')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			x++;
		}
		y++;
	}
	protoRayDocument(cube);
	drawDirection(cube, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos), 50);
	drawPlayer(&cube->mlx, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos));
	// mlx_string_put(&cube->mlx.minimap.img, cube->mlx.mlx_win, 50, 50, C_RED, "HELLO boys");
}

void	updateMinimap(t_cube *cube)
{
	// printf("Player delta x = %f\n", cube->player.playerDir.dirX);
	// printf("Player delta y = %f\n", cube->player.playerDir.dirY);
	printf("Player posX = %f\n", cube->player.xPos);
	printf("Player posY = %f\n", cube->player.yPos);
	// printf("Player planeX = %f\n", cube->player.planeX);
	printf("Player planeY = %f\n --------------------------------\n", cube->player.planeY);

	cube->mlx.minimap.img = mlx_new_image(cube->mlx.mlx, (int)(cube->map_xlen * MINIMAP_RATIO), (int)(cube->map_ylen * MINIMAP_RATIO));
	cube->mlx.minimap.addr = mlx_get_data_addr(cube->mlx.minimap.img, \
	&cube->mlx.minimap.bits_per_pixel, &cube->mlx.minimap.line_length, &cube->mlx.minimap.endian);
	drawMinimap(cube);
	drawPlayer(&cube->mlx, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos));
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.walls.img, 0, 0);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.minimap.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.minimap.img);
}