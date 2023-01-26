#ifndef STRUCT_H
# define STRUCT_H

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
	void			*mlx;
	void			*mlx_win;
	t_sprite		wall_sprite[4];
	unsigned char	ceiling_color[3];
	unsigned char	floor_color[3];
}	t_mlx;

typedef struct	s_cube
{
	char		**map;
	t_mlx		mlx_data;
	t_character	character;
}	t_cube;

#endif
