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
		while (x < cube->map_xlen * MINIMAP_RATIO - 1 && (y % MINIMAP_RATIO) != 0)
		{
			dprintf(2, "x = %d, y = %d\n", x, y);
			if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '1' && (x % MINIMAP_RATIO) != 0)
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '0' && (x % MINIMAP_RATIO) != 0)
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_BLUE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == ' ' && (x % MINIMAP_RATIO) != 0)
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			x++;
		}
		y++;
	}
	drawDirection(cube, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos), 50);
	drawPlayer(&cube->mlx, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos));
	// mlx_string_put(&cube->mlx.minimap.img, cube->mlx.mlx_win, 50, 50, C_RED, "HELLO boys");
}

void	updateMinimap(t_cube *cube)
{
	// printf("------UPDATING PLAYER POS AND DIR------\n");
	// printf("player xPos = %f\nplayer yPos = %f\nplayer xDir = %f\n player yDir = %f\n", cube->player.xPos, cube->player.yPos, cube->player.playerDir.dirX, cube->player.playerDir.dirY);
	cube->mlx.minimap.img = mlx_new_image(cube->mlx.mlx, (int)(cube->map_xlen * MINIMAP_RATIO), (int)(cube->map_ylen * MINIMAP_RATIO));
	cube->mlx.minimap.addr = mlx_get_data_addr(cube->mlx.minimap.img, \
	&cube->mlx.minimap.bits_per_pixel, &cube->mlx.minimap.line_length, &cube->mlx.minimap.endian);
	drawMinimap(cube);
	protoRayDocument(cube);
	drawPlayer(&cube->mlx, minimapOffset(cube->player.xPos), minimapOffset(cube->player.yPos));
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.walls.img, 0, 0);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.minimap.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.minimap.img);
}
