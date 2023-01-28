#include "../includes/cube3D.h"

int	win_keyclose(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_do_key_autorepeaton(mlx->mlx);
		exit(0);
	}
	return (0);
}

int	click_close(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}