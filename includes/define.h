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
# define RGB_ERROR			"rgb color can only be between 0 255 and contain numbers only\n"

//MAP_ERROR
# define MAP_ERROR					"map error in"
# define SYNTAX_ERROR				"syntax in file not correct\n"
# define MAP_REQUEST				"please make sure you give all the needed informations before the map\n"
# define WALL_ERROR					"Wall error\n"
# define WALL_INVALID				"Wall invalid\n"
# define MAP_TOO_SMALL			"map passed in files too small\n"
# define EMPTY_LINE_IN_MAP	"empty line in map\n"
# define SEVERAL_PLAYER			"several player in the map\n"
# define TWO_PLAYER_IN_MAP	"you can't have more than one player in map"
# define UNKNOWN_CHAR				"unknown cahracter in map"
# define NO_PLAYER_IN_MAP		"no player in map\n"

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

# define WIDTH 1230
# define HEIGHT 720
# define PI     3.14159

/*
 *
 *********************************		DEFINE_CONTROLS
 *
 */

# define KEY_LEFT 97
# define KEY_RIGHT 100
# define KEY_FORWARD 119
# define KEY_BACKWARD 115
# define ARROW_RIGHT 65363
# define ARROW_LEFT	65361

/*
 *
 *********************************		DEFINE_MINIMAP
 *
 */

# define MINIMAP_RATIO		30
# define MINIMAP_LENGHT		(int)(WIDTH / 2)
# define MINIMAP_HIGHT		(int)(HEIGHT / 2)
# define PLAYER_MINI_SIZE	5
# define WALL_SIZE			300
/*
 *
 *********************************		DEFINE_COLOR
 *
 */

# define C_BLACK	0x000000
# define C_WHITE	0xFFFFFF
# define C_BLUE  	0x0000FF
# define C_RED	 	0xFF0000
# define C_GREEN 	0x00FF00

/*
 *
 *********************************		DEFINE_PLAYER
 *
 */

#define MOVESPEED 0.05
#define FOV	0.70 //Player's cone of vision (in plane)
#define ROTATIONSPEED 0.05

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
