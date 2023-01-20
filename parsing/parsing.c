#include "../includes/parsing.h"

static void	check_file(const char *file, int *fd)
{
	size_t	i;

	if (ft_strlen(file) <= 4)
		exit_error(CUB_FILE);
	i = ft_strlen(file) - 4;
	if (ft_strcomp(&file[i], ".cub"))
		exit_error(CUB_FILE);
	if (open(file, O_DIRECTORY))
		exit_error(DIR_ERROR_MSG);
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		exit_error(OPEN_ERROR);
}

void	file_map_parsing(const char *file, t_cube map)
{
	int		fd;

	check_file(file, &fd);
	check_sprite_files(fd, map);
	check_color(fd, map);
	check_map(fd, map);
	close(fd);
}
