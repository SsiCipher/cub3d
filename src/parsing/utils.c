/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:36:18 by yanab             #+#    #+#             */
/*   Updated: 2023/01/09 04:17:24 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_error(char *error_msg, int exit_code)
{
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
	exit(exit_code);
}

int	rgb_to_int(char *line)
{
	int		color;
	int		rgb_color[3];
	char	**split_line;

	split_line = ft_split(line, ',');
	if (ft_arr_len(split_line) != 3)
		return (-2);
	rgb_color[0] = ft_atoi(split_line[0]);
	rgb_color[1] = ft_atoi(split_line[1]);
	rgb_color[2] = ft_atoi(split_line[2]);
	if (
		!ft_inrange(rgb_color[0], 0, 255)
		|| !ft_inrange(rgb_color[1], 0, 255)
		|| !ft_inrange(rgb_color[2], 0, 255)
	)
		return (-2);
	color = rgb_color[0];
	color = (color << 8) + rgb_color[1];
	color = (color << 8) + rgb_color[2];
	ft_free_arr(&split_line);
	return (color);
}

size_t	skip_spaces(char *line, size_t start_index)
{
	if (start_index < 0)
		return (-1);
	while (line[start_index] == ' ' || line[start_index] == '\t')
		start_index++;
	return (start_index);
}

bool	is_valid_element(char *element_name, char *line)
{
	size_t	element_len;

	element_len = ft_strlen(element_name);
	return (
		!ft_strncmp(line, element_name, element_len)
		&& (
			line[element_len] == ' '
			|| line[element_len] == '\n'
			|| line[element_len] == '\0'
		)
	);
}

t_img	*get_texture(t_global *global, char *direction)
{
	if (direction[0] == 'n')
		return (&(global->scene->north_texture));
	else if (direction[0] == 's')
		return (&(global->scene->south_texture));
	else if (direction[0] == 'w')
		return (&(global->scene->west_texture));
	else if (direction[0] == 'e')
		return (&(global->scene->east_texture));
	return (NULL);
}
