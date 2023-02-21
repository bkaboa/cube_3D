/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:32:59 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:45:54 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	exit_error(const char *str)
{
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_error_and_destruct(t_cube map, const int fd, const char *msg)
{
	free_all(map, fd);
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	exit_map_error_and_destruct(t_cube map, int y, int x, const char *msg)
{
	free_all(map, 0);
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, msg, ft_strlen(msg));
	write(2, " ,line ", 7);
	ft_itoa_fd(y, 2);
	write(2, " ,column ", 9);
	ft_itoa_fd(x, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	check_sprite(t_cube map)
{
	int8_t	i;
	int32_t	j;
	bool	valid_sprite;

	valid_sprite = false;
	i = -1;
	j = 2;
	while (++i < 4)
	{
		if (map.mlx.wall_sprite[i].height != map.mlx.wall_sprite[i].width)
			exit_error_and_destruct(map, 0, SPRITE_ERROR);
		while (j < 2048)
		{
			if ((j ^ map.mlx.wall_sprite[i].height) == 0)
				valid_sprite = true;
			j = j << 1;
		}
		if (valid_sprite == false)
			exit_error_and_destruct(map, 0, SPRITE_ERROR);
	}
}

void	free_all(t_cube cube, const int fd)
{
	int	i;

	i = -1;
	while (i < 4)
	{
		if (cube.mlx.wall_sprite[i].sprite)
			mlx_destroy_image(cube.mlx.mlx, cube.mlx.wall_sprite[i].sprite);
		i++;
	}
	if (fd)
		close(fd);
	cube.text_file.string_destructor(&cube.text_file);
	if (cube.map)
		free(cube.map);
	if (cube.mlx.walls.img)
		mlx_destroy_image(cube.mlx.mlx, cube.mlx.walls.img);
	if (cube.mlx.mlx_win)
		mlx_destroy_window(cube.mlx.mlx, cube.mlx.mlx_win);
	if (cube.mlx.mlx)
	{
		mlx_destroy_display(cube.mlx.mlx);
		free(cube.mlx.mlx);
	}
}
