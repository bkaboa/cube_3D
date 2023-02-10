#ifndef CUBE3D_H
# define CUBE3D_H

# include "struct.h"

/*
 *
 *********************************		HOOKS
 *
 */
void rotatePlayer(int keycode, t_player *player);
void movePlayer(int keycode, t_player *player);
int control_hooks_loop(int keycode, t_cube *cube);
int	control_hooks_expose(int keycode, t_cube *cube);
int	control_hooks(int keycode, t_cube *cube);
int	click_close(t_cube *cube);
int	win_keyclose(int keycode, t_cube *cube);


/*
 *
 *********************************		DISPLAY
 *
 */
void    my_mlx_pixel_put(t_img *img, float x, float y, int color);
void	drawMinimap(t_cube *cube);
void	drawBackground(t_mlx *mlx);
void	updateMinimap(t_cube *cube);

/*
 *
 *********************************		RAYCASTING
 *
 */
float    protoRayDocument(t_cube *cube);

/*
 *
 *********************************		PARSING
 *
 */
void	exit_error(const char *str);

void	file_map_parsing(const char *file, t_cube map);
void	check_sprite_files(const int fd, t_cube map);
void	check_color(const int fd, t_cube map, t_string line, unsigned int *y);
void	check_map(int fd, t_cube map);
void	exit_error_and_destruct(t_string *str, t_cube map, const int fd, const char *msg);


/*
 *
 *********************************		UTILS
 *
 */
bool		ft_strcomp(const char *first, const char *second);
int			ft_read_file(t_string *line, int fd);
void		init_map(t_cube *map);
void		free_map(t_cube map);
int			ft_strncomp(const char *str1, const char *str2, const int n);
size_t		ft_strlen(const char *str);
void		free_double_pointer(void **pointer);
int			add_line(t_cube map, t_string line);
void 		init_mlx(t_cube *cube);

/*
 *
 *********************************		STRING
 *
 */
void	string_init(t_string *str);


#endif
