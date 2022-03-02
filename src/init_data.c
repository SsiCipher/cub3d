/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:36:29 by yanab             #+#    #+#             */
/*   Updated: 2022/03/02 01:53:49 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Set initial assets
void	init_assets(t_data *data)
{
	data->wall.img = xpm_to_img_i(*data, "wall.xpm", &(data->wall));
	data->space.img = xpm_to_img_i(*data, "space.xpm", &(data->space));
	data->gold.img = xpm_to_img_i(*data, "gold.xpm", &(data->gold));
	data->exit.img = xpm_to_img_i(*data, "exit.xpm", &(data->exit));
	data->enemy.img = xpm_to_img_i(*data, "enemy.xpm", &(data->enemy));
	data->player.x = -1;
	data->player.y = -1;
	data->player.set[P_U] = xpm_to_img_p(*data, "p_up.xpm", &(data->player));
	data->player.set[P_D] = xpm_to_img_p(*data, "p_down.xpm", &(data->player));
	data->player.set[P_L] = xpm_to_img_p(*data, "p_left.xpm", &(data->player));
	data->player.set[P_R] = xpm_to_img_p(*data, "p_right.xpm", &(data->player));
	data->player.img = data->player.set[P_D];
}

// Set initial values of the map
void	init_map(t_map *map, int scale)
{
	map->width = -1;
	map->height = 0;
	map->scale = scale;
	map->map_matrix = NULL;
}

// Create game matrix
/**
 * TODO Check map for empty lines
 */
void	init_matrix(int map_fd, t_map *map, t_data *data)
{
	char	*map_line;

	map_line = get_next_line(map_fd);
	while (map_line != NULL)
	{
		map->height += 1;
		map->map_matrix = ft_realloc(map->map_matrix,
				sizeof(char *) * map->height,
				sizeof(char *) * (map->height + 1));
		if (!map->map_matrix)
			print_err("Error: There isn't enough memory to allocate\n");
		map->map_matrix[map->height - 1] = ft_strtrim(map_line, "\n");
		if (!map->map_matrix[map->height - 1])
			print_err("Error: There isn't enough memory to allocate\n");
		data->score += ft_countchr(map_line, 'C');
		if (map->width == -1)
			map->width = ft_strlen(map->map_matrix[map->height - 1]);
		free(map_line);
		map_line = get_next_line(map_fd);
	}
	printf("line: %s\n", map_line);
	if (map->map_matrix != NULL)
		map->map_matrix[map->height] = NULL;
}

// Create the window
void	init_window(t_data *data)
{
	data->window.padding = 40;
	data->window.width = data->map.width * data->map.scale;
	data->window.height = data->map.height * data->map.scale
		+ data->window.padding;
	data->window.element = mlx_new_window(data->mlx, data->window.width,
			data->window.height, "SoLong");
}

// Init game data
void	init_data(const char *map_filename, t_data *data)
{
	int	map_fd;

	map_fd = open(map_filename, O_RDONLY);
	if (map_fd < 0)
		print_err("Error: Map file not found!\n");
	data->mlx = mlx_init();
	init_assets(data);
	init_map(&(data->map), data->wall.width);
	data->score = 0;
	init_matrix(map_fd, &(data->map), data);
	check_map_matrix(data->map);
	data->gameover = 0;
	data->moves = 0;
	init_window(data);
}
