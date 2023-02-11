#ifndef DEFINE_H
# define DEFINE_H

/*
 *
 *********************************		DEFINE_ERROR
 *
 */
# define ERROR_MSG			"Error\n"

//PARSING_ERROR
# define INV_NUM_ARG		"invalid number of argument\n"
# define DIR_ERROR_MSG		"file passed in argument need to be a file\n"
# define CUB_FILE			"file passed in argument is not .cub extension\n"
# define EMPTY_FILE			"files passed in argument is empty\n"
# define BAD_FILE_NAME		"the file passed in argument doesn't exist\n"
# define BAD_COLOR			"bad color in file\n"

//MAP_ERROR
# define MAP_ERROR			"map error\n"
# define SYNTAX_ERROR		"syntax in file not correct\n"
# define MAP_REQUEST		"please make sure you give all the needed informations before the map\n"
# define WALL_ERROR			"Wall error\n"
# define WALL_INVALID		"Wall invalid\n"
# define MAP_TOO_SMALL		"map passed in files too small\n"
# define EMPTY_LINE_IN_MAP	"empty line in map\n"
# define SEVERAL_PLAYER		"several player in the map\n"

//SYS_ERROR
# define MALLOC_ERROR		"malloc error\n"
# define OPEN_ERROR			"open function system failed\n"
# define READ_ERROR			"read function system failed\n"

//MLX_ERROR
# define XPM_WALL_INVALID	"xpm file for for wall is invalid\n"

# define PLAYER_POS			"NSEW"
# define MAP_CHAR			"01 "
/*
 *
 *********************************		DEFINE_SCREEN
 *
 */

# define WIDTH 1024
# define HEIGHT 768

/*
 *
 *********************************		DEFINE_MINIMAP
 *
 */

# define MINIMAP_RATIO 40
# define CELL_SIZE 30
# define PLAYER_MINI_SIZE 5
/*
 *
 *********************************		DEFINE_COLOR
 *
 */

# define C_WHITE 0xFFFFFF
# define C_BLUE  0x0000FF
# define C_RED	 0xFF0000

/*
 *
 *********************************		DEFINE_PLAYER
 *
 */

#define MOVESPEED 1
#define FOV		45
#define ROTATIONSPEED 1

/*
 *
 *********************************		DEFINE_MAP
 *
 */
# define NORTH			0
# define SOUTH			1
# define WEST			2
# define EAST			3
# define FLOOR			0
# define CEILING		1

/*
 *
 *********************************		UTILITIES_DEFINE
 *
 */
# define FAILURE		-1
# define SUCCESS		0
# define EOM			2



#endif
