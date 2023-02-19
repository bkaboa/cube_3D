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

// int get_tex_x(t_cube *cube, t_ray *ray, t_sprite *sprite)
// {
// 	// A = atan2(V.y, V.x)
// 	float perp_angle = PI - atan2(ray->rayDir.dirY, ray->rayDir.dirX) + 

// 	float cell_pos;
// 	// Getting hit position relative to the cell
// 	if (ray->side == 1) // Horizontal hit
// 		cell_pos = wall_x.y - (int)(wall_x.y / data->cell_size) * data->cell_size;
// 	else // Vertical hit
// 		cell_pos = wall_x.x - (int)(wall_x.x / data->cell_size) * data->cell_size;

// 	if (ray->side_hit == 3 || ray->side_hit == 2) // Converting cell_pos to ratio
// 		cell_pos = cell_pos / data->cell_size;
// 	else // Flip texture if the side hit is the top or the right side of a cell
// 		cell_pos = 1.0f - cell_pos / data->cell_size;

// 	int tex_x = cell_pos * texture->width_img; // Mapping ratio to texture dimension

// 	return (tex_x);
// }

//get color at x y of the sprite

int init_pixel_ray(t_cube *cube, int textnum)
{
	int drawstart = -cube->ray.lineHeight / 2 + HEIGHT / 2;
	if (cube->ray.side == 0)
		cube->ray.wallX = cube->player.yPos + cube->ray.perpWallDist * cube->ray.rayDir.dirY;
	else
		cube->ray.wallX = cube->player.xPos + cube->ray.perpWallDist * cube->ray.rayDir.dirX;
	cube->ray.wallX -= floor(cube->ray.wallX);
	cube->ray.texX = (int)(cube->ray.wallX * (float)cube->mlx.wall_sprite[textnum].width);
	cube->ray.texX = cube->mlx.wall_sprite[textnum].width - cube->ray.texX - 1;
	cube->ray.f_step = 1.0 * cube->mlx.wall_sprite[textnum].height / cube->ray.lineHeight;
	cube->ray.tex_pos = (drawstart - HEIGHT / 2 + cube->ray.lineHeight / 2) * cube->ray.f_step;
}

void get_tex_color(t_cube *cube, int texnum, int x, int y)
{
	int *new_addr;

	new_addr = (int *)cube->mlx.wall_sprite[texnum].addr;
	cube->ray.texY = (int)cube->ray.tex_pos & cube->mlx.wall_sprite[texnum].height;
	cube->ray.tex_pos += cube->ray.f_step;
	my_mlx_pixel_put(&cube->mlx.walls, x, y, new_addr[cube->ray.texY * cube->mlx.wall_sprite[texnum].height + cube->ray.texX]);
}

void select_wall_to_put_pixel(t_cube *cube, int x)
{
	if (cube->ray.side == 1 && cube->ray.mapY < cube->player.yPos)
		cube->ray.textnum = 0;
	else if (cube->ray.side == 1)
		cube->ray.textnum = 1;
	if (cube->ray.side == 0 && cube->ray.mapX > cube->player.xPos)
		cube->ray.textnum = 3;
	else
		cube->ray.textnum = 2;
}

void trace_line_from_ray(t_cube *cube, int x)
{
	int j;

	j = 0;
	select_wall_to_put_pixel(cube, x);
	init_pixel_ray(cube, cube->ray.textnum);
	while (++j < HEIGHT)
	{
		if (j < (-cube->ray.lineHeight / 2) + (HEIGHT / 2))
			my_mlx_pixel_put(&cube->mlx.walls, x, j, C_RED);
		if (j >= (-cube->ray.lineHeight / 2) + (HEIGHT / 2) && j <= (cube->ray.lineHeight / 2) + (HEIGHT / 2))
			get_tex_color(cube, cube->ray.textnum, x, j);
		else if (j > (cube->ray.lineHeight / 2) + (HEIGHT / 2))
			my_mlx_pixel_put(&cube->mlx.walls, x, j, C_BLUE);
	}
}
