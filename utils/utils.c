#include "../includes/cube3D.h"

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
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_read_file(t_string *line, const int fd)
{
	char		buf[10000];
	int			read_ret;

	line->string_destructor(line);
	while (true)
	{
		read_ret = read(fd, buf, 10000);
		if (read_ret == -1)
			return (FAILURE);
		if (read_ret == 0)
			return (EOM);
		buf[read_ret] = 0;
		if (line->append(line, buf) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

void	init_map(t_cube *map)
{
	map->mlx.wall_sprite[0].sprite = NULL;
	map->mlx.wall_sprite[1].sprite = NULL;
	map->mlx.wall_sprite[2].sprite = NULL;
	map->mlx.wall_sprite[3].sprite = NULL;
	map->map = NULL;
}

void	free_double_pointer(void **pointer)
{
	int	i;

	i = -1;
	if (pointer)
	{
		while (pointer[++i])
			free(pointer[i]);
		free(pointer);
	}
}

int	add_line(t_cube map, t_string line)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map.map && map.map[i])
		i++;
	new_map = malloc(sizeof(char*) * (i + 1));
	if (new_map == NULL)
		return (FAILURE);
	i = -1;
	while (map.map && map.map[++i])
		new_map[i]  = map.map[i];
	new_map[i] = line.str;
	new_map[i + 1] = NULL;
	free_double_pointer((void**)map.map);
	map.map = new_map;
	return (SUCCESS);
}

void	ft_bzero(void *var, int64_t var_size)
{
	const void	*var_str = var;

	while (var - var_str < var_size)
		*(char*)(var++) = 0;
}
