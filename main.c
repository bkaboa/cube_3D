#include "includes/header_struct_object.h"
#include "includes/parsing.h"

int main(int ac, char **av)
{
	t_cube	map;

	if (ac != 2)
		exit_error(ARG_ERROR_MSG);
	file_map_parsing(av[1], map);
	return (0);
}
