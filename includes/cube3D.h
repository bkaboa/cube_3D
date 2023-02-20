#ifndef CUBE3D_H
# define CUBE3D_H

# include "struct.h"

/*
 *
 *********************************		HOOKS
 *
 */
void rotatePlayer(int keycode, t_player *player);
void movePlayer(int keycode, t_cube *cube);
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
void raycasting_loop(t_cube *cube);
void trace_line_from_ray(t_cube *cube, int x);
int     init_pixel_ray(t_cube *cube, int textnum);
void select_wall_to_put_pixel(t_cube *cube, int x);

    /*
     *
     *********************************		PARSING
     *
     */
    void exit_error(const char *str);
void	exit_error_and_destruct(t_cube map, const int fd, const char *msg);
void	exit_map_error_and_destruct(t_cube map, int y, int x, const char *msg);

void	check_valid_map(t_cube map);
void	set_player(t_cube *map, int player_glance, int y, int x);
void	take_player(t_cube *map);
void	take_map(char *line, t_cube *map);
void	take_all_line(const int fd, t_cube *map);
void	allocate_map(char *line, t_cube *map);

int		ato_rgb(char **str, u_int8_t *value);
void	convert_rgb_to_hexa(u_int8_t rgb_color[3], int *hexa_color);
void	attribute_color(t_cube *map, char **line);
void	attribute_wall_sprite(t_cube *map, char **line);
void	take_sprite_and_color(t_cube *map);
void	place_eol(char **line);

void	file_map_parsing(const int argc, char **argv, t_cube *map);
/*
 *
 *********************************		OFFSETS
 *
 */
float			Offset(t_cube cube, float value);

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
void		ft_bzero(void *var, int64_t var_size);
int			check_char_in_str(char *str, char c);
void		ft_itoa_fd(u_int64_t num, int fd);

/*
 *
 *********************************		STRING
 *
 */
void	string_init(t_string *str);
int32_t	alloc_string(t_string *str1, size_t lenght);
int32_t	append(t_string *str1, const char *str2);
void	reference_copy_operator(const t_string to_copy, t_string *copy);
int32_t	profond_copy_operator(const t_string to_copy, t_string *copy);
int64_t	find(t_string *str, const char *str2);
int64_t	find_file_instructions(t_string str, char **lines, const char **find);
void	string_destructor(t_string *str);


#endif
