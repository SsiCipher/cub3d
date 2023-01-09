/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:54:16 by mmanouze          #+#    #+#             */
/*   Updated: 2023/01/09 04:10:53 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	direction_option(t_global *var, double wall_x, double wall_y, double fov)
{
	horizontal_or_vertical(var, wall_x, wall_y, fov);
	specify_direction(var, wall_y, wall_x);
}

void	horizontal_or_vertical(t_global *var, double wall_x, double wall_y, double fov)
{
	var->horizontal = 0;
	var->vertical = 0;
	if (var->scene->map[(int)(wall_y + sin(fov)) / DIMENSION][(int)(wall_x - cos(fov)) / DIMENSION] == '1')
		var->horizontal = 1;
	else
		var->vertical = 1;
}

void	specify_direction(t_global *var, double wall_y, double wall_x)
{
	double	x_pos;
	double	y_pos;

	x_pos = var->scene->player.x * DIMENSION;
	y_pos = var->scene->player.y * DIMENSION;
	if (wall_y >= y_pos && var->horizontal == 1)
		var->direction = 'S';
	if (var->vertical == 1 && wall_x >= x_pos)
		var->direction = 'E';
	if (wall_x <= x_pos && var->vertical == 1)
		var->direction = 'W';
	if (var->horizontal == 1 && wall_y <= y_pos)
		var->direction = 'N';
}
