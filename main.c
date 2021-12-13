/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:15:40 by yanab             #+#    #+#             */
/*   Updated: 2021/12/13 09:24:40 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if character is '1'
int	is_wall(char chr)
{
	return (chr == '1');
}

// Checks if map is surrounded by walls
int	check_map_border(t_map map)
{
	int		i;
	char	**matrix_row;

	i = 0;
	matrix_row = map.map_matrix;
	while (*matrix_row)
	{
		if (
			(
				(i == 0 || i == map.height - 1)
				&& !ft_every(*matrix_row, is_wall)
			)
			|| (
				(i != 0 && i != map.height - 1)
				&& *matrix_row[0] != '1'
				&& *matrix_row[map.width - 1] != '1'
			)
		)
			return (0);
		matrix_row++;
		i++;
	}
	return (1);
}

// Checks if map has at least an exit, a starting point and a collectible
int	check_map_characters(t_map map)
{
	int	count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (*(map.map_matrix))
	{
		while (*(*(map.map_matrix)) != '\0')
		{
			if (*(*(map.map_matrix)) == 'P')
				count[0]++;
			else if (*(*(map.map_matrix)) == 'C')
				count[1]++;
			else if (*(*(map.map_matrix)) == 'E')
				count[2]++;
			else if (*(*(map.map_matrix)) != '0' && *(*(map.map_matrix)) != '1')
				return (0);
			*(map.map_matrix) += 1;
		}
		(map.map_matrix)++;
	}
	return (count[0] > 0 && count[0] > 0 && count[0] > 0);
}

// Checks if map has rectangular shape
int	check_map_shape(t_map map)
{
	if (map.width == -1 || map.height == -1)
		return (0);
	return (map.width >= map.height);
}

// Print error and exit
void	print_err(char *err)
{
	ft_printf(err);
	exit(0);
}

// Set initial values of the map
void	init_map(char const *map_filename, int *map_fd, t_map *map)
{
	map->width = -1;
	map->height = 0;
	map->scale = 40;
	map->map_matrix = NULL;
	*map_fd = open(map_filename, O_RDONLY);
	if (*map_fd < 0)
		print_err("Error: Map file not found!\n");
}

// Create game matrix
void	create_map_matrix(int map_fd, t_map	*map)
{
	char	*map_line;

	while ((map_line = get_next_line(map_fd)) != NULL)
	{
		map->height += 1;
		map->map_matrix = realloc(
				map->map_matrix, sizeof(char *) * (map->height + 1));
		if (!map->map_matrix)
			print_err("Error: There isn't enough memory to allocate\n");
		map->map_matrix[map->height - 1] = ft_strdup(map_line);
		if (!map->map_matrix[map->height - 1])
			print_err("Error: There isn't enough memory to allocate\n");
		if (map->width == -1)
			map->width = ft_strlen(map_line);
	}
	if (map->map_matrix != NULL)
		map->map_matrix[map->height] = NULL;
}

// Check if the map matrix is valid
void	check_map_matrix(t_map map)
{
	if (
		!check_map_shape(map)
		|| !check_map_border(map)
		|| !check_map_characters(map)
	)
		print_err("Error: The provided map is not a valid map.\n");
}

// Program main function
int	main(int argc, char const *argv[])
{
	int		map_fd;
	t_map	game_map;

	if (argc != 2)
		print_err("Usage: ./solong <map_file>\n");
	init_map(argv[1], &map_fd, &game_map);
	create_map_matrix(map_fd, &game_map);
	check_map_matrix(game_map);
	return (0);
}
