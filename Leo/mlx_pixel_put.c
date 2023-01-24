#include "display.h"

void    my_mlx_pixel_put(t_mlx_data *data, float x, float y, int color)
{
	char    *dst;

	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
			x = roundf(x);
			y = roundf(y);
			dst = data->addr + (int)(y * data->line_length + \
			x * (data->bits_per_pixel / 8));
			*(unsigned int *) dst = color;
	}
}