/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:14:30 by yanab             #+#    #+#             */
/*   Updated: 2021/12/14 15:06:19 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int		i;
	int		j;
	int		count[3];
	char	**matrix_dup;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	i = -1;
	matrix_dup = map.map_matrix;
	while (matrix_dup[++i])
	{
		j = -1;
		while (matrix_dup[i][++j] != '\0')
		{
			if (matrix_dup[i][j] == 'P')
				count[0]++;
			else if (matrix_dup[i][j] == 'C')
				count[1]++;
			else if (matrix_dup[i][j] == 'E')
				count[2]++;
			else if (matrix_dup[i][j] != '0' && matrix_dup[i][j] != '1')
				return (0);
		}
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
