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
				my_mlx_pixel_put(&mlx->background, x, y, mlx->ceiling_color[0] << 16 | mlx->ceiling_color[1] << 8 | mlx->ceiling_color[2]);
			else
				my_mlx_pixel_put(&mlx->background, x, y, mlx->floor_color[0] << 16 | mlx->floor_color[1] << 8 | mlx->floor_color[2]);
			x++;
		}
		y++;
	}
}