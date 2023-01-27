#include "../includes/cube3D.h"

int8_t	ato_uc(char *str, u_int8_t *pointer_value)
{
	*pointer_value = 0;
	while (*str == '0')
		str++;
	if (*str < '0' || *str > '9' || ft_strlen(str) > 3)
		return (FAILURE);
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (FAILURE);
		if ((int)(*pointer_value * 10 + (*str - '0')) > UCHAR_MAX)
			return (FAILURE);
		*pointer_value = *pointer_value * 10 + (*str - '0');
		str++;
	}
	return (SUCCESS);
}

static void	assign_color(t_cube map, const int fd, t_string line, unsigned int *y, char **str)
{
	u_int8_t	color[3];
	u_int8_t	i;

	i = -1;
	while (++i < 3)
	{
		if (ato_uc(str[i], &color[i]) == FAILURE)
			exit_error_and_destruct(&line, map, fd, MAP_ERROR);
	}
	i = -1;
	if (*y == 4)
		while (++i < 3)
			map.mlx_data.floor_color[i] = color[i];
	else
		while (++i < 3)
			map.mlx_data.ceiling_color[i] = color[i];
}

void	check_color(const int fd, t_cube map, t_string line, unsigned int *y)
{
	int		i;
	int		j;
	char	*str[3];

	j = 0;
	i = 1;
	if (line.str[i] != ' ')
		exit_error_and_destruct(&line, map, fd, WALL_ERROR);
	while (line.str[i] == ' ')
		i++;
	while (line.str[i])
	{
		if (j > 2)
			exit_error_and_destruct(&line, map, fd, MAP_ERROR);
		str[j++] = &line.str[i];
		while (line.str[i] >= '0' && line.str[i] <= '9')
			i++;
		if (line.str[i] == ',')
			line.str[i++] = '\0';
		else
			exit_error_and_destruct(&line, map, fd, MAP_ERROR);
	}
	assign_color(map, fd, line, y, str);
}
