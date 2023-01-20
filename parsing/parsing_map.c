#include "../includes/parsing.h"

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
			map.character.pos_x = x;
			map.character.pos_y = y;
			line->str[x] = '0';
		}
		if (line->str[x] != '0' || line->str[x] != '1' || line->str[x] != ' ')
			exit_error_and_destruct(NULL, map, fd, MAP_ERROR);
	}
}

static void	take_map(const int fd, t_cube map)
{
	t_string	line;
	int			read_file_ret;
	int			n;

	n = -1;
	line.string_init(&line);
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
		add_line(map, line);
		check_line(&line, map, fd, n);
		read_file_ret = ft_read_file(&line, fd);
	}
}

static void	parse_line(t_cube map, int const fd, int count)
{
}

void	check_map(const int fd, t_cube map)
{
	take_map(fd, map);
	parse_map(fd, map);
}
