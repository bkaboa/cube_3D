#include "../includes/cube3D.h"

static void	check_line(const t_string *line, t_cube map, const int fd, int y)
{
	int			x;
	static int	p_count;

	p_count = 0;
	x = -1;
	while (line->str[++x])
	{
		if (line->str[x] == 'W' || line->str[x] == 'E' || line->str[x] == 'N' || line->str[x] == 'S')
		{
			p_count++;
			if (p_count > 1)
				exit_error_and_destruct(NULL, map, fd, MAP_ERROR);
			map.player.pos_x = x;
			map.player.pos_y = y;
			line->str[x] = '0';
		}
		if (line->str[x] != '0' || line->str[x] != '1' || line->str[x] != ' ')
			exit_error_and_destruct(NULL, map, fd, MAP_ERROR);
	}
}

static void	parse_near_char(t_cube map, int y, int x, int i)
{
	if (x <= 0 || y <= 0 || !map.map[y] || !map.map[y][x] || map.map[y][x] == ' ')
		exit_error_and_destruct(NULL, map, 0, MAP_ERROR);
	if (i == 0)
		parse_near_char(map, y - 1, x, i + 1);
	if (i == 1)
		parse_near_char(map, y + 2, x, i + 1);
	if (i == 2)
		parse_near_char(map, y - 1, x - 1, i + 1);
	if (i == 3)
		parse_near_char(map, y, x + 2, i + 1);
}

static void	take_map(const int fd, t_cube map)
{
	t_string	line;
	int			read_file_ret;
	int			n;

	n = -1;
	string_init(&line);
	while (line.str == NULL)
	{
		read_file_ret = ft_read_file(&line, fd);
		if (read_file_ret == EOF || read_file_ret == FAILURE)
			exit_error_and_destruct(&line, map, fd, READ_ERROR);
	}
	while (read_file_ret != EOF && ++n)
	{
		if (read_file_ret == FAILURE || line.str == NULL)
			exit_error_and_destruct(&line, map, fd, MALLOC_ERROR);
		if (add_line(map, line) == FAILURE)
			exit_error_and_destruct(&line, map, fd, MALLOC_ERROR);
		check_line(&line, map, fd, n);
		read_file_ret = ft_read_file(&line, fd);
	}
}

void	check_map(int fd, t_cube map)
{
	int		x;
	int		y;

	y = -1;
	take_map(fd, map);
	close (fd);
	while (map.map[++y])
	{
		x = -1;
		while (map.map[y][++x])
			if (map.map[y][x] == '0')
				parse_near_char(map, y, x, 0);
	}
}
