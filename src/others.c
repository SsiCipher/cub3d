/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:34 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 13:47:42 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_scene_map(t_scene *game_scene, int scene_file_fd, char *first_line)
{
	char *line;

	game_scene->map_matrix = (char **)ft_calloc(2, sizeof(char *));
	game_scene->map_matrix[game_scene->map_height++] = ft_strtrim(first_line, "\n");
	line = ft_getline(scene_file_fd);
	while (line)
	{
		game_scene->map_height += 1;
		game_scene->map_matrix = (char **)ft_realloc(
			game_scene->map_matrix,
			sizeof(char *) * game_scene->map_height,
			sizeof(char *) * (game_scene->map_height + 1));
		game_scene->map_matrix[game_scene->map_height - 1] = ft_strtrim(line, "\n");
		free(line);
		line = ft_getline(scene_file_fd);
	}
}

bool	is_scene_valid(t_scene *scene)
{
	size_t	line_start_gap = 0;
	size_t	line_end_gap = 0;

	for (line_start_gap = 0; scene->map_matrix[0][line_start_gap] == ' '; line_start_gap++);
	for (line_end_gap = 0; scene->map_matrix[0][ft_strlen(scene->map_matrix[0]) - 1 - line_end_gap] == ' '; line_end_gap++);

	for (size_t i = 0; scene->map_matrix[i]; i++)
	{
		for (size_t j = 0; j < line_start_gap; j++)
			if (scene->map_matrix[i][j] != ' ' && scene->map_matrix[i][j] != '1')
				{printf("Error: line number %ld is not left aligned/closed correctly\n", i+1);return (false);}

		for (size_t j = ft_strlen(scene->map_matrix[i]) - 1 - line_end_gap; j > ft_strlen(scene->map_matrix[i]) - 1; j++)
			if (scene->map_matrix[i][j] != ' ' && scene->map_matrix[i][j] != '1')
				{printf("Error: line number %ld is not right aligned/closed correctly\n", i+1);return (false);}

		for (size_t j = line_start_gap; j < ft_strlen(scene->map_matrix[i]) - line_end_gap; j++)
		{
			if (i == 0 || i == scene->map_height - 1)
			{
				if (
					(
						scene->map_matrix[i][j] == ' '
						&& scene->map_matrix[i][j - 1] == '1'
						&& scene->map_matrix[i][j + 1] == '1'
					)
					&& scene->map_matrix[i][j] != '1'
				)
				{printf("Error: line number %ld char %ld is not enclosed by wall\n", i+1, j+1);return (false);}
			}
		}

		for (line_start_gap = 0; scene->map_matrix[i][line_start_gap] == ' '; line_start_gap++);
		for (line_end_gap = 0; scene->map_matrix[i][ft_strlen(scene->map_matrix[i]) - 1 - line_end_gap] == ' '; line_end_gap++);
	}
	return (true);
}

bool	_is_scene_valid(t_scene *scene)
{
	size_t	line_start_gap;
	size_t	line_end_gap;

	for (line_start_gap = 0; scene->map_matrix[0][line_start_gap] == ' '; line_start_gap++);
	for (line_end_gap = 0; scene->map_matrix[0][line_end_gap] == ' '; line_end_gap++);

	for (size_t i = 0; scene->map_matrix[i]; i++)
	{
		if (
			scene->map_matrix[i][line_start_gap] != '1'
			|| scene->map_matrix[i][ft_strlen(scene->map_matrix[i]) - line_end_gap - 1] != '1'
		)
			{printf("Error: line number %ld is not surronded by walls\n", i+1);return (false);}
		else
		{
			if (i == 0 || i == scene->map_height - 1)
			{
				for (size_t j = line_start_gap; j < ft_strlen(scene->map_matrix[i]) - line_end_gap; j++)
				{
					if (
						scene->map_matrix[i][j] == ' '
						&& (
							scene->map_matrix[i][j - 1] != '1'
							|| scene->map_matrix[i][j + 1] != '1'
						)
					)
						{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
					else if (scene->map_matrix[i][j] != '1')
						{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
				}
			}
			else
			{
				for (size_t j = line_start_gap; j < ft_strlen(scene->map_matrix[i]) - line_end_gap; j++)
					if (ft_indexof("01NSEW ", scene->map_matrix[i][j]) == -1)
						{printf("Error: line number %ld contains invalid chars\n", i+1);return (false);}
			}

			// if (line_type && !ft_every_char(scene->map_matrix[i], line_type))
			// 	{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
			// else
			// {
			// 	for (size_t j = line_start_gap; j < ft_strlen(scene->map_matrix[i]) - line_end_gap; j++)
			// 		if (ft_indexof("01NSEW ", scene->map_matrix[i][j]) == -1)
			// 			{printf("Error: line number %ld contains invalid chars\n", i+1);return (false);}
			// }
		}
	}
	return (true);
}
