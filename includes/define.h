/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:42:07 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:14:04 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
 *
 *********************************		DEFINE_ERROR
 *
 */
# define ERROR_MSG			"Error\n"
# define SYNTAX_ERROR		"syntax in file not correct\n"
# define RGB_ERROR			"rgb color can only be between 0 255 \
	and contain numbers only\n"
# define WALL_INVALID		"Wall invalid\n"
# define UNKNOWN_CHAR		"unknown cahracter in map"
# define MAP_ERROR			"map error in"
# define MAP_ERROR_2		"map error\n"
# define TWO_PLAYER			"you can't have more than one player in map"
# define NO_PLAYER			"no player in map\n"
# define MAP_TOO_SMALL		"map passed in files too small\n"
# define MALLOC_ERROR		"malloc error\n"
# define OPEN_ERROR			"open function system failed\n"
# define READ_ERROR			"read function system failed\n"
# define SPRITE_ERROR		"the sprite passed in file must be a square, \
	and the lenght must be a pow 2 inferior to 2048\n"
# define FILE_TOO_BIG		"file passed in argument can't be over \
	25000 character rethink your file\n"
# define BAD_FILE_NAME		"the file passed in argument doesn't exist\n"
# define INV_NUM_ARG		"invalid number of argument\n"
# define DIR_ERROR_MSG		"file passed in argument need to be a file\n"
# define CUB_FILE			"file passed in argument is not .cub extension\n"
# define EMPTY_FILE			"files passed in argument is empty\n"
# define MAP_REQUEST		"please make sure you give all the needed \
	informations before the map\n"
# define EMPTY_LINE_IN_MAP	"empty line in map\n"

# define PLAYER_POS			"NSEW"
# define MAP_CHAR			"01 "
/*
 *
 *********************************		DEFINE_SCREEN
 *
 */

# define WIDTH				1080
# define HEIGHT				720
# define MID_HEIGHT_SCREEN	360
/*
 *
 *********************************		DEFINE_CONTROLS
 *
 */

# define KEY_LEFT		97
# define KEY_RIGHT		100
# define KEY_FORWARD	119
# define KEY_BACKWARD	115
# define ARROW_RIGHT	65363
# define ARROW_LEFT		65361

/*
 *
 *********************************		DEFINE_MINIMAP
 *
 */

# define PLAYER_MINI_SIZE	5
/*
 *
 *********************************		DEFINE_COLOR
 *
 */

# define C_BLACK	0x000000
# define C_WHITE	0xFFFFFF
# define C_BLUE 0x0000FF
# define C_RED 0xFF0000
# define C_GREEN 0x00FF00

/*
 *
 *********************************		DEFINE_PLAYER
 *
 */

# define MOVESPEED		0.03
# define FOV				0.70 //Player's cone of vision (in plane)
# define ROTATIONSPEED	0.05

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
# define FAILURE_2		-2
# define SUCCESS		0
# define EOM			2

#endif
