/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:34 by yanab             #+#    #+#             */
/*   Updated: 2023/01/05 16:55:01 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_scene_valid(t_scene *scene)
{
	size_t	line_start_gap = 0;
	size_t	line_end_gap = 0;

	for (line_start_gap = 0; scene->map[0][line_start_gap] == ' '; line_start_gap++);
	for (line_end_gap = 0; scene->map[0][ft_strlen(scene->map[0]) - 1 - line_end_gap] == ' '; line_end_gap++);

	for (size_t i = 0; scene->map[i]; i++)
	{
		for (size_t j = 0; j < line_start_gap; j++)
			if (scene->map[i][j] != ' ' && scene->map[i][j] != '1')
				{printf("Error: line number %ld is not left aligned/closed correctly\n", i+1);return (false);}

		for (size_t j = ft_strlen(scene->map[i]) - 1 - line_end_gap; j > ft_strlen(scene->map[i]) - 1; j++)
			if (scene->map[i][j] != ' ' && scene->map[i][j] != '1')
				{printf("Error: line number %ld is not right aligned/closed correctly\n", i+1);return (false);}

		for (size_t j = line_start_gap; j < ft_strlen(scene->map[i]) - line_end_gap; j++)
		{
			if (i == 0 || i == scene->map_height - 1)
			{
				if (
					(
						scene->map[i][j] == ' '
						&& scene->map[i][j - 1] == '1'
						&& scene->map[i][j + 1] == '1'
					)
					&& scene->map[i][j] != '1'
				)
				{printf("Error: line number %ld char %ld is not enclosed by wall\n", i+1, j+1);return (false);}
			}
		}

		for (line_start_gap = 0; scene->map[i][line_start_gap] == ' '; line_start_gap++);
		for (line_end_gap = 0; scene->map[i][ft_strlen(scene->map[i]) - 1 - line_end_gap] == ' '; line_end_gap++);
	}
	return (true);
}

bool	_is_scene_valid(t_scene *scene)
{
	size_t	line_start_gap;
	size_t	line_end_gap;

	for (line_start_gap = 0; scene->map[0][line_start_gap] == ' '; line_start_gap++);
	for (line_end_gap = 0; scene->map[0][line_end_gap] == ' '; line_end_gap++);

	for (size_t i = 0; scene->map[i]; i++)
	{
		if (
			scene->map[i][line_start_gap] != '1'
			|| scene->map[i][ft_strlen(scene->map[i]) - line_end_gap - 1] != '1'
		)
			{printf("Error: line number %ld is not surronded by walls\n", i+1);return (false);}
		else
		{
			if (i == 0 || i == scene->map_height - 1)
			{
				for (size_t j = line_start_gap; j < ft_strlen(scene->map[i]) - line_end_gap; j++)
				{
					if (
						scene->map[i][j] == ' '
						&& (
							scene->map[i][j - 1] != '1'
							|| scene->map[i][j + 1] != '1'
						)
					)
						{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
					else if (scene->map[i][j] != '1')
						{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
				}
			}
			else
			{
				for (size_t j = line_start_gap; j < ft_strlen(scene->map[i]) - line_end_gap; j++)
					if (ft_indexof("01NSEW ", scene->map[i][j]) == -1)
						{printf("Error: line number %ld contains invalid chars\n", i+1);return (false);}
			}

			// if (line_type && !ft_every_char(scene->map[i], line_type))
			// 	{printf("Error: line number %ld is not a wall\n", i+1);return (false);}
			// else
			// {
			// 	for (size_t j = line_start_gap; j < ft_strlen(scene->map[i]) - line_end_gap; j++)
			// 		if (ft_indexof("01NSEW ", scene->map[i][j]) == -1)
			// 			{printf("Error: line number %ld contains invalid chars\n", i+1);return (false);}
			// }
		}
	}
	return (true);
}
