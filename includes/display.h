#ifndef DISPLAY
#define DISPLAY

# include "include.h"
# include "player.h"
# include "hooks.h"

# define WIDTH 1024
# define HEIGHT 768
# define MINIMAPX 10
# define MINIMAPY 10
# define MINIMAPTILESIZE 20
# define C_WHITE 0xFFFFFF
# define C_BLUE  0x0000FF
# define C_RED	 0xFF0000

typedef struct s_my_map
{
	char **map;
	int	x_len;
	int	y_len;
}	t_my_map;

typedef struct s_minimap
{
	int xStart;
	int yStart;
	int tilePixSize;
} t_minimap;

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


t_mlx_data	init_mlx(void);
void    	my_mlx_pixel_put(t_mlx_data *data, float x, float y, int color);
void	drawMinimap(t_mlx_data *data, t_my_map *map, t_player player);

#endif
