/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2023/01/08 05:07:46 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# define W_WIDTH 12*140
# define W_HEIGHT 8*140
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
	t_player	player;
}	t_scene;

typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	t_img	mlx_img;
	t_scene	*scene;
	double	pa;
}	t_global;

// src/init_scene.c
t_scene	*init_scene();
void	free_scene(t_scene **game_scene);
void	set_texture(t_global *global, char *value, char *direction);
void	set_color(int *color, char *value, char *direction);
void	read_scene_file(t_global *global, int scene_file_fd);

// src/utils.c
void	display_error(char *error_msg, int exit_code);
int		rgb_to_int(char *line);
size_t	skip_spaces(char *line, size_t start_index);
bool	is_valid_element(char *element_name, char *line);
t_img	*get_texture(t_global *global, char *direction);

// src/error_check.c
bool	is_valid_extension(const char *file_name);
bool	file_exists(const char *file_name);
void	check_elements(t_scene scene);
bool	check_scene_map(t_scene *scene);

// src/wrappers.c
void	set_img_addr(t_img *image);

// src/debug.c
void	debug_print_scene(t_scene *scene);

// src/rc_utils.c
double	degree_to_radian(int degree);

#endif
