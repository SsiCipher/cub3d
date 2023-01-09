/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:20 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 04:21:23 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_elements(t_scene scene)
{
	if (scene.north_texture.content == NULL)
		display_error("Error: the north texture is missing\n", 1);
	else if (scene.south_texture.content == NULL)
		display_error("Error: the south texture is missing\n", 1);
	else if (scene.west_texture.content == NULL)
		display_error("Error: the west texture is missing\n", 1);
	else if (scene.east_texture.content == NULL)
		display_error("Error: the east texture is missing\n", 1);
	else if (scene.floor_color < 0)
		display_error("Error: the floor color is missing\n", 1);
	else if (scene.ceilling_color < 0)
		display_error("Error: the ceilling color is missing\n", 1);
}

bool	set_player_dir(t_scene *scene, int i, int j)
{
	if (ft_indexof("NSEW", scene->map[i][j]) != -1
		&& scene->player.direction != UNSET)
		return (false);
	if (scene->map[i][j] == 'N')
		scene->player.direction = NORTH;
	else if (scene->map[i][j] == 'S')
		scene->player.direction = SOUTH;
	else if (scene->map[i][j] == 'E')
		scene->player.direction = EAST;
	else if (scene->map[i][j] == 'W')
		scene->player.direction = WEST;
	if (ft_indexof("NSEW", scene->map[i][j]) != -1)
	{
		scene->player.x = j + 0.5;
		scene->player.y = i + 0.5;
		scene->map[i][j] = '0';
	}
	return (true);
}

bool	is_valid_surrounding(t_scene *scene, size_t i, size_t j)
{
	return (
		scene->map[i + 1][j] != ' ' && scene->map[i + 1][j] != '\0'
		&& scene->map[i - 1][j] != ' ' && scene->map[i - 1][j] != '\0'
		&& scene->map[i][j + 1] != ' ' && scene->map[i][j + 1] != '\0'
		&& scene->map[i][j - 1] != ' ' && scene->map[i][j - 1] != '\0'
	);
}

bool	check_scene_map(t_scene *scene)
{
	size_t	i;
	size_t	j;

	if (!scene->map[0])
		return (!printf("Error: the scene file doesn't contain a map\n"));
	i = -1;
	while (scene->map[++i])
	{
		if ((i == 0 || i == scene->map_height - 1) && !ft_every_is(scene->map[i], " 1"))
			return (!printf("Error: line #%ld isn't a wall\n", i + 1));
		else if (i != 0 && i != scene->map_height - 1)
		{
			j = -1;
			while (scene->map[i][++j])
			{
				if (ft_indexof(" 01NSEW", scene->map[i][j]) == -1)
					return (!printf("Error: line #%ld contains non valid chars\n", i + 1));
				else if (!set_player_dir(scene, i, j))
					return (!printf("Error: line #%ld contains another player\n", i + 1));
				else if (scene->map[i][j] == '0' && !is_valid_surrounding(scene, i, j))
					return (!printf("Error: line #%ld isn't an enclosed by a wall\n", i + 1));
			}
		}
	}
	return (true);
}
