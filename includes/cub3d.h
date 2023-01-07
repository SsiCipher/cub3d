/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2023/01/07 22:03:11 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "libft.h"

# ifdef __APPLE__
#  include "keycodes_macos.h"
# else
#  include "keycodes_linux.h"
# endif

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_scene
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color;
	int		ceilling_color;
	size_t	map_width;
	size_t	map_height;
	char	**map;
	enum e_dir {
		UNSET,
		NORTH,
		SOUTH,
		EAST,
		WEST
	} player_direction;
}	t_scene;

typedef struct s_line
{
	int		initial_wall;
	char	type;
}	t_line;

// src/init_scene.c
t_scene	*init_scene();
void	free_scene(t_scene **game_scene);
void	add_texture(char **texture, char *value, char *direction);
void	add_color(int *color, char *value, char *direction);
void	read_scene_file(t_scene *scene, int scene_file_fd);

// src/utils.c
void	display_error(char *error_msg, int exit_code);
int		rgb_to_int(char *line);
size_t	skip_spaces(char *line, size_t start_index);
bool	is_valid_element(char *element_name, char *line);

// src/error_check.c
bool	is_valid_extension(const char *file_name);
bool	file_exists(const char *file_name);
void	check_elements(t_scene scene);
bool	check_scene_map(t_scene *scene);

// src/debug.c
void	debug_print_scene(t_scene *scene);

#endif
