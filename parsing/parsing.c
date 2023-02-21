/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:33:03 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:19:13 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

static void	check_file(const char *file, int *fd)
{
	size_t	i;

	if (ft_strlen(file) <= 4)
		exit_error(CUB_FILE);
	i = ft_strlen(file) - 4;
	if (file[i - 1] == '/')
		exit_error(CUB_FILE);
	if (ft_strcomp(&file[i], ".cub"))
		exit_error(CUB_FILE);
	if (open(file, O_DIRECTORY) >= 0)
		exit_error(DIR_ERROR_MSG);
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		exit_error(OPEN_ERROR);
}

void	place_eol(char **line)
{
	char	*tmp;
	int32_t	n_lines;
	int32_t	i;

	n_lines = 0;
	i = -1;
	while (line[n_lines])
		n_lines++;
	while (++i < n_lines)
	{
		tmp = line[i];
		while (*tmp && *tmp != '\n')
			tmp++;
		*tmp = '\0';
	}
}

void	take_all_line(const int fd, t_cube *map)
{
	int	read_ret;

	string_init(&map->text_file);
	read_ret = ft_read_file(&map->text_file, fd);
	if (read_ret == FAILURE)
		exit_error_and_destruct(*map, fd, READ_ERROR);
	if (read_ret == FAILURE_2)
		exit_error_and_destruct(*map, fd, FILE_TOO_BIG);
	if (!map->text_file.str)
		exit_error_and_destruct(*map, 0, EMPTY_FILE);
	close(fd);
	take_sprite_and_color(map);
}

void	file_map_parsing(const int argc, char **argv, t_cube *map)
{
	int		fd;
	char	*file;

	if (argc > 2 || argc < 2)
		exit_error(INV_NUM_ARG);
	file = argv[1];
	check_file(file, &fd);
	init_mlx(map);
	take_all_line(fd, map);
	close(fd);
}
