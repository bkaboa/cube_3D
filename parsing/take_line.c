#include "../includes/cube3D.h"

//static int64_t	count_map_size(char *str_map)
//{
//	int64_t	n_lines;
//	
//	n_lines = 0;
//	while (*str_map)
//	{
//		if (*str_map == '\n')
//			n_lines++;
//		str_map++;
//	}
//	return (n_lines);
//}
//
//static int16_t	parse_map(void* line, t_cube map, t_string *file_text)
//{
//	const char	*str = (char*)line;
//	int64_t	n_lines;
//
//	while (*str != '1')
//	{
//		if (*str != '1' && *str != ' ' && *str != '\n')
//			exit_error_and_destruct(file_text, map, 0, MAP_ERROR);
//		str++;
//	}
//	while (str[-1] != '\n')
//		str--;
//	n_lines = count_map_size(str);
//	return (SUCCESS);
//}

static void	place_eol(char **line)
{
	char	*tmp;
	int32_t	n_lines;
	int		i;
	
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
		if (ret > 255)
			return (FAILURE);
		ret = ret * 10 + (**str - '0');
		(*str)++;
	}
	*value = ret;
	dprintf(2, "value = %d\n", *value);
	return (SUCCESS);
}

static void	attribute_color(t_cube map, char **line, t_string *file_text)
{
	u_int8_t	i;
	u_int8_t	j;
	char		*tmp_line;

	i = 4;
	while (i < 6)
	{
		j = 0;
		tmp_line = line[i];
		tmp_line += 1;
		if (*tmp_line != ' ')
			exit_error_and_destruct(file_text, map, 0, SYNTAX_ERROR);
		while (*tmp_line == ' ')
			tmp_line++;
		while (*tmp_line && *tmp_line != '\n')
		{
			if (ato_rgb(&tmp_line, &map.mlx.color[i - 4][j]) == FAILURE)
				exit_error_and_destruct(file_text, map, 0, SYNTAX_ERROR);
			if (*tmp_line == ',' && ++j)
				tmp_line++;
		}
		if (j > 2 || j < 2)
			exit_error_and_destruct(file_text, map, 0, SYNTAX_ERROR);
		i++;
	}
}

static void	attribute_wall_sprite(t_cube map, char **line, t_string *file_text)
{
	int8_t	i;
	char		*tmp_line;
	
	i = -1;
	while (++i < 4)
	{
		tmp_line = line[i];
		tmp_line += 2;
		if (*tmp_line != ' ')
			exit_error_and_destruct(file_text, map, 0, SYNTAX_ERROR);
		while (*tmp_line == ' ')
			tmp_line++;
		map.mlx.wall_sprite[i].sprite = mlx_xpm_file_to_image(map.mlx.mlx, tmp_line, &map.mlx.wall_sprite[i].sprite_lenght, &map.mlx.wall_sprite[i].sprite_width);
		if (map.mlx.wall_sprite[i].sprite == NULL)
			exit_error_and_destruct(file_text, map, 0, WALL_INVALID);
	}
}

static void	take_sprite_and_color(t_cube map, t_string *file_text)
{
	int64_t		ret_find;
	char		*line[7];
	int			i;
	const char	*map_instruct[] = {"NO", "SO", "EA", "WE", "C", "F", NULL};

	i = -1;
	while (++i < 7)
		line[i] = NULL;
	ret_find = file_text->find_file_instructions(*file_text, line, map_instruct);
	if (ret_find < 0)
		exit_error_and_destruct(file_text, map, 0, MAP_ERROR);
	place_eol(line);
	attribute_wall_sprite(map, line, file_text);
	attribute_color(map, line, file_text);
	exit_error_and_destruct(file_text, map, 0, "all have been made");
	//parse_map((void*)ret_find, map, file_text);
}

void	take_all_line(const int fd, t_cube map)
{
	t_string	file_text;

	string_init(&file_text);
	if (ft_read_file(&file_text, fd) == FAILURE)
		exit_error_and_destruct(&file_text, map, fd, READ_ERROR);
	close(fd);
	take_sprite_and_color(map, &file_text);
}