#ifndef DISPLAY
#define DISPLAY

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx/mlx.h"

# define WIDTH 1024
# define HEIGHT 768

typedef	struct	s_tile
{
	int	x_pos;
	int y_pos;
	int type; //0 = sol, 1 = mur, 2 = joueur
}	t_tile;

typedef struct s_my_map
{
	t_tile **map;
	int	x_len;
	int	y_len;
}	t_my_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_player
{
	float	x_pos;
	float	y_pos;
}	t_player;

t_mlx_data	init_mlx(void);
void    	my_mlx_pixel_put(t_mlx_data *data, float x, float y, int color);

#endif