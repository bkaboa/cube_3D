#include "../includes/cube3D.h"

static void	check_valid_map(t_cube map, int64_t x, int64_t y)
{
	if (map.map[y] && map.map[y][x] == '0')
	{
		if (x == 0 || y == 0 || !map.map[y][x + 1])
				exit_map_error_and_destruct(map, y + 1, x + 2, MAP_ERROR);
		if (x > (int32_t)ft_strlen(map.map[y + 1]) || x > (int32_t)ft_strlen(map.map[y - 1]))
				exit_map_error_and_destruct(map, y + 1, x + 1, MAP_ERROR);
		if (map.map[y - 1][x] == ' ' || map.map[y - 1][x] == ' ')
				exit_map_error_and_destruct(map, y, x + 1, MAP_ERROR);
		if (map.map[y][x - 1] == ' ' || map.map[y][x + 1] == ' ')
				exit_map_error_and_destruct(map, y + 1, x + 2, MAP_ERROR);
	}
	if (map.map[y] && x == 0)
		check_valid_map(map, x, y + 1);
	if (map.map[y] && map.map[y][x])
		check_valid_map(map, x + 1, y);
}

static void	set_player_view(t_cube *map, int player_glance)
{
	if (player_glance < 2)
	{
		map->player.planeY = -FOV;
		if(player_glance % 2)
		{
			map->player.playerDir.dirX = 1;
			map->player.planeX = FOV;
		}
		else
			map->player.playerDir.dirX = 1;
	}
	else
	{
		map->player.planeX = FOV;
		if (player_glance % 2)
		{
			map->player.planeX = -FOV;
			map->player.playerDir.dirY = -1;
		}
		else
			map->player.playerDir.dirY = 1;
	}
}

static void	take_player(t_cube *map)
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
						exit_map_error_and_destruct(*map, y + 1, x + 1, UNKNOWN_CHAR);
				if (n_player >= 1)
						exit_map_error_and_destruct(*map, y + 1, x + 1, TWO_PLAYER_IN_MAP);
				map->map[y][x] = '0';
				n_player++;
				set_player_view(map, player_glance);
				map->player.yPos = x + 0.5;
				map->player.xPos = y + 0.5;
			 }
		}
	}
	if (n_player == 0)
		exit_error_and_destruct(*map, 0, NO_PLAYER_IN_MAP);
}

static void	take_map(char *line, t_cube *map)
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

static void	allocate_map(char *line, t_cube *map)
{
	int32_t	i;
	bool	is_empty;

	i = -1;
	is_empty = false;
	map->map = malloc(sizeof(char*) * (map->map_ylen + 1));
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

static void	place_eol(char **line)
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

static int	ato_rgb(char **str, u_int8_t *value)
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
	while ( --j >= 0)
	{
		*hexa_color += (rgb_color[j >> 1] % 16) * i;
		rgb_color[(j >> 1)] = rgb_color[(j >> 1)] >> 4;
		i = i << 4;
	}
}

static void	attribute_color(t_cube *map, char **line)
{
	u_int8_t	i;
	u_int8_t	j;
		u_int8_t	mlx_color[2][3];
	char		*tmp_line;

	i = 4;
	while (i < 6)
	{
		j = 0;
		tmp_line = line[i];
		tmp_line += 1;
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
		i++;
	}
}

static void	attribute_wall_sprite(t_cube *map, char **line)
{
	int8_t	i;
	char		*tmp_line;
	
	i = -1;
	while (++i < 4)
	{
		tmp_line = line[i];
		tmp_line += 2;
		if (*tmp_line != ' ')
			exit_error_and_destruct(*map, 0, SYNTAX_ERROR);
		while (*tmp_line == ' ')
			tmp_line++;
		map->mlx.wall_sprite[i].sprite = mlx_xpm_file_to_image(map->mlx.mlx, tmp_line, &map->mlx.wall_sprite[i].height, &map->mlx.wall_sprite[i].width);
		if (map->mlx.wall_sprite[i].sprite == NULL)
			exit_error_and_destruct(*map, 0, WALL_INVALID);
		map->mlx.wall_sprite[i].addr = mlx_get_data_addr(map->mlx.wall_sprite[i].sprite,
																&map->mlx.wall_sprite[i].bits_per_pixel, &map->mlx.wall_sprite[i].line_length, &map->mlx.wall_sprite[i].endian);
		// map->mlx.wall_sprite[i].bits_per_pixel >>= 3;
		if (map->mlx.wall_sprite[i].addr == NULL)
			exit_error_and_destruct(*map, 0, WALL_ERROR);
	}
}

static void	take_sprite_and_color(t_cube *map)
{
	int64_t		ret_find;
	char		*line[7];
	int32_t		i;
	const char	*map_instruct[] = {"NO", "SO", "EA", "WE", "C", "F", NULL};

	i = -1;
	while (++i < 7)
		line[i] = NULL;
	ret_find = map->text_file.find_file_instructions(map->text_file, line, map_instruct);
	if (ret_find < 0)
		exit_error_and_destruct(*map, 0, MAP_ERROR);
	place_eol(line);
	attribute_wall_sprite(map, line);
	attribute_color(map, line);
	take_map((char*)ret_find, map);
	allocate_map((char*)ret_find, map);
	take_player(map);
	check_valid_map(*map, 0, 0);
	int j = 0;
}

void	take_all_line(const int fd, t_cube *map)
{
	string_init(&map->text_file);
	if (ft_read_file(&map->text_file, fd) == FAILURE)
		exit_error_and_destruct(*map, fd, READ_ERROR);
	if (!map->text_file.str)
			exit_error_and_destruct(*map, 0, EMPTY_FILE);
	close(fd);
	take_sprite_and_color(map);
}
