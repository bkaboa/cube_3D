int	win_keyclose(int keycode, t_mlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
		mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
		mlx_do_key_autorepeaton(fdf->mlx.mlx);
		exit(0);
	}
	return (0);
}

int	win_close(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx.mlx, fdf->mlx.win);
	mlx_destroy_window(fdf->mlx.mlx, fdf->mlx.win);
	exit(0);
	return (0);
}