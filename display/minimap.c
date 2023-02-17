#include "../includes/cube3D.h"

void drawDirection(t_cube *cube, int x, int y, int length) 
{
	int i;

	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.planeY* i)), (y + (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.minimap, (x - (cube->player.planeY* i)), (y - (cube->player.planeX * i)), C_RED);
		my_mlx_pixel_put(&cube->mlx.minimap, (x + (cube->player.playerDir.dirY* i)), (y + (cube->player.playerDir.dirX * i)), C_GREEN);
		i++;
	}
}

void	drawPlayer(t_mlx *mlx, int x, int y)
{
	int j = -PLAYER_MINI_SIZE;
	x = (int)MINIMAP_LENGHT / 2;
	y = (int)MINIMAP_HIGHT / 2;

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
	int	y2 = (cube->player.xPos / 2) * MINIMAP_HIGHT;
	int	x2 = (cube->player.yPos / 2) * MINIMAP_LENGHT;
	while (y < MINIMAP_HIGHT)
	{
		x = 0;
		x2 = (cube->player.yPos / 2) * MINIMAP_LENGHT;
		while (x < MINIMAP_LENGHT)
		{
			if (cube->map[y2 / MINIMAP_HIGHT][x2 / MINIMAP_LENGHT] == '1')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			else if (cube->map[y2 / MINIMAP_HIGHT][x2 / MINIMAP_LENGHT] == '0')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_BLUE);
			else if (cube->map[y2 / MINIMAP_HIGHT][x2 / MINIMAP_LENGHT] == ' ')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			x2++;
			x++;
		}
		y2++;
		y++;
	}
	drawDirection(cube, MINIMAP_LENGHT / 2, MINIMAP_HIGHT / 2, 50);
	// drawPlayer(&cube->mlx, Offset(cube->player.yPos), Offset(cube->player.xPos));
	// mlx_string_put(&cube->mlx.minimap.img, cube->mlx.mlx_win, 50, 50, C_RED, "HELLO boys");
}

void	updateMinimap(t_cube *cube)
{
	// printf("------UPDATING PLAYER POS AND DIR------\n");
	// printf("player xPos = %f\nplayer yPos = %f\nplayer xDir = %f\n player yDir = %f\n", cube->player.xPos, cube->player.yPos, cube->player.playerDir.dirX, cube->player.playerDir.dirY);
	cube->mlx.minimap.img = mlx_new_image(cube->mlx.mlx, (int)(MINIMAP_LENGHT), (int)(MINIMAP_HIGHT));
	cube->mlx.minimap.addr = mlx_get_data_addr(cube->mlx.minimap.img, \
	&cube->mlx.minimap.bits_per_pixel, &cube->mlx.minimap.line_length, &cube->mlx.minimap.endian);
	drawMinimap(cube);
	raycasting_loop(cube);
	drawPlayer(&cube->mlx, Offset(cube->player.yPos), Offset(cube->player.xPos));
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.walls.img, 0, 0);
	mlx_put_image_to_window(cube->mlx.mlx, cube->mlx.mlx_win, cube->mlx.minimap.img, 0, 0);
	mlx_destroy_image(cube->mlx.mlx, cube->mlx.minimap.img);
}
