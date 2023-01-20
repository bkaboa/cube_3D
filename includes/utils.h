#ifndef UTILS_H
# define UTILS_H

# include "header_struct_object.h"

bool		ft_strcomp(const char *first, const char *second);
int			ft_read_file(t_string *line, int fd);
void		init_map(t_cube map);
void		free_map(t_cube map);
int			ft_strncomp(const char *str1, const char *str2, const int n);
size_t		ft_strlen(const char *str);

#endif
