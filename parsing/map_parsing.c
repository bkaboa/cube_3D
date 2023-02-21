/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:34:24 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 22:11:01 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

void	check_valid_map(t_cube map)
{
	int	y;
	int	x;

	y = -1;
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
		{
			if (map.map[y] && map.map[y][x] == '0')
			{
				if (x == 0 || y == 0 || !map.map[y][x + 1])
					exit_map_error_and_destruct(map, ++y, ++x, MAP_ERROR);
				if (x > (int32_t)ft_strlen(map.map[y + 1]) \
						|| x > (int32_t)ft_strlen(map.map[y - 1]))
					exit_map_error_and_destruct(map, ++y, ++x, MAP_ERROR);
				if (map.map[y - 1][x] == ' ' || map.map[y - 1][x] == ' ')
					exit_map_error_and_destruct(map, y, ++x, MAP_ERROR);
				if (map.map[y][x - 1] == ' ' || map.map[y][x + 1] == ' ')
					exit_map_error_and_destruct(map, ++y, ++x, MAP_ERROR);
			}
		}
	}
}

void	set_player(t_cube *map, int player_glance, int y, int x)
{
	if (player_glance < 2)
	{
		map->player.plane_y = FOV;
		if (player_glance % 2)
		{
			map->player.playerdir.dirx = 1;
			map->player.plane_y = -FOV;
		}
		else
			map->player.playerdir.dirx = -1;
	}
	else
	{
		map->player.plane_x = FOV;
		if (player_glance % 2)
		{
			map->player.plane_x = -FOV;
			map->player.playerdir.diry = -1;
		}
		else
			map->player.playerdir.diry = 1;
	}
	map->map[y][x] = '0';
	map->player.x_pos = y + 0.5;
	map->player.y_pos = x + 0.5;
}

void	take_player(t_cube *map)
{
	int	y;
	int	x;
	int	player_glance;
	int	n_player;

	y = -1;
	n_player = 0;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (check_char_in_str(MAP_CHAR, map->map[y][x]) == -1)
			{
				player_glance = check_char_in_str(PLAYER_POS, map->map[y][x]);
				if (player_glance == -1)
					exit_map_error_and_destruct(*map, ++y, ++x, UNKNOWN_CHAR);
				if (n_player++ >= 1)
					exit_map_error_and_destruct(*map, ++y, ++x, TWO_PLAYER);
				set_player(map, player_glance, y, x);
			}
		}
	}
	if (n_player == 0)
		exit_error_and_destruct(*map, 0, NO_PLAYER);
}

void	take_map(char *line, t_cube *map)
{
	int		i;

	i = 0;
	map->map_ylen = 1;
	while (*line && *line == '\n')
		line++;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			map->map_ylen++;
			if (i > map->map_xlen)
				map->map_xlen = i;
			line = &line[i];
			i = 0;
		}
		i++;
	}
	if (map->map_ylen <= 3)
		exit_error_and_destruct(*map, 0, MAP_TOO_SMALL);
}

void	allocate_map(char *line, t_cube *map)
{
	int32_t	i;
	bool	is_empty;

	i = -1;
	is_empty = false;
	map->map = malloc(sizeof(char *) * (map->map_ylen + 1));
	if (map->map == NULL)
		exit_error_and_destruct(*map, 0, MALLOC_ERROR);
	map->map[map->map_ylen] = NULL;
	while (*line == '\n')
		line++;
	while (++i < map->map_ylen)
	{
		map->map[i] = line;
		while (*line)
		{
			is_empty = false;
			line++;
		}
		line++;
		if (is_empty == true && i < map->map_ylen - 1)
			exit_error_and_destruct(*map, 0, EMPTY_LINE_IN_MAP);
		is_empty = true;
	}
}
