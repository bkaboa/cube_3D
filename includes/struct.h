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
	int64_t	(*find)(struct s_string*, const char*);
	int64_t	(*find_file_instructions)(struct s_string, char**, const char**);
}	t_string;

typedef struct s_vector
{
	float dirX;
	float dirY;
} t_vector;

typedef struct s_player
{
	float 		xPos;
	float 		yPos;
	float		planeX;
	float		planeY;
	t_vector 	playerDir;
	int32_t		lastKey;
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
<<<<<<< HEAD
		void		*mlx;
		void		*mlx_win;
		t_img		minimap;
		t_img		walls;
		t_img		background;
		t_sprite	wall_sprite[4];
		char			hexa_color[2][7];
=======
	void		*mlx;
	void		*mlx_win;
	t_img		minimap;
	t_img		walls;
	t_sprite	wall_sprite[4];
	u_int8_t	ceiling_color[3];
	u_int8_t	floor_color[3];
>>>>>>> display
}	t_mlx;

typedef struct	s_cube
{
	char		**map;
	t_string	text_file;
	int32_t		map_xlen;
	int32_t		map_ylen;
	int			minimap_tile_size;
	t_mlx		mlx;
	t_player	player;
}	t_cube;

typedef struct s_ray
{
	float cameraX;
	t_vector rayDir;
	int mapX;
	int mapY;
	float deltaDistX;
	float deltaDistY;
	float perpWallDist;
	int stepX;
	int stepY;
	int hit;  // was there a wall hit?
	int side; // was a NS or a EW wall hit?
	int line;
	int lineHeight;
	float sideDistX;
	float sideDistY;
} 	t_ray;

#endif
