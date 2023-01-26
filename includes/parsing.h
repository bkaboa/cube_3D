#ifndef PARSING_H
# define PARSING_H

# include "include.h"

void	exit_error(const char *str);

void	file_map_parsing(const char *file, t_cube map);
void	check_sprite_files(const int fd, t_cube map);
void	check_color(const int fd, t_cube map, t_string line, unsigned int *y);
void	check_map(int fd, t_cube map);
void	exit_error_and_destruct(t_string *str, t_cube map, const int fd, const char *msg);

#endif
