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
int control_hooks_loop(int keycode, t_player *player);
int	control_hooks_expose(int keycode, t_player *player);
int	click_close(t_mlx *mlx);


/*
 *
 *********************************		DISPLAY
 *
 */
void    my_mlx_pixel_put(t_img *img, float x, float y, int color);
void	drawMinimap(t_cube *cube);
void	drawBackground(t_mlx *mlx);

/*
 *
 *********************************		PARSING
 *
 */
void	exit_error(const char *str);
void	exit_error_and_destruct(t_cube map, const int fd, const char *msg);
void	exit_map_error_and_destruct(t_cube map, int y, int x, const char *msg);

void	file_map_parsing(const int argc, char **argv, t_cube map);
void	check_sprite_files(const int fd, t_cube map);
void	check_color(const int fd, t_cube map, t_string line, unsigned int *y);
void	check_map(int fd, t_cube map);
void	take_all_line(const int fd, t_cube map);


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
size_t	ft_strlen(const char *str);
void		free_double_pointer(void **pointer);
int			add_line(t_cube map, t_string line);
void 		init_mlx(t_cube *cube);
void		ft_bzero(void *var, int64_t var_size);
int			check_char_in_str(char *str, char c);
void		ft_itoa_fd(u_int64_t num, int fd);

/*
 *
 *********************************		STRING
 *
 */
void	string_init(t_string *str);


#endif
