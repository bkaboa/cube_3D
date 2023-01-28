#include "../includes/cube3D.h"

void	drawSquare(t_mlx *mlx, int x, int y, int color)
{
	int j = 0;
	int i = 0;
	while (j < MINIMAPTILESIZE)
	{
		i = 0;
		while (i < MINIMAPTILESIZE)
		{
			my_mlx_pixel_put(&mlx->minimap, (x + i), (y + j), color);
			i++;
		}
		j++;
	}
	return;
}

void	drawMinimap(t_mlx *mlx, t_cube *cube)
{
	int y = 0;
	int x = 0;
	int miniX;
	int miniY = MINIMAPY;
	while (y < cube->map_ylen)
	{
		x = 0;
		miniX = MINIMAPX;
		while (x < cube->map_xlen)
		{
			if (cube->map[y][x] == '1')
				drawSquare(mlx, miniX, miniY, C_WHITE);
			else if (cube->map[y][x] == '0' || cube->map[y][x] == 'N')
				drawSquare(mlx, miniX, miniY, C_BLUE);
			else if (cube->map[y][x] == ' ')
				drawSquare(mlx, miniX, miniY, 0x000000);
			miniX += MINIMAPTILESIZE;
			x++;
		}
		miniY += MINIMAPTILESIZE;
		y++;
	}
	return;
}