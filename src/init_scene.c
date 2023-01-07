/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cipher <cipher@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:15 by yanab             #+#    #+#             */
/*   Updated: 2023/01/07 23:11:57 by cipher           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	*init_scene(void)
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene));
	if (!game_scene)
		exit(2);
	game_scene->north_texture = NULL;
	game_scene->south_texture = NULL;
	game_scene->west_texture = NULL;
	game_scene->east_texture = NULL;
	game_scene->floor_color = -1;
	game_scene->ceilling_color = -1;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map = ft_calloc(1, sizeof(char *));
	if (!game_scene->map)
		exit(2);
	game_scene->player_direction = UNSET;
	return (game_scene);
}

void	free_scene(t_scene **game_scene)
{
	free((*game_scene)->north_texture);
	free((*game_scene)->south_texture);
	free((*game_scene)->west_texture);
	free((*game_scene)->east_texture);
	ft_free_arr(&((*game_scene)->map));
	free(*game_scene);
	*game_scene = NULL;
}

void	add_texture(char **texture, char *value, char *direction)
{
	if (*texture)
		display_error(
			ft_multijoin(
				3, "Error: ", direction, " texture is duplicated\n"), 1);
	*texture = ft_strtrim(value + skip_spaces(value, 2), "\n");
	if (ft_isempty(*texture))
		display_error(
			ft_multijoin(3, "Error: ", direction, " texture is empty\n"), 1);
}

void	add_color(int *color, char *value, char *direction)
{
	char	*color_str;

	color_str = ft_strtrim(value + skip_spaces(value, 1), "\n");
	if (*color >= 0)
		display_error(
			ft_multijoin(3, "Error: ", direction, " color is duplicated\n"), 1);
	if (ft_isempty(color_str))
		display_error(
			ft_multijoin(3, "Error: ", direction, " color is empty\n"), 1);
	*color = rgb_to_int(color_str);
	if (*color == -2)
		display_error(
			ft_multijoin(3, "Error: ", direction, " color is invalid\n"), 1);
	free(color_str);
}

/*
! CASES
	* element cases:
		[x] non existant
		[x] empty
		[x] invalid value (color -> out-of-range)
		[ ] invalid value (texture -> file-not-found)
		[x] duplicated
		[x] invalid line with wrong identifier
	* map cases:
		[x] non existant
		[x] it has one player
		[x] no empty lines
		[x] doesn't contain invalid chars
		[x] not surronded by walls
		[x] has empty lines in between
		[ ] corners are well enclosed
*/

void	read_scene_map(t_scene *scene, int scene_fd, char *line)
{
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
			display_error("Error: your map can't contain empty lines\n", 1);
		scene->map_height += 1;
		scene->map = (char **)ft_realloc(scene->map,
				sizeof(char *) * scene->map_height,
				sizeof(char *) * (scene->map_height + 1));
		scene->map[scene->map_height - 1] = ft_strtrim(line, "\n");
		if (scene->map_height != 1)
			free(line);
		line = ft_getline(scene_fd);
	}
	if (scene->map_height > 0)
		scene->map[scene->map_height] = NULL;
}

void	read_scene_file(t_scene *scene, int scene_file_fd)
{
	char	*line;
	size_t	spaces;

	line = ft_getline(scene_file_fd);
	while (line)
	{
		spaces = skip_spaces(line, 0);
		if (line[spaces] == '1')
		{
			check_elements(*scene);
			read_scene_map(scene, scene_file_fd, line);
		}
		else if (is_valid_element("NO", line + spaces))
			add_texture(&(scene->north_texture), line + spaces, "north");
		else if (is_valid_element("SO", line + spaces))
			add_texture(&(scene->south_texture), line + spaces, "south");
		else if (is_valid_element("WE", line + spaces))
			add_texture(&(scene->west_texture), line + spaces, "west");
		else if (is_valid_element("EA", line + spaces))
			add_texture(&(scene->east_texture), line + spaces, "east");
		else if (is_valid_element("F", line + spaces))
			add_color(&(scene->floor_color), line + spaces, "floor");
		else if (is_valid_element("C", line + spaces))
			add_color(&(scene->ceilling_color), line + spaces, "ceilling");
		else if (line[0] != '\n' || ft_isempty(line))
			display_error("Error: scene file contains an invalid element\n", 1);
		free(line);
		line = ft_getline(scene_file_fd);
	}
}
