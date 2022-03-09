/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2022/03/09 02:12:28 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> // TEMPORARY
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libftprintf/ft_printf.h"
# include "libgnl/get_next_line.h"

# ifdef __APPLE__
#  include "keycodes_macos.h"
# else
#  include "keycodes_linux.h"
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
}	t_img;

# define P_U 0
# define P_R 1
# define P_D 2
# define P_L 3

typedef struct s_player
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	void	*set[4];
}	t_player;

typedef struct s_window
{
	int		width;
	int		height;
	int		padding;
	void	*element;
}	t_window;

typedef struct s_data
{
	void		*mlx;
	t_window	window;
	int			score;
	int			moves;
	int			gameover;
	t_map		map;
	t_img		wall;
	t_img		space;
	t_player	player;
	t_img		exit;
	t_img		gold;
}	t_data;

// check_map.c
int		check_map_shape(t_map map);
int		check_map_border(t_map map);
int		check_map_chars(t_map map);
void	check_map_matrix(t_map map);

// init_data.c
void	init_assets(t_data *data);
void	init_map(t_map *map, int scale);
void	init_matrix(int map_fd, t_map *map, t_data *data);
void	init_window(t_data *data);
void	init_data(const char *map_filename, t_data *data);

// game.c
void	put_image(char map_char, t_data *game_data, int x, int y);
void	render_map(t_data *game_data);
void	decide_move(t_data *data, char next_block, int x, int y);
void	move_player(t_data *data, int x, int y);
int		handle_keyevent(int keycode, t_data *data);

// wrappers.c
void	w_put_img(t_data data, t_img *image, int x, int y);
void	w_put_player(t_data data, t_player *player, int x, int y);
void	w_put_str(t_data data, char *str, int x, int y);
void	*xpm_to_img_p(t_data data, char const *filename, t_player *player);
void	*xpm_to_img_i(t_data data, char const *filename, t_img *img);

// so_long.c
void	print_err(char const *error_msg);
int		close_window(void);

#endif
