#include "../includes/cube3D.h"

void	free_all_and_exit(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx, cube->mlx.mlx_win);
	mlx_destroy_window(cube->mlx.mlx, cube->mlx.mlx_win);
	exit(0);
}

int	click_close(t_cube *cube)
{
	mlx_clear_window(cube->mlx.mlx,cube->mlx.mlx_win);
	mlx_destroy_window(cube->mlx.mlx,cube->mlx.mlx_win);
	exit(0);
	return (0);
}