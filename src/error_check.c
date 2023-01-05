/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:20 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 18:45:29 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_extension(const char *file_name)
{
	return (
		!ft_strncmp(".cub", file_name + (ft_strlen(file_name) - 4), 4)
	);
}

bool	file_exists(const char *file_name)
{
	int		file_fd;
	bool	file_exists;

	file_fd = open(file_name, O_RDONLY);
	file_exists = file_fd != -1;
	if (file_exists)
		close(file_fd);
	return (file_exists);
}

void	check_elements(t_scene scene)
{
	if (!scene.north_texture)
		display_error("Error: the north texture is missing\n", 1);
	else if (!scene.south_texture)
		display_error("Error: the south texture is missing\n", 1);
	else if (!scene.west_texture)
		display_error("Error: the west texture is missing\n", 1);
	else if (!scene.east_texture)
		display_error("Error: the east texture is missing\n", 1);
	else if (scene.floor_color < 0)
		display_error("Error: the floor color is missing\n", 1);
	else if (scene.ceilling_color < 0)
		display_error("Error: the ceilling color is missing\n", 1);
}

bool	set_player_dir(t_scene *scene, char c)
{
	if (ft_indexof("NSEW", c) != -1 && scene->player_direction != UNSET)
		return (false);
	if (c == 'N')
		scene->player_direction = NORTH;
	else if (c == 'S')
		scene->player_direction = SOUTH;
	else if (c == 'E')
		scene->player_direction = EAST;
	else if (c == 'W')
		scene->player_direction = WEST;
	return (true);
}

bool	check_scene_map(t_scene *scene)
{
	size_t start_gap = 0;
	// size_t end_gap = 0;

	// for (start_gap = 0; scene->map[0][start_gap] == ' '; start_gap++);

	for (size_t i = 0; scene->map[i]; i++)
	{
		// inital part of the line has to either be a space or a wall (1)
		for (size_t j = 0; j < start_gap; j++)
		{
			if (scene->map[i][j] != ' ' && scene->map[i][j] != '1')
				return (!printf("Error: line #%ld is not left aligned/closed correctly\n", i+1));
		}

		// first char of the line has to be a wall (1)
		if (i != 0 && scene->map[i][start_gap] != '1')
			return (!printf("Error: line #%ld is not enclosed by a wall\n", i+1));

		// line chars have to be valid and the player has to be one
		for (size_t j = start_gap; scene->map[i][j]; j++)
		{
			if (ft_indexof(" 01NSEW", scene->map[i][j]) == -1)
				return (!printf("Error: line #%ld contains non valid chars\n", i+1));
			else if (!set_player_dir(scene, scene->map[i][j]))
				return (!printf("Error: line #%ld contains another player\n", i+1));
		}

		// reset start spaces count
		for (start_gap = 0; scene->map[i][start_gap] == ' '; start_gap++);
	}

	return (true);
}
