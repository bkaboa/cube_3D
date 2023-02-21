/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:28 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 18:57:48 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	ato_rgb(char **str, u_int8_t *value)
{
	u_int16_t	ret;

	ret = 0;
	if (**str < '0' || **str > '9')
		return (FAILURE);
	while (**str >= '0' && **str <= '9')
	{
		ret = ret * 10 + (**str - '0');
		(*str)++;
		if (ret > 255)
			return (FAILURE);
	}
	*value = ret;
	return (SUCCESS);
}

void	convert_rgb_to_hexa(u_int8_t rgb_color[3], int *hexa_color)
{
	int			j;
	int			i;

	j = 6;
	i = 1;
	while (--j >= 0)
	{
		*hexa_color += (rgb_color[j >> 1] % 16) * i;
		rgb_color[(j >> 1)] = rgb_color[(j >> 1)] >> 4;
		i = i << 4;
	}
}

void	attribute_color(t_cube *map, char **line)
{
	u_int8_t	i;
	u_int8_t	j;
	u_int8_t	mlx_color[2][3];
	char		*tmp_line;

	i = 3;
	while (++i < 6)
	{
		j = 0;
		tmp_line = line[i] + 1;
		if (*tmp_line != ' ')
			exit_error_and_destruct(*map, 0, SYNTAX_ERROR);
		while (*tmp_line == ' ')
			tmp_line++;
		while (*tmp_line && *tmp_line != '\n')
		{
			if (ato_rgb(&tmp_line, &mlx_color[i - 4][j]) == FAILURE)
				exit_error_and_destruct(*map, 0, RGB_ERROR);
			if (*tmp_line == ',' && ++j)
				tmp_line++;
		}
		if (j > 2 || j < 2)
			exit_error_and_destruct(*map, 0, SYNTAX_ERROR);
		convert_rgb_to_hexa(mlx_color[i - 4], &map->mlx.hexa_color[i - 4]);
	}
}

void	attribute_wall_sprite(t_cube *map, char **line)
{
	int8_t		i;
	char		*tmp_line;

	i = -1;
	while (++i < 4)
	{
		tmp_line = line[i] + 2;
		if (*tmp_line != ' ')
			exit_error_and_destruct(*map, 0, SYNTAX_ERROR);
		while (*tmp_line == ' ')
			tmp_line++;
		map->mlx.wall_sprite[i].sprite = mlx_xpm_file_to_image(map->mlx.mlx, \
			tmp_line, &map->mlx.wall_sprite[i].height, \
			&map->mlx.wall_sprite[i].width);
		if (map->mlx.wall_sprite[i].sprite == NULL)
			exit_error_and_destruct(*map, 0, WALL_INVALID);
		map->mlx.wall_sprite[i].addr = \
			mlx_get_data_addr(map->mlx.wall_sprite[i].sprite, \
			&map->mlx.wall_sprite[i].bits_per_pixel, \
			&map->mlx.wall_sprite[i].line_length, \
			&map->mlx.wall_sprite[i].endian);
		if (map->mlx.wall_sprite[i].addr == NULL)
			exit_error_and_destruct(*map, 0, WALL_INVALID);
		check_sprite(*map);
	}
}

void	take_sprite_and_color(t_cube *map)
{
	int64_t		ret_find;
	char		*line[7];
	int32_t		i;
	const char	*map_instruct[] = {"NO", "SO", "EA", "WE", "C", "F", NULL};

	i = -1;
	while (++i < 7)
		line[i] = NULL;
	ret_find = map->text_file.find_file_instructions(map->text_file, \
		line, map_instruct);
	if (ret_find < 0)
		exit_error_and_destruct(*map, 0, MAP_ERROR_2);
	place_eol(line);
	attribute_wall_sprite(map, line);
	attribute_color(map, line);
	take_map((char *)ret_find, map);
	allocate_map((char *)ret_find, map);
	take_player(map);
	check_valid_map(*map);
}
