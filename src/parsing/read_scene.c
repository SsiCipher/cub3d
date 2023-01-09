/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:15 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 08:22:08 by mmanouze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	set_color(t_global *global, char *value, char *direction)
{
	int		*color;
	char	*color_str;

	color = NULL;
	if (direction[0] == 'f')
		color = &global->scene->floor_color;
	else if (direction[0] == 'c')
		color = &global->scene->ceilling_color;
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

bool	set_scene_elements(t_global *global, char *line)
{
	if (is_valid_element("NO", line))
		set_texture(global, line, "north");
	else if (is_valid_element("SO", line))
		set_texture(global, line, "south");
	else if (is_valid_element("WE", line))
		set_texture(global, line, "west");
	else if (is_valid_element("EA", line))
		set_texture(global, line, "east");
	else if (is_valid_element("F", line))
		set_color(global, line, "floor");
	else if (is_valid_element("C", line))
		set_color(global, line, "ceilling");
	else
		return (false);
	return (true);
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
		if (set_scene_elements(global, line + spaces))
		{
			free(line);
			line = ft_getline(scene_file_fd);
			continue ;
		}
		else if (line[spaces] == '1')
			read_scene_map(global->scene, scene_file_fd, line);
		else if (line[0] != '\n' || ft_isempty(line))
			display_error("Error: scene file contains an invalid element\n", 1);
		free(line);
		line = ft_getline(scene_file_fd);
	}
}
