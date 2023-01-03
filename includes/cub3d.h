/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2023/01/03 15:47:05 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <mlx.h>
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
	char	**map_matrix;
}	t_scene;

typedef struct s_line
{
	int		initial_wall;
	char	type;
}	t_line;

// src/init_scene.c
void	init_scene(t_scene *game_scene);
void	free_scene(t_scene **game_scene);
void	read_scene_file(t_scene *game_scene, int scene_file_fd);

// src/utils.c
void	display_error(char *error_msg, int exit_code);
int		rgb_to_int(char *line);
size_t	skip_spaces(char *line, size_t start_index);

// src/error_check.c
bool	valid_extension(const char *file_name);
bool	file_exists(const char *file_name);

// src/debug.c
void	debug_print_scene(t_scene *scene);

#endif
