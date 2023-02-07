#ifndef STRUCT_H
# define STRUCT_H

# include "include.h"

typedef struct s_string
{
	size_t	lenght;
	size_t	size;
	char	*str;
	int32_t	(*append)(struct s_string*, const char*);
	int32_t	(*alloc_string)(struct s_string*, size_t);
	void	(*string_destructor)(struct s_string*);
	void	(*reference_copy_operator)(const struct s_string, struct s_string*);
	int32_t	(*profond_copy_operator)(const struct s_string, struct s_string*);
	int32_t	(*find)(struct s_string*, const char*);
}	t_string;

typedef struct s_player
{
	float 	xPos;
	float 	yPos;
	float	planeX;
	float	planeY;
	float	dirX;
	float	dirY;
	int32_t	lastKey;
}	t_player;

typedef struct s_sprite
{
	void	*sprite;
	int32_t	sprite_lenght;
	int32_t	sprite_width;
}	t_sprite;

typedef struct s_position
{
	int x_pos;
	int y_pos;
} t_position;

typedef	struct s_img
{
	void		*img;
	char		*addr;
	int32_t		bits_per_pixel;
	int32_t		line_length;
	int32_t		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		minimap;
	t_img		walls;
	t_img		background;
	t_sprite	wall_sprite[4];
	u_int8_t	ceiling_color[3];
	u_int8_t	floor_color[3];
}	t_mlx;

typedef struct	s_cube
{
	char		**map;
	int32_t		map_xlen;
	int32_t		map_ylen;
	int			minimap_tile_size;
	t_mlx		mlx;
	t_player	player;
}	t_cube;


#endif
