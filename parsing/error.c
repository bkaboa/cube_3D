#include "../includes/cube3D.h"

void	exit_error(const char *str)
{
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_error_and_destruct(t_cube map, const int fd, const char *msg)
{
	map.text_file.string_destructor(&map.text_file);
	if (fd)
		close(fd);
	if (map.map)
		free(map.map);
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	exit_map_error_and_destruct(t_cube map, int y, int x, const char *msg)
{
	map.text_file.string_destructor(&map.text_file);
	if (map.map)
		free(map.map);
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, msg, ft_strlen(msg));
	write(2, " ,line ", 7);
	ft_itoa_fd(y, 2);
	write(2, " ,column ", 9);
	ft_itoa_fd(x, 2);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
