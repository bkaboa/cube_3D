#include "../includes/cube3D.h"

void	drawPlayer(t_mlx *mlx, int x, int y, int color)
{
	int j = -PLAYER_MINI_SIZE;
	
	while (j < PLAYER_MINI_SIZE)
	{
		int i = -PLAYER_MINI_SIZE;
		while (i < PLAYER_MINI_SIZE)
		{
			my_mlx_pixel_put(&mlx->minimap, (y - i - MINIMAP_RATIO), (x - j + MINIMAP_RATIO), color);
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
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_BLUE);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == '0')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_RED);
			else if (cube->map[y / MINIMAP_RATIO][x / MINIMAP_RATIO] == ' ')
				my_mlx_pixel_put(&cube->mlx.minimap, x, y, C_WHITE);
			x++;
		}
		y++;
	}
	drawPlayer(&cube->mlx, (cube->player.xPos * MINIMAP_RATIO) / CELL_SIZE, (cube->player.yPos* MINIMAP_RATIO) / CELL_SIZE, 0x00FF00);
}