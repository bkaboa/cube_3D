#include "../includes/cube3D.h"

void	drawBackground(t_mlx *mlx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				my_mlx_pixel_put(&mlx->walls, x, y, mlx->hexa_color[0]);
			else
				my_mlx_pixel_put(&mlx->walls, x, y, mlx->hexa_color[1]);
			x++;
		}
		y++;
	}
}
