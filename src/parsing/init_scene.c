/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:15 by yanab             #+#    #+#             */
/*   Updated: 2023/01/08 04:57:34 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scene	*init_scene(void)
{
	t_scene	*game_scene;

	game_scene = malloc(sizeof(t_scene));
	if (!game_scene)
		exit(2);
	game_scene->north_texture.content = NULL;
	game_scene->south_texture.content = NULL;
	game_scene->west_texture.content = NULL;
	game_scene->east_texture.content = NULL;
	game_scene->floor_color = -1;
	game_scene->ceilling_color = -1;
	game_scene->map_width = 0;
	game_scene->map_height = 0;
	game_scene->map = ft_calloc(1, sizeof(char *));
	if (!game_scene->map)
		exit(2);
	game_scene->player.direction = UNSET;
	return (game_scene);
}

void	free_scene(t_scene **game_scene)
{
	ft_free_arr(&((*game_scene)->map));
	free(*game_scene);
	*game_scene = NULL;
}

void	set_texture(t_global *global, char *value, char *direction)
{
	t_img	*texture;
	char	*texture_path;

	texture = get_texture(global, direction);
	if (texture->content)
		display_error(
			ft_multijoin(
				3, "Error: ", direction, " texture is duplicated\n"), 1);
	texture_path = ft_strtrim(value + skip_spaces(value, 2), "\n");
	if (ft_isempty(texture_path))
		display_error(
			ft_multijoin(3, "Error: ", direction, " texture is empty\n"), 1);
	texture->content = mlx_xpm_file_to_image(global->mlx,
			texture_path, &(texture->width), &(texture->height));
	if (!(texture->content))
		display_error(
			ft_multijoin(3, "Error: ", direction, " texture wasn't found\n"), 1);
	free(texture_path);
}

void	set_color(int *color, char *value, char *direction)
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

void	read_scene_map(t_scene *scene, int scene_fd, char *line)
{
	check_elements(*scene);
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

void	read_scene_file(t_global *global, int scene_file_fd)
{
	char	*line;
	size_t	spaces;

	line = ft_getline(scene_file_fd);
	while (line)
	{
		spaces = skip_spaces(line, 0);
		if (is_valid_element("NO", line + spaces))
			set_texture(global, line + spaces, "north");
		else if (is_valid_element("SO", line + spaces))
			set_texture(global, line + spaces, "south");
		else if (is_valid_element("WE", line + spaces))
			set_texture(global, line + spaces, "west");
		else if (is_valid_element("EA", line + spaces))
			set_texture(global, line + spaces, "east");
		else if (is_valid_element("F", line + spaces))
			set_color(&(global->scene->floor_color), line + spaces, "floor");
		else if (is_valid_element("C", line + spaces))
			set_color(&(global->scene->ceilling_color), line + spaces, "ceilling");
		else if (line[spaces] == '1')
			read_scene_map(global->scene, scene_file_fd, line);
		else if (line[0] != '\n' || ft_isempty(line))
			display_error("Error: scene file contains an invalid element\n", 1);
		free(line);
		line = ft_getline(scene_file_fd);
	}
}
