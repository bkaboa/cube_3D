#include "../includes/display.h"

void	drawSquare(t_mlx_data *data, int x, int y, int color)
{
	int j = 0;
	int i = 0;
	while (j < MINIMAPTILESIZE)
	{
		i = 0;
		while (i < MINIMAPTILESIZE)
		{
			my_mlx_pixel_put(data, (x + i), (y + j), color);
			i++;
		}
		j++;
	}
	return;
}

void	drawMinimap(t_mlx_data *data, t_my_map *map, t_player player)
{
	(void)player;
	int y = 0;
	int x = 0;
	int miniX;
	int miniY = MINIMAPY;
	while (y < map->y_len)
	{
		printf("char = %c\n", map->map[0][1]);
		x = 0;
		miniX = MINIMAPX;
		while (x < map->x_len)
		{
			printf("Gonna draw on %d %d with mini %d %d\n", x, y, miniX, miniY);
			printf("char y[%d] x[%d] = %c\n", y, x, map->map[y][x]);
			if (map->map[y][x] == '1')
				my_mlx_pixel_put(data, miniX, miniY, C_WHITE);
				//drawSquare(data, miniX, miniY, C_WHITE);
			else if (map->map[y][x] == '0')
				my_mlx_pixel_put(data, miniX, miniY, C_BLUE);
				//drawSquare(data, miniX, miniY, C_BLUE);
			else if (map->map[y][x] == 'N')
				my_mlx_pixel_put(data, miniX, miniY, C_RED);
				//drawSquare(data, miniX, miniY, C_RED);
			miniX += MINIMAPTILESIZE;
			x++;
		}
		miniY += MINIMAPTILESIZE;
		y++;
	}
	return;
}