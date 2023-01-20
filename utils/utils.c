#include "../includes/utils.h"
#include <cstdlib>

size_t	ft_strlen(const char *str)
{
	char *tmp;

	if (!str)
		return (0);
	tmp = (char*)str;
	while (*tmp)
		tmp++;
	return (tmp - str);
}

bool	ft_strcomp(const char *first, const char *second)
{
	if (!first || !second)
		return (-1);
	while (*first == *second && *first && *second)
	{
		first++;
		second++;
	}
	return (*first - *second);
}

int	ft_strncomp(const char *str1, const char *str2, const int n)
{
	int		i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	while (i < n && str1[i] == str2[i] && str1[i] && str2[i])
	{
		i++;
	}
	return (*str1 - *str2);
}

int	ft_read_file(t_string *line, const int fd)
{
	char		buf[2];
	int			read_ret;

	line->string_destructor(line);
	buf[1] = 0;
	while (buf[1] != '\n')
	{
		read_ret = read(fd, buf, 1);
		if (read_ret == -1)
			return (FAILURE);
		if (read_ret == 0)
			return (EOF);
		if (buf[0] != '\n')
			if (line->append(line, buf) == FAILURE)
				return (FAILURE);
	}
	return (SUCCESS);
}

void	init_map(t_cube map)
{
	map.mlx_data.color[0] = NULL;
	map.mlx_data.color[1] = NULL;
	map.mlx_data.wall_sprite[0].sprite = NULL;
	map.mlx_data.wall_sprite[1].sprite = NULL;
	map.mlx_data.wall_sprite[2].sprite = NULL;
	map.mlx_data.wall_sprite[3].sprite = NULL;
	map.map = NULL;
}

void	add_line(t_cube map, t_string line)
{
	if (!map.map)
		map.map = malloc(sizeof(t_string) * 2);
}
