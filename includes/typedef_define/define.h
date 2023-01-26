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
# define MAP_ERROR			"map error in (line, column)\n"

//SYS_ERROR
# define MALLOC_ERROR		"malloc error\n"
# define OPEN_ERROR			"open function system failed\n"
# define READ_ERROR			"read function system failed\n"

//MLX_ERROR
# define XPM_WALL_INVALID	"xpm file for for wall is invalid\n"

/*
 *
 *********************************		DEFINE_MAP
 *
 */
# define NORTH			"NO"
# define SOUTH			"SO"
# define WEST			"WE"
# define EAST			"EA"
# define FLOOR			"F"
# define CEILING		"C"

/*
 *
 *********************************		UTILITIES_DEFINE
 *
 */
# define FAILURE		-1
# define SUCCESS		0
# define EOF			2



#endif
