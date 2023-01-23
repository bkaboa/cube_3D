#include "../includes/parsing.h"
#include <stdlib.h>

void	exit_error(const char *str)
{
	write(2, ERROR_MSG, ft_strlen(ERROR_MSG));
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	exit_error_and_destruct(t_string *str, t_cube map, const int fd, const char *msg)
{
	int		i;

	i = -1;
	if (str)
		str->string_destructor(str);
	if (fd != 0)
		close(fd);
	free_double_pointer((void**)map.map);
	exit(EXIT_FAILURE);
}
