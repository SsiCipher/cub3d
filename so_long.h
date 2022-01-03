/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2021/12/15 23:18:17 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "includes/libft/libft.h"
# include "includes/libftprintf/ft_printf.h"
# include "includes/libgnl/get_next_line.h"

# ifndef FRAMES_DURATION
#  define FRAMES_DURATION 30
# endif

typedef struct s_map
{
	int		width;
	int		height;
	int		scale;
	char	**map_matrix;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
}	t_img;

typedef struct s_window
{
	void	*element;
	int		width;
	int		height;
	int		padding;
}	t_window;

typedef struct s_data
{
	void		*mlx;
	t_window	window;
	int			score;
	int			player_moves;
	int			gameover;
	t_map		map;
	t_img		wall;
	t_img		space;
	t_img		player;
	t_img		exit;
	t_img		collectible;
}	t_data;

// check_map.c
int		check_map_shape(t_map map);
int		is_wall(char chr);
int		check_map_border(t_map map);
int		check_map_characters(t_map map);
void	check_map_matrix(t_map map);

// init_data.c
void	create_map_matrix(char const *map_filename, t_map *map, t_data *data);
void	init_map(t_map *map, int scale);
void	init_assets(t_data *data);
void	init_window(t_data *data);
void	init_data(const char *map_filename, t_data *data);

// game.c
int		close_window(void);
void	render_map(t_data *game_data);
void	move_player(t_data *data, int x, int y);
int		handle_key_event(int keycode, t_data *data);
int		animate_game(t_data *data);

// wrappers.c
void	w_put_img(t_data data, t_img *image, int x, int y);
void	w_put_str(t_data data, char *str, int x, int y);

// main.c
void	print_err(char *error_msg);

#endif
