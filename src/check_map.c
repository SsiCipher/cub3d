/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:14:30 by yanab             #+#    #+#             */
/*   Updated: 2022/02/23 22:53:06 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if map has rectangular shape
int	check_map_shape(t_map map)
{
	if (map.width == -1 || map.height == 0)
		return (0);
	return (map.width >= map.height);
}

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
		if (map.width != ft_strlen(*matrix_row))
			return (0);
		matrix_row++;
		i++;
	}
	return (1);
}

// Checks if map has at least an exit, a starting point and a collectible
int	check_map_chars(t_map map)
{
	int		i;
	int		j;
	int		count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	i = -1;
	while (map.map_matrix[++i])
	{
		j = -1;
		while (map.map_matrix[i][++j])
		{
			if (map.map_matrix[i][j] == 'P')
				count[0]++;
			else if (map.map_matrix[i][j] == 'C')
				count[1]++;
			else if (map.map_matrix[i][j] == 'E')
				count[2]++;
			else if (map.map_matrix[i][j] != '0' && map.map_matrix[i][j] != '1'
				&& map.map_matrix[i][j] != 'D')
				return (0);
		}
	}
	return (count[0] == 1 && count[1] > 0 && count[2] > 0);
}

// Check if the map matrix is valid
void	check_map_matrix(t_map map)
{
	if (
		!check_map_shape(map)
		|| !check_map_border(map)
		|| !check_map_chars(map)
	)
		print_err("Error: The provided map is not a valid map.\n");
}
