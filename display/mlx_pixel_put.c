#include "../includes/cube3D.h"

void	my_mlx_pixel_put(t_img *img, float x, float y, int color)
{
	char	*dst;

	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		x = roundf(x);
		y = roundf(y);
		dprintf(2, "%p\n", dst);
		dst = img->addr + (int)(y * img->line_length + \
		x * (img->bits_per_pixel >> 3));
		dprintf(2, "%p\n", dst);
		dprintf(2, "Ox%x", color);
		*(unsigned int *) dst = color;
	}
}
