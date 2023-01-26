#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_player
{
	float 	xPos;
	float 	yPos;
	float	angle;
	float	delta_x;
	float	delta_y;
	int		lastKey;
}	t_player;


typedef struct s_sprite
{
	void	*sprite;
	int		sprite_lenght;
	int		sprite_width;
}	t_sprite;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	void			*minimap;
	void			*walls;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_sprite		wall_sprite[4];
	unsigned char	ceiling_color[3];
	unsigned char	floor_color[3];
}	t_mlx;

typedef struct	s_cube
{
	char		**map;
	int			map_xlen;
	int			map_ylen;
	t_mlx		mlx_data;
	t_player	player;
}	t_cube;

#endif
