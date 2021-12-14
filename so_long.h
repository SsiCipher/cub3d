/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:26:28 by yanab             #+#    #+#             */
/*   Updated: 2021/12/14 17:47:59 by yanab            ###   ########.fr       */
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
	void	*elememt;
	int		width;
	int		height;
}	t_window;

typedef struct s_data
{
	void		*mlx;
	t_window	window;
	int			score;
	t_map		map;
	t_img		wall;
	t_img		space;
	t_img		player;
	t_img		exit;
	t_img		collectible;
}	t_data;

// check_map.c
int	check_map_border(t_map map);
int	check_map_characters(t_map map);
int	check_map_shape(t_map map);

// init_data.c
void	create_map_matrix(char const *map_filename, t_map *map, t_data *data);
void	check_map_matrix(t_map map);
void	init_map(t_map *map, int scale);
void	init_data(const char *map_filename, t_data *data);

// main.c
void	print_err(char *err);


#endif
