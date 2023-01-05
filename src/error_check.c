/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:20 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 13:36:20 by yanab            ###   ########.fr       */
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
