# include "../includes/parsing.h"

void	check_color(const int fd, t_cube map)
{
	const char	*fc[2] = {FLOOR, CEILING};
	int			n_fc[2];
	t_string	line;
	int			i;
	int			y;

	fc[0] = 0;
	fc[1] = 0;
	i = 0;
	y = 1;
	while (i < 2)
	{
		while (line.str == NULL)
			line = ft_read_file(fd);
	}
}
