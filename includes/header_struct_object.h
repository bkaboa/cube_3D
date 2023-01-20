#ifndef HEADER_STRUCT_OBJECT_H
# define HEADER_STRUCT_OBJECT_H

# define ERROR_MSG			"Error\n"
# define ARG_ERROR_MSG		"invalid number of argument\n"
# define DIR_ERROR_MSG		"map need to be a file not a directory\n"
# define OPEN_ERROR			"bad file name or open error\n"
# define CUB_FILE			"file passed in argument is not .cub\n"
# define WALL_INVALID		"sprite in file must be north south west east\n"
# define WALL_ERROR			"after wall coordinate it must have sprite\n"
# define READ_ERROR			"problem during the reading file\n"
# define XPM_WALL_INVALID	"xpm file for sprite is invalid\n"
# define MALLOC_ERROR		"malloc error\n"

# define MAP_ERROR			"map error\n"

# define NORTH			"NO"
# define SOUTH			"SO"
# define WEST			"WE"
# define EAST			"EA"
# define FLOOR			"F"
# define CEILING		"C"

# define FAILURE		-1
# define SUCCESS		0
# define EOF			2

# include "include.h"
# include "../object/string/string.h"

typedef struct	s_character
{
	float	pos_x;
	float	pos_y;
	float	fov;
}	t_character;

typedef struct s_sprite
{
	void	*sprite;
	int		sprite_lenght;
	int		sprite_width;
}	t_sprite;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_sprite	wall_sprite[4];
	void		*color[2];
}	t_mlx;

typedef struct	s_cube
{
	t_string	*map;
	t_mlx		mlx_data;
	t_character	character;
}	t_cube;

#endif
