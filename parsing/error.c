#include "../includes/include.h"

void	exit_error(const char *str)
{
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_error_and_destruct(t_string *str, t_cube map, const int fd, const char *msg)
{
	if (str)
		str->string_destructor(str);
	if (fd != 0)
		close(fd);
	free_double_pointer((void**)map.map);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
