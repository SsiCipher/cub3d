/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 10:33:57 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"

# ifdef __APPLE__
#  include "keycodes_macos.h"
# else
#  include "keycodes_linux.h"
# endif

# define SPEED 0.1
# define SIGHT_SPEED 0.4
# define SCALE 0.2
# define DIMENSION 1000
# define W_WIDTH 1280
# define W_HEIGHT 720
# define W_TITLE "Tasndo9t_3D"

typedef struct s_img
{
	void	*content;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef enum e_dir {
	UNSET,
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dirs;

typedef struct s_player
{
	double	x;
	double	y;
	t_dirs	direction;
}	t_player;

typedef struct s_scene
{
	t_img		north_texture;
	t_img		south_texture;
	t_img		west_texture;
	t_img		east_texture;
	int			floor_color;
	int			ceilling_color;
	size_t		map_width;
	size_t		map_height;
	char		**map;
	char		itto;
	t_player	player;
}	t_scene;

typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	t_img	mlx_img;
	t_scene	*scene;
	double	pa;
	double	xhitwall;
	double	yhitwall;
	int		key_a_d;
	int		key_w_s;
	int		key_r_l;
	int		key_u_d;
	int		horizontal;
	int		vertical;
	char	direction;
	int		index;
	double	p_w_d;
	double	p_w_h;
	int		top_pixel;
	int		bottom_pixel;
	int		pos;
	int		x_text;
	int		y_text;
}	t_global;

// src/parsing/init_data.c
t_scene	*init_scene(void);
void	free_global(t_global *global);
void	init_global(t_global *global, char *scene_file);

// src/parsing/read_scene.c
void	set_texture(t_global *global, char *value, char *direction);
void	set_color(t_global *global, char *value, char *direction);
void	read_scene_file(t_global *global, int scene_file_fd);

// src/parsing/utils.c
void	display_error(char *error_msg, int exit_code);
int		rgb_to_int(char *line);
size_t	skip_spaces(char *line, size_t start_index);
bool	is_valid_element(char *element_name, char *line);
t_img	*get_texture(t_global *global, char *direction);

// src/parsing/error_check.c
void	check_elements(t_scene scene);
bool	set_player_dir(t_scene *scene, int i, int j);
bool	is_valid_surrounding(t_scene *scene, size_t i, size_t j);
bool	is_valid_map_line(t_scene *scene, char *line, int i);
bool	check_scene_map(t_scene *scene);

// src/wrappers.c
void	set_img_addr(t_img *image);
void	set_img_pixel(t_img *mlx_img, int x, int y, int color);

// src/main.c
bool	is_valid_extension(const char *file_name);
bool	file_exists(const char *file_name);
void	check_args(int argc, char *argv[]);

// src/raycasting/rc_utils.c
double	degree_to_radian(int degree);

// src/raycasting/events.c
int		loop_event(t_global *var);
int		reset_keys(int key, t_global *var);
int		init_keys(int key, t_global *var);
int		key_manager(t_global *var);

// src/raycasting/player_casting.c
void	close_wall(t_global *var, double fov, int i);
void	far_wall(t_global *var, double fov, int i);
void	ray_projection(double fov, t_global *var, int i);
double	normalize_angle(double angle);
void	player_view(t_global *var);

// src/raycasting/player_movement.c
void	ft_right(t_global *var);
void	ft_left(t_global *var);
void	ft_down(t_global *var);
void	ft_up(t_global *var);

// src/raycasting/playes_rotation.c
void	ft_turn_right(t_global *var);
void	ft_turn_left(t_global *var);

// src/raycasting/direction.c
void	direction_option(t_global *var,
			double wall_x, double wall_y, double fov);
void	horizontal_or_vertical(t_global *var,
			double wall_x, double wall_y, double fov);
void	specify_direction(t_global *var, double wall_y, double wall_x);

// src/raycasting/draw3D.c
void	draw_3d(t_global *var, int abs, int i, double fov);
void	calcul_indexes(t_global *var, int abs);
void	paint_sky(t_global *var, int i);
void	paint_walls(t_global *var, int i, double fov);

// src/raycasting/textures.c
void	wall_pixels(t_global *var, double fov);
void	x_wall_text(t_global *var, double fov, int line);

// src/raycasting/textures.c
void	north_wall(t_global *var);
void	south_wall(t_global *var);
void	west_wall(t_global *var);
void	east_wall(t_global *var);

int		far_wall_condition(t_global *var, double fov, int speed, double yf);

#endif
