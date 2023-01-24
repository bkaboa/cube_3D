#ifndef STRING_H
# define STRING_H

# include "../../includes/include.h"

typedef struct s_string
{
	size_t	lenght;
	size_t	size;
	char	*str;
	int			(*append)(struct s_string*, const char*);
	int			(*alloc_string)(struct s_string*, size_t);
	void		(*string_destructor)(struct s_string*);
	void		(*reference_copy_operator)(const struct s_string, struct s_string*);
	int			(*profond_copy_operator)(const struct s_string, struct s_string*);
	int			(*find)(struct s_string*, const char*);
}	t_string;

void	string_init(t_string *str);

#endif
