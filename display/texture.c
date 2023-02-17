#include "../includes/cube3D.h"

// void texture_abucia(t_cube *cube, t_sprite *sprite, int new_x, int j)
// {
// 	int *new_addr;

// 	new_addr = (int *)sprite->addr;
// 	cube->ray.texDirY = (int)cube->ray.tex_pos & (sprite->height - 1);
// 	cube->ray.tex_pos += cube->ray.f_step;
// 	if (cube->ray.side == 1)
// 		my_mlx_pixel_put(&cube->mlx.walls, new_x, j,
// 						 new_addr[cube->ray.texDirY * sprite->height + cube->ray.texDirX]);
// 	else
// 		my_mlx_pixel_put(&cube->mlx.walls, new_x, j,
// 						 new_addr[cube->ray.texDirX * sprite->height + cube->ray.texDirX]);
// }

int	get_text_pixel(t_sprite *sprite, int x, int y)
{
	int color;

	if (x < 0 || x >= sprite->width)
		return (0);
	if (y < 0 || y >= sprite->height)
		return (0);

	color = (*(int *)sprite->addr + (y * sprite->line_length) + (x * sprite->bits_per_pixel / 8));
	return (color);
}

int get_tex_x(t_cube *cube, t_ray *ray, t_sprite *sprite)
{
	// A = atan2(V.y, V.x)
	float perp_angle = PI - atan2(ray->rayDir.dirY, ray->rayDir.dirX) + 

	float cell_pos;
	// Getting hit position relative to the cell
	if (ray->side == 1) // Horizontal hit
		cell_pos = wall_x.y - (int)(wall_x.y / data->cell_size) * data->cell_size;
	else // Vertical hit
		cell_pos = wall_x.x - (int)(wall_x.x / data->cell_size) * data->cell_size;

	if (ray->side_hit == 3 || ray->side_hit == 2) // Converting cell_pos to ratio
		cell_pos = cell_pos / data->cell_size;
	else // Flip texture if the side hit is the top or the right side of a cell
		cell_pos = 1.0f - cell_pos / data->cell_size;

	int tex_x = cell_pos * texture->width_img; // Mapping ratio to texture dimension

	return (tex_x);
}