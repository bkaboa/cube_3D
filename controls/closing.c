#include "../includes/cube3D.h"

int	win_keyclose(int keycode, t_cube *cube)
{
	if (keycode == 65307)
	{
		mlx_clear_window(cube->mlx.mlx, cube->mlx.mlx_win);
		mlx_destroy_window(cube->mlx.mlx, cube->mlx.mlx_win);
		mlx_do_key_autorepeaton(cube->mlx.mlx);
		exit(0);
	}
	return (0);
}

int	click_close(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx,cube->mlx.mlx_win);
	mlx_destroy_window(cube->mlx.mlx,cube->mlx.mlx_win);
	exit(0);
	return (0);
}