/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:42:13 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/02/21 20:08:46 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "include.h"

typedef struct s_string
{
	size_t	lenght;
	size_t	size;
	char	*str;

	int32_t	((*append)(struct s_string *, const char *));
	int32_t	((*alloc_string)(struct s_string *, size_t));
	void	((*string_destructor)(struct s_string *));
	void	((*reference_copy_operator)(const struct s_string, \
			struct s_string *));
	int32_t	((*profond_copy_operator)(const struct s_string, \
			struct s_string *));
	int64_t	((*find)(struct s_string *, const char *));
	int64_t	((*find_file_instructions)(struct s_string, char **, \
			const char **));
}	t_string;

typedef struct s_vector
{
	float	dirx;
	float	diry;
}	t_vector;

typedef struct s_player
{
	float		x_pos;
	float		y_pos;
	float		plane_x;
	float		plane_y;
	t_vector	playerdir;
}	t_player;

typedef struct s_sprite
{
	void	*sprite;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int32_t	height;
	int32_t	width;
}	t_sprite;

typedef struct s_position
{
	int	x_pos;
	int	y_pos;
}	t_position;

typedef struct s_img
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
	int			minimap_ratio;
	void		*mlx_win;
	t_img		minimap;
	t_img		walls;
	t_sprite	wall_sprite[4];
	int32_t		hexa_color[2];
}	t_mlx;

typedef struct s_ray
{
	float		camera_x;
	t_vector	ray_dir;
	int			map_x;
	int			map_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line;
	int			lineheight;
	float		side_distx;
	float		side_disty;
	float		tex_step;
	float		tex_pos;
	float		wall_x;
	float		f_step;
	int			tex_x;
	int			tex_y;
	int			textnum;
	float		ty_off;
	float		ty_step;
	int			drawstart;
	int			drawend;
}	t_ray;

typedef struct s_cube
{
	char		**map;
	t_string	text_file;
	int32_t		map_xlen;
	int32_t		map_ylen;
	int			minimap_tile_size;
	t_mlx		mlx;
	t_player	player;
	t_ray		ray;
	int			keys[7];
}	t_cube;

#endif
