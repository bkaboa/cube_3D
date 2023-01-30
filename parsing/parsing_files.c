#include "../includes/cube3D.h"

static void	check_file(t_string line, t_cube map, unsigned int *y, const int fd)
{
	int		i;

	if (*y >= 4)
		check_color(fd, map, line, y);
	i = 2;
	if (line.str[i] != ' ')
		exit_error_and_destruct(&line, map, fd, WALL_ERROR);
	while (line.str[i] == ' ')
		i++;
	map.mlx.wall_sprite[*y].sprite = mlx_xpm_file_to_image(\
			map.mlx.mlx, &line.str[i], \
			&map.mlx.wall_sprite[*y].sprite_lenght, \
			&map.mlx.wall_sprite[*y].sprite_width);
	if (map.mlx.wall_sprite[*y].sprite == NULL)
		exit_error_and_destruct(&line, map, fd, XPM_WALL_INVALID);
	line.string_destructor(&line);
	*y = 0;
}

static void	init_sprite_direction(int *sprite_direction)
{
	int		i;

	i = 0;
	while (i < 6)
		sprite_direction[i++] = 0;
}

static int	read_in_file(t_string *line, const int fd)
{
	int	read_file_ret;

	line->string_destructor(line);
	while(line->str == NULL && read_file_ret == SUCCESS)
		read_file_ret = ft_read_file(line, fd);
	if (read_file_ret == FAILURE || read_file_ret == EOF)
		return (FAILURE);
	return (SUCCESS);
}

void	check_sprite_files(const int fd, t_cube map)
{
	const char		*sprite[] = {"NO", "SO", "EA", "WE", "F", "C", NULL};
	int32_t			sprite_and_color[6];
	u_int32_t		i;
	u_int32_t		y;
	t_string		line;

	i = -1;
	string_init(&line);
	init_sprite_direction(sprite_and_color);
	while (++i < 6)
	{
		y = 0;
		if (read_in_file(&line, fd) == FAILURE)
			exit_error_and_destruct(&line, map, fd, READ_ERROR);
		while (sprite[y])
		{
			if (ft_strcomp(sprite[y++], line.str) == true)
			{
				if (++(sprite_and_color[y]) > 1)
					exit_error_and_destruct(&line, map, fd, WALL_INVALID);
				check_file(line, map, &y, fd);
			}
		}
		if (!sprite[y])
			exit_error_and_destruct(&line, map, fd, WALL_INVALID);
	}
}
